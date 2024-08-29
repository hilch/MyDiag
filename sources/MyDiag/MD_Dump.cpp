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

#include <bur/plctypes.h>
#include <cstring>
#include <cstdio>
#include <algorithm>

#define STARTUP 0
#define W_SYSTEMDUMP 10
#define DELETE_OLD_DUMPS 20
#define DONE 100
#define ERROR_SYSTEMDUMP 9001
#define ERROR_LIMIT_FILE_NUMBER 9002


/* Write into Logger */
void MD_Dump(struct MD_Dump* inst)
{
	if( inst->Execute ){
		switch( inst->step ){
			case STARTUP: /* start */
			inst->Busy = true;
			inst->Done = false;
			inst->Error = false;
			inst->ErrorID = 0;

			/* create a dump file name */
			std::strcpy( inst->DumpFileName, inst->FileNamePrefix );
			MD_filenameDT( (UDINT) "_", (UDINT) ((char*) &inst->DumpFileName + std::strlen(inst->FileNamePrefix)), sizeof(inst->DumpFileName)-1 );
			std::strcat( (char*) &inst->DumpFileName, (char*) ".tar.gz" );

			/* init SdmSystemDump */
			inst->fbSystemDump.enable = false; 
			inst->fbSystemDump.configuration = sdm_SYSTEMDUMP_DATA;
			inst->fbSystemDump.pDevice = reinterpret_cast<UDINT>(  &inst->FileDeviceName );
			inst->fbSystemDump.pFile = reinterpret_cast<UDINT>(  &inst->DumpFileName );
			inst->fbSystemDump.pParam = 0;
			SdmSystemDump( &inst->fbSystemDump ); /* reset fb */

			/* create system dump file */
			inst->fbSystemDump.enable = true;
			SdmSystemDump( &inst->fbSystemDump );

			/* init MD_LimitFileNumber */
			std::strncpy( inst->fbLimitFileNumber.FileDeviceName, inst->FileDeviceName, sizeof(inst->fbLimitFileNumber.FileDeviceName) );
			std::strcpy( inst->fbLimitFileNumber.DirectoryName, "" );
			std::strncpy( inst->fbLimitFileNumber.FileNamePattern, inst->FileNamePrefix, sizeof(inst->fbLimitFileNumber.FileNamePattern));
			std::strncat( inst->fbLimitFileNumber.FileNamePattern, R"(_\d{4}-\d{2}-\d{2}T\d{2}_\d{2}_\d{2}.tar.gz)", 
				sizeof(inst->fbLimitFileNumber.FileNamePattern));
			inst->fbLimitFileNumber.MaxCount = inst->MaxFileCount;
			inst->fbLimitFileNumber.Execute = false; /* reset fb */
			MD_LimitFileNumber( &inst->fbLimitFileNumber );

			inst->step = W_SYSTEMDUMP;
			break;


			case W_SYSTEMDUMP:
			if( inst->fbSystemDump.status == ERR_OK ){ /* successful */
				inst->fbSystemDump.enable = false; /* reset fb */
				SdmSystemDump( &inst->fbSystemDump );
				inst->fbLimitFileNumber.Execute = true; 
				MD_LimitFileNumber( &inst->fbLimitFileNumber );
				inst->step = DELETE_OLD_DUMPS;
			}
			else if( inst->fbSystemDump.status != ERR_FUB_BUSY ){  /* busy */
				inst->fbSystemDump.enable = false; /* reset fb */
				SdmSystemDump( &inst->fbSystemDump );
				inst->step = ERROR_SYSTEMDUMP;
			}
			else {  /* busy */
				SdmSystemDump( &inst->fbSystemDump );
			}
			break;


			case DELETE_OLD_DUMPS:
			if( inst->fbLimitFileNumber.Done ){ /* done */
				inst->fbLimitFileNumber.Execute = false; /* reset fb */
				MD_LimitFileNumber( &inst->fbLimitFileNumber );
				inst->Busy = false;
				inst->Done = true;
				inst->step = DONE;
			}
			else if( inst->fbLimitFileNumber.Error ){ /* error */
				inst->ErrorID = inst->fbLimitFileNumber.ErrorID;
				inst->Error = true;
				inst->fbLimitFileNumber.Execute = false; /* reset fb */
				MD_LimitFileNumber( &inst->fbLimitFileNumber );
				inst->step = ERROR_LIMIT_FILE_NUMBER;
			}
			else {  /* busy */
				MD_LimitFileNumber( &inst->fbLimitFileNumber );
			}
			break;



			case DONE: /* done */

			break;


			case ERROR_SYSTEMDUMP: /* error */
			case ERROR_LIMIT_FILE_NUMBER: 
			break;

		}
	}
	else {
		inst->step = STARTUP;
		inst->Error = false;
		inst->Busy = false;
		inst->Done = false;
	}
}
