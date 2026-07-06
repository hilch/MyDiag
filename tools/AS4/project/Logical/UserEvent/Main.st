
PROGRAM _INIT
	fbEvent.enable := TRUE;

	 
END_PROGRAM

PROGRAM _CYCLIC

	// User Event '13'
	fbEvent.objIdent := 13;
	fbEvent.userEvent := profUSER_EVENT_START;
	fbEvent();

	FOR i := 0 TO 1000 DO
		brsstrcpy( ADR(dest), ADR(src)  ); // waste time..., this is user event 13 = 0x0d in profiler
	END_FOR

	fbEvent.userEvent := profUSER_EVENT_STOP;
	fbEvent();


	// User Event '14'
	fbEvent.objIdent := 14;
	fbEvent.userEvent := profUSER_EVENT_START;
	fbEvent();	 
	IF crash THEN
		crash := FALSE;
		t := clock_ms();
		REPEAT
			UNTIL DiffT( clock_ms(), t ) >= 30  // user event 14 = 0x0e will be logged with a duration of 30 ms 
												// what means we'll got a cycle time violation (CTV) when running
												// this task in a 10ms task class
		END_REPEAT
	END_IF
	fbEvent.userEvent := profUSER_EVENT_STOP;
	fbEvent();


END_PROGRAM

PROGRAM _EXIT
	(* Insert code here *)
	 
END_PROGRAM

