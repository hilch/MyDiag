#ifndef __AS__TYPE_InterfaceFromType
#define __AS__TYPE_InterfaceFromType
typedef struct InterfaceFromType
{	plcbit PowerOn;
	plcbit StartAutomatic;
} InterfaceFromType;
#endif

#ifndef __AS__TYPE_InterfaceToType
#define __AS__TYPE_InterfaceToType
typedef struct InterfaceToType
{	plcbit PowerIsOn;
	plcbit AutomaticIsActive;
	plcbit CoverOpenPermission;
	plcbit Error;
} InterfaceToType;
#endif

#ifndef __AS__TYPE_InterfaceType
#define __AS__TYPE_InterfaceType
typedef struct InterfaceType
{	InterfaceFromType from;
	InterfaceToType to;
} InterfaceType;
#endif

#ifndef __AS__TYPE_ArFBStateInternalType
#define __AS__TYPE_ArFBStateInternalType
typedef struct ArFBStateInternalType
{	unsigned long ExecuteRef;
	unsigned long BusyRef;
	unsigned long DoneRef;
	unsigned long ErrorRef;
	unsigned long ActiveRef;
	unsigned long StatusRef;
	unsigned long FBCyclic;
	unsigned long AsyfumaState;
	unsigned long FBResetOut;
	unsigned long Argument;
	unsigned long State;
	plcbit ExecutePrev;
} ArFBStateInternalType;
#endif

#ifndef __AS__TYPE_ArFBAsyFuMaInternalType
#define __AS__TYPE_ArFBAsyFuMaInternalType
typedef struct ArFBAsyFuMaInternalType
{	unsigned short State;
	signed long Result;
} ArFBAsyFuMaInternalType;
#endif

#ifndef __AS__TYPE_fiDIR_READ_EX_DATA
#define __AS__TYPE_fiDIR_READ_EX_DATA
typedef struct fiDIR_READ_EX_DATA
{	unsigned char Filename[260];
	plcdt Date;
	unsigned long Filelength;
	unsigned short Mode;
} fiDIR_READ_EX_DATA;
#endif

#ifndef __AS__TYPE_ArEventLogIdentType
#define __AS__TYPE_ArEventLogIdentType
typedef unsigned long ArEventLogIdentType;
#endif

#ifndef __AS__TYPE_ArEventLogRecordIDType
#define __AS__TYPE_ArEventLogRecordIDType
typedef unsigned long ArEventLogRecordIDType;
#endif

#ifndef __AS__TYPE_ArEventLogAsyncInternalType
#define __AS__TYPE_ArEventLogAsyncInternalType
typedef struct ArEventLogAsyncInternalType
{	ArFBStateInternalType FBStateCtx;
	ArFBAsyFuMaInternalType AsyFuMaCtx;
} ArEventLogAsyncInternalType;
#endif

#ifndef __AS__TYPE_ArEventLogInternalType
#define __AS__TYPE_ArEventLogInternalType
typedef struct ArEventLogInternalType
{	ArFBStateInternalType FBStateCtx;
} ArEventLogInternalType;
#endif

