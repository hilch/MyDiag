
PROGRAM _INIT
	(* initialization MD_LogWrite() *)
	MD_LogWrite_0(Execute := FALSE, Name := 'mylog', ObjectID := 'program: Program', EventID := BASIC_INFO_ID );
	
	(* initialization MD_LogWatchBOOL *)
	MD_LogWatchBOOL_0( Enable := FALSE, LogName := 'mylog', SignalName := 'light barrier', EventID := BASIC_INFO_ID  );
	MD_LogWatchBOOL_0.Enable := TRUE; 

	(* initialization MD_LogWatch8Flags *)
	MD_LogWatch8Flags_0( Enable := FALSE, LogName := 'mylog', SignalName := 'interface signals', EventID := BASIC_INFO_ID );
	MD_LogWatch8Flags_0.Flag[0] := 'fr.Power'; (* max. 8 characters *)
	MD_LogWatch8Flags_0.Flag[1] := 'fr.Auto';
	MD_LogWatch8Flags_0.Flag[2] := 'to.Power';
	MD_LogWatch8Flags_0.Flag[3] := 'to.Auto';
	MD_LogWatch8Flags_0.Flag[4] := 'to.Cover';
	MD_LogWatch8Flags_0.Flag[5] := 'to.Error';
	MD_LogWatch8Flags_0.Enable := TRUE;


	(* initialization MD_LogWatchDINT *)
	MD_LogWatchDINT_0( Enable := FALSE, LogName := 'mylog', SignalName := 'counter', EventID := BASIC_INFO_ID );
	MD_LogWatchDINT_0.Enable := TRUE;


	(* initialization MD_LogWatchSTRING *)
	MD_LogWatchSTRING_0( Enable := FALSE, LogName := 'mylog', SignalName := 'step', EventID := BASIC_INFO_ID );
	MD_LogWatchSTRING_0.Enable := TRUE;
	(* init state machine variables *)
	step := 0;
	stepStr := '_INIT';

	// ensure the user log is already present after _INIT
	REPEAT
		MD_LogWatchDINT_0( Enable := TRUE );
	UNTIL NOT MD_LogWatchDINT_0.Busy
	END_REPEAT

	
	// initialize system dumping
	MD_Dump_0( Execute := FALSE, FileDeviceName := 'Diagnosis', FileNamePrefix := 'MyDumps', MaxFileCount := 10 );


	n := 0;
END_PROGRAM


PROGRAM _CYCLIC
	(* MD_LogWrite() example *)
	IF event1 THEN (* wait for an event *)
		event1 := FALSE;
		counter := counter + 1;
		(* prepare storing data into logger *)
		MD_LogWrite_0.Ascii := 'counter:';
		brsitoa( counter, ADR(tempstring) );
		brsstrcat( ADR(MD_LogWrite_0.Ascii),  ADR(tempstring) );
		MD_LogWrite_0( Execute := TRUE );
	END_IF

	MD_LogWrite_0(); 
	IF MD_LogWrite_0.Done OR MD_LogWrite_0.Error THEN
		MD_LogWrite_0.Execute := FALSE;
	END_IF


	(* MD_LogWatchBOOL() example *)
	(* wait for a signal change *)
	MD_LogWatchBOOL_0( Signal := light_barrier );




	(* MD_LogWatch8Flags() example *)
	(* collect signals from an interface *)
	MD_LogWatch8Flags_0.Signal.0 := interface.from.PowerOn;
	MD_LogWatch8Flags_0.Signal.1 := interface.from.StartAutomatic;
	MD_LogWatch8Flags_0.Signal.2 := interface.to.PowerIsOn;
	MD_LogWatch8Flags_0.Signal.3 := interface.to.AutomaticIsActive;
	MD_LogWatch8Flags_0.Signal.4 := interface.to.CoverOpenPermission;
	MD_LogWatch8Flags_0.Signal.5 := interface.to.Error;
	(* wait for signal change *)
	MD_LogWatch8Flags_0();



	(* MD_LogWatchDINT() example *)
	(* wait for signal change *)
	MD_LogWatchDINT_0( Signal := counter );


	(* test cycle accuracy *)
	IF n < 3 THEN
		light_barrier := NOT light_barrier;
		interface.to.AutomaticIsActive := NOT interface.to.AutomaticIsActive;
		counter := counter + 1;
		n := n + 1;
	END_IF
	


	(* 	MD_LogWatchSTRING() example *)

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


	(* MD_Dump example *)
	MD_Dump_0( Execute := error_situation );
			 
END_PROGRAM

PROGRAM _EXIT
	(* Insert code here *)
	 
END_PROGRAM

