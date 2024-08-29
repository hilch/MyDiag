[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)
[![Made For B&R](https://github.com/hilch/BandR-badges/blob/main/Made-For-BrAutomation.svg)](https://www.br-automation.com)

# MyDiag
Helper Library for diagnosis with B&R Automation Runtime logger
Included are some function blocks that can be used to easily make entries in application specific loggers. 
In the event of an error, internal states (state machines, internal process data) can thus be brought into connection with system loggers.
As a further aid, function block to store a SystemDump in case of an event is present.


## Dependencies / Preconditions

- ArEventLog
- astime
- standard
- sys_lib
- brsystem
- FileIO
- AsArSdm

GCC >= V6.3.0



# Functions / function blocks

## Function blocks for logging

They are just convenience function around ArEventLog. If logger does not exist it will be created.

(Older Automation Runtime seem to have problems generating logbooks in tasks with short cycle times. 
This can be avoided if these functions are called once in _INIT.)

example:
```
PROGRAM _INIT
	(* ensure the user log is already present after _INIT *)
	REPEAT
		MD_LogWatchDINT_0( Enable := TRUE );
	UNTIL NOT MD_LogWatchDINT_0.Busy
	END_REPEAT
END_PROGRAM
```

Set 'EventID' according to ArEventLog to decide if message is error, warning, info etc.
Every write command is executed within 1 cycle.

### MD_LogWatchBOOL

Write status of BOOL variable into logger on variable change.

usage:
```
PROGRAM _INIT
	(* initialization MD_LogWatchBOOL *)
	MD_LogWatchBOOL_0( Enable := FALSE, LogName := 'mylog', SignalName := 'light barrier', EventID := BASIC_INFO_ID  );
	MD_LogWatchBOOL_0.Enable := TRUE; 
END_PROGRAM

PROGRAM _CYCLIC
	(* wait for a signal change *)
	MD_LogWatchBOOL_0( Signal := light_barrier );
END_PROGRAM
```


### MD_LogWatch8Flags

Writes status of up to 8 bits ('flags') into logger on variable change.
Each bit is assigned a text via '.Flag[x]', where a '1' state is indicated with upper case letters and a '0' state with lower case letters. 
If the output text in logger is preceded by an asterisk '*', this means that the state of this bit has changed.

usage:
```
PROGRAM _INIT
	(* initialization MD_LogWatch8Flags *)
	MD_LogWatch8Flags_0( Enable := FALSE, LogName := 'mylog', SignalName := 'interface signals', EventID := BASIC_INFO_ID );
	MD_LogWatch8Flags_0.Flag[0] := 'fr.Power'; (* max. 8 characters *)
	MD_LogWatch8Flags_0.Flag[1] := 'fr.Auto';
	MD_LogWatch8Flags_0.Flag[2] := 'to.Power';
	MD_LogWatch8Flags_0.Flag[3] := 'to.Auto';
	MD_LogWatch8Flags_0.Flag[4] := 'to.Cover';
	MD_LogWatch8Flags_0.Flag[5] := 'to.Error';
	MD_LogWatch8Flags_0.Enable := TRUE;

END_PROGRAM

PROGRAM _CYCLIC
	(* collect signals from an interface *)
	MD_LogWatch8Flags_0.Signal.0 := interface.from.PowerOn;
	MD_LogWatch8Flags_0.Signal.1 := interface.from.StartAutomatic;
	MD_LogWatch8Flags_0.Signal.2 := interface.to.PowerIsOn;
	MD_LogWatch8Flags_0.Signal.3 := interface.to.AutomaticIsActive;
	MD_LogWatch8Flags_0.Signal.4 := interface.to.CoverOpenPermission;
	MD_LogWatch8Flags_0.Signal.5 := interface.to.Error;
	(* wait for signal change *)
	MD_LogWatch8Flags_0();
END_PROGRAM
```


### MD_LogWatchDINT

Writes status of DINT variable into logger on variable change.

usage:
```
PROGRAM _INIT
	(* initialization MD_LogWatchDINT *)
	MD_LogWatchDINT_0( Enable := FALSE, LogName := 'mylog', SignalName := 'counter', EventID := BASIC_INFO_ID );
	MD_LogWatchDINT_0.Enable := TRUE;
END_PROGRAM

PROGRAM _CYCLIC
	(* wait for signal change *)
	MD_LogWatchDINT_0( Signal := counter );
END_PROGRAM
```


### MD_LogWatchSTRING

Writes contents of STRING variable into logger on variable change.

usage:
```
PROGRAM _INIT
	(* initialization MD_LogWatchSTRING *)
	MD_LogWatchSTRING_0( Enable := FALSE, LogName := 'mylog', SignalName := 'step', EventID := BASIC_INFO_ID );
	MD_LogWatchSTRING_0.Enable := TRUE;
	(* init state machine variables *)
	step := 0;
	stepStr := '_INIT';
END_PROGRAM

PROGRAM _CYCLIC
	CASE step OF
		0:
		stepStr := 'Step 0';
		step := 1;		

		1:
		stepStr := 'Step 1';
		step := 2;

		2:
		stepStr := 'Step 2';
		step := 3;

		3:
		stepStr := 'Step 3';
		step := -1;

	END_CASE
	(* wait for signal change *)
	MD_LogWatchSTRING_0( Signal := stepStr );
END_PROGRAM
```


### MD_LogWrite

Writes into Logger. Generic function with 'Execute' input.

usage:
```
PROGRAM _INIT
	(* initialization MD_LogWrite() *)
	MD_LogWrite_0(Execute := FALSE, Name := 'mylog', ObjectID := 'program: Program', EventID := BASIC_INFO_ID );
END_PROGRAM

PROGRAM _CYCLIC
	(* wait for an event *)
	IF event1 THEN (* wait for an event *)
		event1 := FALSE;
		counter := counter + 1;
		(* prepare storing data into logger *)
		MD_LogWrite_0.Ascii := 'counter:';
		brsitoa( counter, ADR(tempstring) );
		brsstrcat( ADR(MD_LogWrite_0.Ascii),  ADR(tempstring) );
		MD_LogWrite_0( Execute := TRUE );
	END_IF
END_PROGRAM
```


### MD_Dump

Create a System Dump File on local storage. The system date is included in file name.
The number of files can be limited to reduce storage space.

usage:
```
PROGRAM _INIT
	(* initialize system dumping *)
	MD_Dump_0( Execute := FALSE, FileDeviceName := 'Diagnosis', FileNamePrefix := 'MyDumps', MaxFileCount := 10 );
END_PROGRAM
```

```
PROGRAM _CYCLIC
	MD_Dump_0( Execute := error_situation );
END_PROGRAM
```

## Helper functions and function blocks

These function blocks are internally used but might be helpful in other situations.

### MD_ascDT

Returns ASCII timestring for DATE_AND_TIME

usage:
```
MD_ascDT( entry.LocalTime, ADR(strAsctime), SIZEOF(strAsctime) );  (* convert time stamp to readable string *)
```
The output will be a string like `'Thu Aug 23  14:55:20'`.

### MD_filenameDT

Returns a valid filename with given prefix and IEC like timestamp included.
This function block is used for generating filenames within MD_Record 

usage:
```
MD_filenameDT( ADR('SystemDump_'), ADR(filename), SIZEOF(filename) );
```
The output will be a string like `'SystemDump_2023-01-15T14_55_20'`.

### MD_LimitFileNumber

Limits the number of files on a file device. The FileNamePattern can be given by a regular expression.
With a rising edge at the 'Execute' input, the oldest files are deleted until the maximum number 'MaxCount' is reached. 

usage:

```
MD_LimitFileNumber( Execute := TRUE, FileDeviceName := 'Diagnosis', DirectoryName := '', FileNamePattern := 'SysDump_');

```