struct FileDelete
{	unsigned long pDevice;
	unsigned long pName;
	unsigned short status;
	unsigned short i_state;
	unsigned short i_result;
	unsigned long i_tmp;
	plcbit enable;
};
_BUR_PUBLIC void FileDelete(struct FileDelete* inst);
struct DirOpen
{	unsigned long pDevice;
	unsigned long pName;
	unsigned short status;
	unsigned long ident;
	unsigned short i_state;
	unsigned short i_result;
	unsigned long i_tmp;
	plcbit enable;
};
_BUR_PUBLIC void DirOpen(struct DirOpen* inst);
struct DirClose
{	unsigned long ident;
	unsigned short status;
	unsigned short i_state;
	unsigned short i_result;
	unsigned long i_tmp;
	plcbit enable;
};
_BUR_PUBLIC void DirClose(struct DirClose* inst);
struct DirReadEx
{	unsigned long ident;
	unsigned long pData;
	unsigned long data_len;
	unsigned short status;
	unsigned short i_state;
	unsigned short i_result;
	unsigned long i_tmp;
	plcbit enable;
};
_BUR_PUBLIC void DirReadEx(struct DirReadEx* inst);
struct ArEventLogCreate
{	plcstring Name[257];
	unsigned long Size;
	unsigned char Persistence;
	unsigned long Info;
	signed long StatusID;
	ArEventLogIdentType Ident;
	ArEventLogAsyncInternalType Internal;
	plcbit Execute;
	plcbit Done;
	plcbit Busy;
	plcbit Error;
};
_BUR_PUBLIC void ArEventLogCreate(struct ArEventLogCreate* inst);
struct ArEventLogGetIdent
{	plcstring Name[257];
	signed long StatusID;
	ArEventLogIdentType Ident;
	ArEventLogInternalType Internal;
	plcbit Execute;
	plcbit Done;
	plcbit Error;
};
_BUR_PUBLIC void ArEventLogGetIdent(struct ArEventLogGetIdent* inst);
struct ArEventLogWrite
{	ArEventLogIdentType Ident;
	signed long EventID;
	ArEventLogRecordIDType OriginRecordID;
	plcstring ObjectID[37];
	unsigned long AddDataSize;
	unsigned char AddDataFormat;
	unsigned long AddData;
	unsigned long TimeStamp;
	signed long StatusID;
	ArEventLogRecordIDType RecordID;
	ArEventLogInternalType Internal;
	plcbit Execute;
	plcbit Done;
	plcbit Error;
};
_BUR_PUBLIC void ArEventLogWrite(struct ArEventLogWrite* inst);
struct SdmSystemDump
{	unsigned long configuration;
	unsigned long pDevice;
	unsigned long pFile;
	unsigned long pParam;
	unsigned short status;
	unsigned short i_state;
	unsigned short i_result;
	unsigned long i_tmp;
	plcbit enable;
};
_BUR_PUBLIC void SdmSystemDump(struct SdmSystemDump* inst);
struct MD_LimitFileNumber
{	plcstring FileDeviceName[33];
	plcstring DirectoryName[33];
	plcstring FileNamePattern[129];
	unsigned short MaxCount;
	signed long ErrorID;
	plcstring ErrorFileNamePattern[81];
	unsigned short step;
	struct DirOpen fbDirOpen;
	struct DirReadEx fbDirRead;
	struct DirClose fbDirClose;
	struct FileDelete fbFileDelete;
	fiDIR_READ_EX_DATA dirEntry;
	unsigned short fileCount;
	plcdt timeStamps[101];
	unsigned char pass;
	plcbit Execute;
	plcbit Done;
	plcbit Busy;
	plcbit Error;
};
_BUR_PUBLIC void MD_LimitFileNumber(struct MD_LimitFileNumber* inst);
struct MD_Dump
{	plcstring FileDeviceName[33];
	plcstring FileNamePrefix[33];
	unsigned short MaxFileCount;
	signed long ErrorID;
	plcstring DumpFileName[256];
	unsigned short step;
	struct SdmSystemDump fbSystemDump;
	struct MD_LimitFileNumber fbLimitFileNumber;
	plcbit Execute;
	plcbit Done;
	plcbit Busy;
	plcbit Error;
};
_BUR_PUBLIC void MD_Dump(struct MD_Dump* inst);
struct MD_LogWrite
{	plcstring Name[11];
	signed long EventID;
	plcstring ObjectID[37];
	plcstring Ascii[121];
	signed long ErrorID;
	struct ArEventLogCreate fbLogCreate;
	struct ArEventLogGetIdent fbLogGetIdent;
	struct ArEventLogWrite fbLogWrite;
	unsigned short step;
	plcbit Execute;
	plcbit Done;
	plcbit Busy;
	plcbit Error;
};
_BUR_PUBLIC void MD_LogWrite(struct MD_LogWrite* inst);
struct MD_LogWatchBOOL
{	plcstring LogName[11];
	plcstring SignalName[37];
	signed long EventID;
	signed long ErrorID;
	unsigned short step;
	struct MD_LogWrite fbLogWrite;
	plcbit Enable;
	plcbit Signal;
	plcbit Valid;
	plcbit Busy;
	plcbit Error;
	plcbit signalOld;
};
_BUR_PUBLIC void MD_LogWatchBOOL(struct MD_LogWatchBOOL* inst);
struct MD_LogWatch8Flags
{	unsigned char Signal;
	plcstring LogName[11];
	plcstring SignalName[37];
	signed long EventID;
	plcstring Flag[8][9];
	signed long ErrorID;
	unsigned char signalOld;
	unsigned short step;
	struct MD_LogWrite fbLogWrite;
	plcbit Enable;
	plcbit Valid;
	plcbit Busy;
	plcbit Error;
};
_BUR_PUBLIC void MD_LogWatch8Flags(struct MD_LogWatch8Flags* inst);
struct MD_LogWatchDINT
{	signed long Signal;
	plcstring LogName[11];
	plcstring SignalName[37];
	signed long EventID;
	signed long ErrorID;
	signed long signalOld;
	unsigned short step;
	struct MD_LogWrite fbLogWrite;
	plcbit Enable;
	plcbit Valid;
	plcbit Busy;
	plcbit Error;
};
_BUR_PUBLIC void MD_LogWatchDINT(struct MD_LogWatchDINT* inst);
struct MD_LogWatchSTRING
{	plcstring Signal[121];
	plcstring LogName[11];
	plcstring SignalName[37];
	signed long EventID;
	signed long ErrorID;
	plcstring signalOld[121];
	unsigned short step;
	struct MD_LogWrite fbLogWrite;
	plcbit Enable;
	plcbit Valid;
	plcbit Busy;
	plcbit Error;
};
_BUR_PUBLIC void MD_LogWatchSTRING(struct MD_LogWatchSTRING* inst);
_BUR_LOCAL plcbit event1;
_BUR_LOCAL InterfaceType interface;
_BUR_LOCAL plcbit light_barrier;
_BUR_LOCAL signed long BASIC_INFO_ID;
_BUR_LOCAL signed long counter;
_BUR_LOCAL plcstring tempstring[81];
_BUR_LOCAL struct MD_LogWrite MD_LogWrite_0;
_BUR_LOCAL struct MD_LogWatchBOOL MD_LogWatchBOOL_0;
_BUR_LOCAL struct MD_LogWatch8Flags MD_LogWatch8Flags_0;
_BUR_LOCAL struct MD_LogWatchDINT MD_LogWatchDINT_0;
_BUR_LOCAL struct MD_Dump MD_Dump_0;
_BUR_LOCAL unsigned char n;
_BUR_LOCAL signed short step;
_BUR_LOCAL plcstring stepStr[81];
_BUR_LOCAL struct MD_LogWatchSTRING MD_LogWatchSTRING_0;
_BUR_LOCAL plcbit error_situation;
