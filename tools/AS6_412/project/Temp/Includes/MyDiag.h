/* Automation Studio generated header file */
/* Do not edit ! */
/* MyDiag 1.01.0 */

#ifndef _MYDIAG_
#define _MYDIAG_
#ifdef __cplusplus
extern "C" 
{
#endif
#ifndef _MyDiag_VERSION
#define _MyDiag_VERSION 1.01.0
#endif

#include <bur/plctypes.h>

#ifndef _BUR_PUBLIC
#define _BUR_PUBLIC
#endif
#ifdef _SG3
		#include "astime.h"
		#include "FileIO.h"
		#include "standard.h"
		#include "AsBrStr.h"
		#include "sys_lib.h"
		#include "brsystem.h"
		#include "ArEventLog.h"
		#include "AsArSdm.h"
		#include "AsArProf.h"
#endif
#ifdef _SG4
		#include "astime.h"
		#include "FileIO.h"
		#include "standard.h"
		#include "AsBrStr.h"
		#include "sys_lib.h"
		#include "brsystem.h"
		#include "ArEventLog.h"
		#include "AsArSdm.h"
		#include "AsArProf.h"
#endif
#ifdef _SGC
		#include "astime.h"
		#include "FileIO.h"
		#include "standard.h"
		#include "AsBrStr.h"
		#include "sys_lib.h"
		#include "brsystem.h"
		#include "ArEventLog.h"
		#include "AsArSdm.h"
		#include "AsArProf.h"
#endif


/* Constants */
#ifdef _REPLACE_CONST
 #define MD_ERR_WRONG_PARAM (-536870911)
 #define MD_ERR_INTERNAL (-536870912)
 #define MD_EVENT_INFO_COMMON 1610612736
 #define MD_EVENT_SUCC_COMMON 536870912
 #define MC_EVENT_WARN_COMMON (-1610612736)
 #define MD_EVENT_ERR_COMMON (-536870912)
#else
 _GLOBAL_CONST signed long MD_ERR_WRONG_PARAM;
 _GLOBAL_CONST signed long MD_ERR_INTERNAL;
 _GLOBAL_CONST signed long MD_EVENT_INFO_COMMON;
 _GLOBAL_CONST signed long MD_EVENT_SUCC_COMMON;
 _GLOBAL_CONST signed long MC_EVENT_WARN_COMMON;
 _GLOBAL_CONST signed long MD_EVENT_ERR_COMMON;
#endif




/* Datatypes and datatypes of function blocks */
typedef enum MD_Profiler_Step
{	MD_PROF_GET_STATE = 0,
	MD_PROF_STOPPING,
	MD_PROF_DEINSTALLING,
	MD_PROF_CHECK_DEINSTALLED,
	MD_PROF_INSTALLING,
	MD_PROF_STARTING,
	MD_PROF_CHECK_RUNNING,
	MD_PROF_RUNNING,
	MD_PROF_ARCH_STOP,
	MD_PROF_ARCH_CREATE,
	MD_PROF_ERROR
} MD_Profiler_Step;

typedef struct MD_LimitFileNumber
{
	/* VAR_INPUT (analog) */
	plcstring FileDeviceName[33];
	plcstring DirectoryName[33];
	plcstring FileNamePattern[129];
	unsigned short MaxCount;
	/* VAR_OUTPUT (analog) */
	signed long ErrorID;
	plcstring ErrorFileNamePattern[81];
	/* VAR (analog) */
	unsigned short step;
	struct DirOpen fbDirOpen;
	struct DirReadEx fbDirRead;
	struct DirClose fbDirClose;
	struct FileDelete fbFileDelete;
	struct fiDIR_READ_EX_DATA dirEntry;
	unsigned short fileCount;
	plcdt timeStamps[101];
	unsigned char pass;
	/* VAR_INPUT (digital) */
	plcbit Execute;
	/* VAR_OUTPUT (digital) */
	plcbit Done;
	plcbit Busy;
	plcbit Error;
} MD_LimitFileNumber_typ;

typedef struct MD_Dump
{
	/* VAR_INPUT (analog) */
	plcstring FileDeviceName[33];
	plcstring FileNamePrefix[33];
	unsigned short MaxFileCount;
	/* VAR_OUTPUT (analog) */
	signed long ErrorID;
	plcstring DumpFileName[256];
	/* VAR (analog) */
	unsigned short step;
	struct SdmSystemDump fbSystemDump;
	struct MD_LimitFileNumber fbLimitFileNumber;
	/* VAR_INPUT (digital) */
	plcbit Execute;
	/* VAR_OUTPUT (digital) */
	plcbit Done;
	plcbit Busy;
	plcbit Error;
} MD_Dump_typ;

typedef struct MD_LogWrite
{
	/* VAR_INPUT (analog) */
	plcstring Name[11];
	signed long EventID;
	plcstring ObjectID[37];
	plcstring Ascii[121];
	/* VAR_OUTPUT (analog) */
	signed long ErrorID;
	/* VAR (analog) */
	struct ArEventLogCreate fbLogCreate;
	struct ArEventLogGetIdent fbLogGetIdent;
	struct ArEventLogWrite fbLogWrite;
	unsigned short step;
	/* VAR_INPUT (digital) */
	plcbit Execute;
	/* VAR_OUTPUT (digital) */
	plcbit Done;
	plcbit Busy;
	plcbit Error;
} MD_LogWrite_typ;

typedef struct MD_LogWatchBOOL
{
	/* VAR_INPUT (analog) */
	plcstring LogName[11];
	plcstring SignalName[37];
	signed long EventID;
	/* VAR_OUTPUT (analog) */
	signed long ErrorID;
	/* VAR (analog) */
	unsigned short step;
	struct MD_LogWrite fbLogWrite;
	/* VAR_INPUT (digital) */
	plcbit Enable;
	plcbit Signal;
	/* VAR_OUTPUT (digital) */
	plcbit Valid;
	plcbit Busy;
	plcbit Error;
	/* VAR (digital) */
	plcbit signalOld;
} MD_LogWatchBOOL_typ;

typedef struct MD_LogWatch8Flags
{
	/* VAR_INPUT (analog) */
	unsigned char Signal;
	plcstring LogName[11];
	plcstring SignalName[37];
	signed long EventID;
	plcstring Flag[8][9];
	/* VAR_OUTPUT (analog) */
	signed long ErrorID;
	/* VAR (analog) */
	unsigned char signalOld;
	unsigned short step;
	struct MD_LogWrite fbLogWrite;
	/* VAR_INPUT (digital) */
	plcbit Enable;
	/* VAR_OUTPUT (digital) */
	plcbit Valid;
	plcbit Busy;
	plcbit Error;
} MD_LogWatch8Flags_typ;

typedef struct MD_LogWatchDINT
{
	/* VAR_INPUT (analog) */
	signed long Signal;
	plcstring LogName[11];
	plcstring SignalName[37];
	signed long EventID;
	/* VAR_OUTPUT (analog) */
	signed long ErrorID;
	/* VAR (analog) */
	signed long signalOld;
	unsigned short step;
	struct MD_LogWrite fbLogWrite;
	/* VAR_INPUT (digital) */
	plcbit Enable;
	/* VAR_OUTPUT (digital) */
	plcbit Valid;
	plcbit Busy;
	plcbit Error;
} MD_LogWatchDINT_typ;

typedef struct MD_LogWatchSTRING
{
	/* VAR_INPUT (analog) */
	plcstring Signal[121];
	plcstring LogName[11];
	plcstring SignalName[37];
	signed long EventID;
	/* VAR_OUTPUT (analog) */
	signed long ErrorID;
	/* VAR (analog) */
	plcstring signalOld[121];
	unsigned short step;
	struct MD_LogWrite fbLogWrite;
	/* VAR_INPUT (digital) */
	plcbit Enable;
	/* VAR_OUTPUT (digital) */
	plcbit Valid;
	plcbit Busy;
	plcbit Error;
} MD_LogWatchSTRING_typ;

typedef struct MD_Profiler
{
	/* VAR_OUTPUT (analog) */
	signed long ErrorID;
	enum MD_Profiler_Step step;
	/* VAR_IN_OUT (analog and digital) */
	struct PROFILER_DEFINITION* PrfDef;
	/* VAR (analog) */
	struct LogStateGet fbLogStateGet;
	struct LogInstall fbLogInstall;
	struct LogDeInstall fbLogDeInstall;
	struct LogStart fbLogStart;
	struct LogStop fbLogStop;
	struct LogArchCreate fbLogArchCreate;
	struct LogArchDelete fbLogArchDelete;
	struct LogIdleShow fbLogIdleShow;
	struct DTGetTime fbGetTime;
	plcstring archive_name[13];
	enum MD_Profiler_Step error_step;
	/* VAR_INPUT (digital) */
	plcbit Enable;
	plcbit CreateArchive;
	/* VAR_OUTPUT (digital) */
	plcbit Done;
	plcbit Busy;
	plcbit Error;
} MD_Profiler_typ;



/* Prototyping of functions and function blocks */
_BUR_PUBLIC void MD_Dump(struct MD_Dump* inst);
_BUR_PUBLIC void MD_LogWatchBOOL(struct MD_LogWatchBOOL* inst);
_BUR_PUBLIC void MD_LogWatch8Flags(struct MD_LogWatch8Flags* inst);
_BUR_PUBLIC void MD_LogWatchDINT(struct MD_LogWatchDINT* inst);
_BUR_PUBLIC void MD_LogWatchSTRING(struct MD_LogWatchSTRING* inst);
_BUR_PUBLIC void MD_LogWrite(struct MD_LogWrite* inst);
_BUR_PUBLIC void MD_LimitFileNumber(struct MD_LimitFileNumber* inst);
_BUR_PUBLIC void MD_Profiler(struct MD_Profiler* inst);
_BUR_PUBLIC plcbit MD_ascDT(plcdt DT1, unsigned long pString, unsigned char maxSize);
_BUR_PUBLIC unsigned short MD_filenameDT(unsigned long prefix, unsigned long pString, unsigned long maxSize);


#ifdef __cplusplus
};
#endif
#endif /* _MYDIAG_ */

