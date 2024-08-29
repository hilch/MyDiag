
FUNCTION_BLOCK MD_Dump
	VAR_INPUT
		Execute : BOOL;
		FileDeviceName : STRING[32]; (*file device*)
		FileNamePrefix : {REDUND_UNREPLICABLE} STRING[32];
		MaxFileCount : {REDUND_UNREPLICABLE} UINT;
	END_VAR
	VAR_OUTPUT
		Done : BOOL;
		Busy : BOOL;
		Error : BOOL;
		ErrorID : DINT;
		DumpFileName : STRING[255];
	END_VAR
	VAR
		step : UINT;
		fbSystemDump : SdmSystemDump;
		fbLimitFileNumber : MD_LimitFileNumber;
	END_VAR
END_FUNCTION_BLOCK

{REDUND_ERROR} FUNCTION MD_ascDT : BOOL (*Returns ASCII timestring for DATE_AND_TIME*) (*$GROUP=User,$CAT=User,$GROUPICON=User.png,$CATICON=User.png*)
	VAR_INPUT
		DT1 : DATE_AND_TIME;
		pString : UDINT; (*pointer to output string*)
		maxSize : USINT; (*max length of output string*)
	END_VAR
END_FUNCTION

{REDUND_ERROR} FUNCTION MD_filenameDT : UINT (*Returns a filename with timestamp included*) (*$GROUP=User,$CAT=User,$GROUPICON=User.png,$CATICON=User.png*)
	VAR_INPUT
		prefix : UDINT; (*pointer to prefix string (input)*)
		pString : UDINT; (*pointer to output string*)
		maxSize : UDINT; (*max length of output string*)
	END_VAR
END_FUNCTION

{REDUND_ERROR} FUNCTION_BLOCK MD_LogWatchBOOL (*Write status of BOOL variable into logger*) (*$GROUP=User,$CAT=User,$GROUPICON=User.png,$CATICON=User.png*)
	VAR_INPUT
		Enable : BOOL;
		Signal : BOOL;
		LogName : STRING[10];
		SignalName : STRING[36];
		EventID : DINT;
	END_VAR
	VAR_OUTPUT
		Valid : BOOL;
		Busy : BOOL;
		Error : BOOL;
		ErrorID : DINT;
	END_VAR
	VAR
		signalOld : BOOL;
		step : UINT;
		fbLogWrite : MD_LogWrite;
	END_VAR
END_FUNCTION_BLOCK

{REDUND_ERROR} FUNCTION_BLOCK MD_LogWatch8Flags (*Write status of 8 flags variable into logger*) (*$GROUP=User,$CAT=User,$GROUPICON=User.png,$CATICON=User.png*)
	VAR_INPUT
		Enable : BOOL;
		Signal : USINT;
		LogName : STRING[10];
		SignalName : STRING[36];
		EventID : DINT;
		Flag : ARRAY[0..7] OF STRING[8];
	END_VAR
	VAR_OUTPUT
		Valid : BOOL;
		Busy : BOOL;
		Error : BOOL;
		ErrorID : DINT;
	END_VAR
	VAR
		signalOld : USINT;
		step : UINT;
		fbLogWrite : MD_LogWrite;
	END_VAR
END_FUNCTION_BLOCK

{REDUND_ERROR} FUNCTION_BLOCK MD_LogWatchDINT (*Write status of DINT variable into logger*) (*$GROUP=User,$CAT=User,$GROUPICON=User.png,$CATICON=User.png*)
	VAR_INPUT
		Enable : BOOL;
		Signal : DINT;
		LogName : STRING[10];
		SignalName : STRING[36];
		EventID : DINT;
	END_VAR
	VAR_OUTPUT
		Valid : BOOL;
		Busy : BOOL;
		Error : BOOL;
		ErrorID : DINT;
	END_VAR
	VAR
		signalOld : DINT;
		step : UINT;
		fbLogWrite : MD_LogWrite;
	END_VAR
END_FUNCTION_BLOCK

{REDUND_ERROR} FUNCTION_BLOCK MD_LogWatchSTRING (*Write contents of STRING variable into logger*) (*$GROUP=User,$CAT=User,$GROUPICON=User.png,$CATICON=User.png*)
	VAR_INPUT
		Enable : BOOL;
		Signal : STRING[120];
		LogName : STRING[10];
		SignalName : STRING[36];
		EventID : DINT;
	END_VAR
	VAR_OUTPUT
		Valid : BOOL;
		Busy : BOOL;
		Error : BOOL;
		ErrorID : DINT;
	END_VAR
	VAR
		signalOld : STRING[120];
		step : UINT;
		fbLogWrite : MD_LogWrite;
	END_VAR
END_FUNCTION_BLOCK

{REDUND_ERROR} FUNCTION_BLOCK MD_LogWrite (*Write into Logger*) (*$GROUP=User,$CAT=User,$GROUPICON=User.png,$CATICON=User.png*)
	VAR_INPUT
		Execute : BOOL;
		Name : STRING[10];
		EventID : DINT;
		ObjectID : STRING[36];
		Ascii : STRING[120];
	END_VAR
	VAR_OUTPUT
		Done : BOOL;
		Busy : BOOL;
		Error : BOOL;
		ErrorID : DINT;
	END_VAR
	VAR
		fbLogCreate : ArEventLogCreate;
		fbLogGetIdent : ArEventLogGetIdent;
		fbLogWrite : ArEventLogWrite;
		step : UINT;
	END_VAR
END_FUNCTION_BLOCK

{REDUND_ERROR} FUNCTION_BLOCK MD_LimitFileNumber (*Limit number of files in a certain folder*)
	VAR_INPUT
		Execute : BOOL;
		FileDeviceName : STRING[32]; (*file device*)
		DirectoryName : STRING[32]; (*directory name*)
		FileNamePattern : STRING[128]; (*regular expression for file names*)
		MaxCount : UINT; (*limited number of files*)
	END_VAR
	VAR_OUTPUT
		Done : BOOL;
		Busy : BOOL;
		Error : BOOL;
		ErrorID : DINT;
		ErrorFileNamePattern : STRING[80]; (*extended error information*)
	END_VAR
	VAR
		step : UINT;
		fbDirOpen : DirOpen;
		fbDirRead : DirReadEx;
		fbDirClose : DirClose;
		fbFileDelete : FileDelete;
		dirEntry : fiDIR_READ_EX_DATA;
		fileCount : UINT;
		timeStamps : ARRAY[0..100] OF DATE_AND_TIME;
		pass : USINT;
	END_VAR
END_FUNCTION_BLOCK
