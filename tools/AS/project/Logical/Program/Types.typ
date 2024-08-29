
TYPE
	InterfaceFromType : 	STRUCT 
		PowerOn : BOOL;
		StartAutomatic : BOOL;
	END_STRUCT;
	InterfaceToType : 	STRUCT 
		PowerIsOn : BOOL;
		AutomaticIsActive : BOOL;
		CoverOpenPermission : BOOL;
		Error : BOOL;
	END_STRUCT;
	InterfaceType : 	STRUCT 
		from : InterfaceFromType;
		to : InterfaceToType;
	END_STRUCT;
END_TYPE
