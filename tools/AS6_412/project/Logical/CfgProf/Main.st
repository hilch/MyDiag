
PROGRAM _INIT
	(*Define Profiler settings
	see https://help.br-automation.com/#/en/4/libraries%2Fasarprof%2Fdatatypes%2Fprofiler_definition.html for details
	*)
	definition.logGroup := profLOGGRP_ALL;  (*Event grout to be logged. profLOGGRP_ALL = log all groups *)
	definition.logMode :=  profLOGMOD_STARTUPINST OR profLOGMOD_CONTINUOUS;  (* starts the profiling then continous recording*)
	definition.archMode := profARCHMOD_OPT_ERROR; (*Automatic archiving in case of error*)
	definition.memTypeDef := profMEMTYPE_USERROM ;  (*Store definition module to USERROM*)
	definition.libFctCnt := 1;
	definition.pLibFunctions := ADR(libraryFunctions);
	
	(* storing to USERRAM allows to find watchdog errors, but causes a high system load !! *)
	definition.memTypeDat := profMEMTYPE_DRAM; //profMEMTYPE_USERRAM ;  (*Store data object to USERRAM = used to record WATCHDOG errors*)
	definition.bufferSize := 1024*2000;  (*Size of the log buffer in bytes*)
	definition.backupLevel := profBKPLEVEL_SHUTDOWN;  (*profiling is backed up only at shutdown*)
	definition.addDataSize := 0;
	 
	fbProfiler.Enable := TRUE;
END_PROGRAM

PROGRAM _CYCLIC
	fbProfiler(PrfDef := definition);
	 
END_PROGRAM

PROGRAM _EXIT
	(* Insert code here *)
	 
END_PROGRAM

