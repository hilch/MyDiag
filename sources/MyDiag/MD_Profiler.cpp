/*

https://github.com/hilch/MyDiag

Helper Library for ACOPOStrak diagnosis

MIT License

Copyright (c) 2022 https://github.com/hilch

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

#include <bur/plctypes.h>
#ifdef __cplusplus
extern "C"
{
#endif
#include "MyDiag.h"
#ifdef __cplusplus
};
#endif

#include <ctime>
#include <cstring>

static void HandleFbStatus(struct MD_Profiler *inst, unsigned short status)
{
    if (status == 0U)
    {
        inst->error_step = MD_PROF_GET_STATE;
    }
    else if (status != ERR_FUB_BUSY)
    {
        inst->error_step = inst->step;
        inst->ErrorID = status;
        inst->step = MD_PROF_ERROR;
    }
}

/* Configures AR Profiler */
void MD_Profiler(struct MD_Profiler *inst)
{
    if (inst->Enable)
    {
        switch (inst->step)
        {
        case MD_PROF_GET_STATE:
            inst->fbLogStateGet.enable = 1;
            LogStateGet(&inst->fbLogStateGet);
            inst->Busy = true;

            if (inst->fbLogStateGet.status == 0U)
            {
                inst->error_step = MD_PROF_GET_STATE;
                if ((inst->fbLogStateGet.logstate == profSTATE_RUNNING) ||
                    (inst->fbLogStateGet.logstate == profSTATE_READY))
                {
                    inst->step = MD_PROF_DEINSTALLING;
                }
            }
            else
            {
                HandleFbStatus(inst, inst->fbLogStateGet.status);
            }
            break;

        case MD_PROF_STOPPING:
            inst->fbLogStop.enable = 1;
            LogStop(&inst->fbLogStop);

            if (inst->fbLogStop.status == 0U)
            {
                inst->step = MD_PROF_GET_STATE;
            }
            else
            {
                HandleFbStatus(inst, inst->fbLogStop.status);
            }
            break;

        case MD_PROF_DEINSTALLING:
            inst->fbLogDeInstall.enable = 1;
            inst->fbLogDeInstall.option = 0U;
            LogDeInstall(&inst->fbLogDeInstall);

            if (inst->fbLogDeInstall.status == 0U)
            {
                inst->step = MD_PROF_CHECK_DEINSTALLED;
            }
            else
            {
                HandleFbStatus(inst, inst->fbLogDeInstall.status);
            }
            break;

        case MD_PROF_CHECK_DEINSTALLED:
            inst->fbLogStateGet.enable = 1;
            LogStateGet(&inst->fbLogStateGet);

            if (inst->fbLogStateGet.status == 0U)
            {
                if (inst->fbLogStateGet.logstate == profSTATE_ACTIVE)
                {
                    inst->step = MD_PROF_INSTALLING;
                }
            }
            else
            {
                HandleFbStatus(inst, inst->fbLogStateGet.status);
            }
            break;

        case MD_PROF_INSTALLING:
            inst->fbLogInstall.enable = 1;
            inst->fbLogInstall.pVersion = 0U;
            inst->fbLogInstall.pDefinition = reinterpret_cast<UDINT>(inst->PrfDef);
            LogInstall(&inst->fbLogInstall);

            if (inst->fbLogInstall.status == 0U)
            {
                inst->step = MD_PROF_STARTING;
            }
            else
            {
                HandleFbStatus(inst, inst->fbLogInstall.status);
            }
            break;

        case MD_PROF_STARTING:
            inst->fbLogStart.enable = 1;
            LogStart(&inst->fbLogStart);

            if (inst->fbLogStart.status == 0U)
            {
                inst->step = MD_PROF_CHECK_RUNNING;
            }
            else
            {
                HandleFbStatus(inst, inst->fbLogStart.status);
            }
            break;

        case MD_PROF_CHECK_RUNNING:
            inst->fbLogStateGet.enable = 1;
            LogStateGet(&inst->fbLogStateGet);

            if (inst->fbLogStateGet.status == 0U)
            {
                if (inst->fbLogStateGet.logstate == profSTATE_RUNNING)
                {
                    inst->step = MD_PROF_RUNNING;
                }
            }
            else
            {
                HandleFbStatus(inst, inst->fbLogStateGet.status);
            }
            break;

        case MD_PROF_RUNNING:
            inst->Busy = false;
            if (inst->CreateArchive)
            {
                inst->Done = false;
                inst->Busy = true;
                inst->CreateArchive = false;
                inst->fbGetTime.enable = 1;
                DTGetTime(&inst->fbGetTime);
                brsitoa((DINT)inst->fbGetTime.DT1, (UDINT) &inst->archive_name);
                inst->step = MD_PROF_ARCH_STOP;
            }
            break;

        case MD_PROF_ARCH_STOP:
            inst->fbLogStop.enable = 1;
            LogStop(&inst->fbLogStop);

            if (inst->fbLogStop.status == 0U)
            {
                inst->step = MD_PROF_ARCH_CREATE;
            }
            else
            {
                HandleFbStatus(inst, inst->fbLogStop.status);
            }
            break;

        case MD_PROF_ARCH_CREATE:
            inst->fbLogArchCreate.enable = 1;
            inst->fbLogArchCreate.pDevice = 0U;
            inst->fbLogArchCreate.pName = (UDINT) &inst->archive_name;
            inst->fbLogArchCreate.option = 0U;
            LogArchCreate(&inst->fbLogArchCreate);

            if (inst->fbLogArchCreate.status == 0U)
            {
            	inst->Done = true;
                inst->step = MD_PROF_STARTING;
            }
            else
            {
                HandleFbStatus(inst, inst->fbLogArchCreate.status);
            }
            break;

        case MD_PROF_ERROR:
            inst->Done = false;
            inst->Error = true;
            inst->Busy = false;
            break;



        }
    }
    else
    {
        inst->step = MD_PROF_GET_STATE;
        inst->Done = false;
        inst->Error = false;
        inst->Busy = false;
        inst->ErrorID = 0;
    }
}
