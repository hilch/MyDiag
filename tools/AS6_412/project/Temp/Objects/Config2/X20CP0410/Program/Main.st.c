#define _DEFAULT_INCLUDE
#include <bur\plctypes.h>
#include "C:/Projects/github/MyDiag/tools/AS/project/Temp/Objects/Config2/X20CP0410/Program/Mainst.h"
#line 1 "C:/Projects/github/MyDiag/tools/AS/project/Logical/Program/Main.nodebug"
#line 2 "C:/Projects/github/MyDiag/tools/AS/project/Logical/Program/Main.st"
void __BUR__ENTRY_INIT_FUNCT__(void){int __AS__Local0_00000;plcstring* __AS__Local3_00000;plcstring* __AS__Local4_00000;{

(MD_LogWrite_0.Execute=0);;__AS__Local3_00000=(plcstring*)MD_LogWrite_0.Name; __AS__Local4_00000=(plcstring*)"mylog"; for(__AS__Local0_00000=0; __AS__Local0_00000<5l && __AS__Local4_00000[__AS__Local0_00000]!=0; __AS__Local0_00000++) __AS__Local3_00000[__AS__Local0_00000] = __AS__Local4_00000[__AS__Local0_00000]; __AS__Local3_00000[__AS__Local0_00000] = 0;;(MD_LogWrite_0.EventID=BASIC_INFO_ID);;__AS__Local3_00000=(plcstring*)MD_LogWrite_0.ObjectID; __AS__Local4_00000=(plcstring*)"program: Program"; for(__AS__Local0_00000=0; __AS__Local0_00000<16l && __AS__Local4_00000[__AS__Local0_00000]!=0; __AS__Local0_00000++) __AS__Local3_00000[__AS__Local0_00000] = __AS__Local4_00000[__AS__Local0_00000]; __AS__Local3_00000[__AS__Local0_00000] = 0;;MD_LogWrite(&MD_LogWrite_0);


(MD_LogWatchBOOL_0.Enable=0);;__AS__Local3_00000=(plcstring*)MD_LogWatchBOOL_0.LogName; __AS__Local4_00000=(plcstring*)"mylog"; for(__AS__Local0_00000=0; __AS__Local0_00000<5l && __AS__Local4_00000[__AS__Local0_00000]!=0; __AS__Local0_00000++) __AS__Local3_00000[__AS__Local0_00000] = __AS__Local4_00000[__AS__Local0_00000]; __AS__Local3_00000[__AS__Local0_00000] = 0;;__AS__Local3_00000=(plcstring*)MD_LogWatchBOOL_0.SignalName; __AS__Local4_00000=(plcstring*)"light barrier"; for(__AS__Local0_00000=0; __AS__Local0_00000<13l && __AS__Local4_00000[__AS__Local0_00000]!=0; __AS__Local0_00000++) __AS__Local3_00000[__AS__Local0_00000] = __AS__Local4_00000[__AS__Local0_00000]; __AS__Local3_00000[__AS__Local0_00000] = 0;;(MD_LogWatchBOOL_0.EventID=BASIC_INFO_ID);;MD_LogWatchBOOL(&MD_LogWatchBOOL_0);
(MD_LogWatchBOOL_0.Enable=1);


(MD_LogWatch8Flags_0.Enable=0);;__AS__Local3_00000=(plcstring*)MD_LogWatch8Flags_0.LogName; __AS__Local4_00000=(plcstring*)"mylog"; for(__AS__Local0_00000=0; __AS__Local0_00000<5l && __AS__Local4_00000[__AS__Local0_00000]!=0; __AS__Local0_00000++) __AS__Local3_00000[__AS__Local0_00000] = __AS__Local4_00000[__AS__Local0_00000]; __AS__Local3_00000[__AS__Local0_00000] = 0;;__AS__Local3_00000=(plcstring*)MD_LogWatch8Flags_0.SignalName; __AS__Local4_00000=(plcstring*)"interface signals"; for(__AS__Local0_00000=0; __AS__Local0_00000<17l && __AS__Local4_00000[__AS__Local0_00000]!=0; __AS__Local0_00000++) __AS__Local3_00000[__AS__Local0_00000] = __AS__Local4_00000[__AS__Local0_00000]; __AS__Local3_00000[__AS__Local0_00000] = 0;;(MD_LogWatch8Flags_0.EventID=BASIC_INFO_ID);;MD_LogWatch8Flags(&MD_LogWatch8Flags_0);
__AS__Local3_00000=(plcstring*)MD_LogWatch8Flags_0.Flag[0]; __AS__Local4_00000=(plcstring*)"fr.Power"; for(__AS__Local0_00000=0; __AS__Local0_00000<8l && __AS__Local4_00000[__AS__Local0_00000]!=0; __AS__Local0_00000++) __AS__Local3_00000[__AS__Local0_00000] = __AS__Local4_00000[__AS__Local0_00000]; __AS__Local3_00000[__AS__Local0_00000] = 0;
__AS__Local3_00000=(plcstring*)MD_LogWatch8Flags_0.Flag[1]; __AS__Local4_00000=(plcstring*)"fr.Auto"; for(__AS__Local0_00000=0; __AS__Local0_00000<7l && __AS__Local4_00000[__AS__Local0_00000]!=0; __AS__Local0_00000++) __AS__Local3_00000[__AS__Local0_00000] = __AS__Local4_00000[__AS__Local0_00000]; __AS__Local3_00000[__AS__Local0_00000] = 0;
__AS__Local3_00000=(plcstring*)MD_LogWatch8Flags_0.Flag[2]; __AS__Local4_00000=(plcstring*)"to.Power"; for(__AS__Local0_00000=0; __AS__Local0_00000<8l && __AS__Local4_00000[__AS__Local0_00000]!=0; __AS__Local0_00000++) __AS__Local3_00000[__AS__Local0_00000] = __AS__Local4_00000[__AS__Local0_00000]; __AS__Local3_00000[__AS__Local0_00000] = 0;
__AS__Local3_00000=(plcstring*)MD_LogWatch8Flags_0.Flag[3]; __AS__Local4_00000=(plcstring*)"to.Auto"; for(__AS__Local0_00000=0; __AS__Local0_00000<7l && __AS__Local4_00000[__AS__Local0_00000]!=0; __AS__Local0_00000++) __AS__Local3_00000[__AS__Local0_00000] = __AS__Local4_00000[__AS__Local0_00000]; __AS__Local3_00000[__AS__Local0_00000] = 0;
__AS__Local3_00000=(plcstring*)MD_LogWatch8Flags_0.Flag[4]; __AS__Local4_00000=(plcstring*)"to.Cover"; for(__AS__Local0_00000=0; __AS__Local0_00000<8l && __AS__Local4_00000[__AS__Local0_00000]!=0; __AS__Local0_00000++) __AS__Local3_00000[__AS__Local0_00000] = __AS__Local4_00000[__AS__Local0_00000]; __AS__Local3_00000[__AS__Local0_00000] = 0;
__AS__Local3_00000=(plcstring*)MD_LogWatch8Flags_0.Flag[5]; __AS__Local4_00000=(plcstring*)"to.Error"; for(__AS__Local0_00000=0; __AS__Local0_00000<8l && __AS__Local4_00000[__AS__Local0_00000]!=0; __AS__Local0_00000++) __AS__Local3_00000[__AS__Local0_00000] = __AS__Local4_00000[__AS__Local0_00000]; __AS__Local3_00000[__AS__Local0_00000] = 0;
(MD_LogWatch8Flags_0.Enable=1);



(MD_LogWatchDINT_0.Enable=0);;__AS__Local3_00000=(plcstring*)MD_LogWatchDINT_0.LogName; __AS__Local4_00000=(plcstring*)"mylog"; for(__AS__Local0_00000=0; __AS__Local0_00000<5l && __AS__Local4_00000[__AS__Local0_00000]!=0; __AS__Local0_00000++) __AS__Local3_00000[__AS__Local0_00000] = __AS__Local4_00000[__AS__Local0_00000]; __AS__Local3_00000[__AS__Local0_00000] = 0;;__AS__Local3_00000=(plcstring*)MD_LogWatchDINT_0.SignalName; __AS__Local4_00000=(plcstring*)"counter"; for(__AS__Local0_00000=0; __AS__Local0_00000<7l && __AS__Local4_00000[__AS__Local0_00000]!=0; __AS__Local0_00000++) __AS__Local3_00000[__AS__Local0_00000] = __AS__Local4_00000[__AS__Local0_00000]; __AS__Local3_00000[__AS__Local0_00000] = 0;;(MD_LogWatchDINT_0.EventID=BASIC_INFO_ID);;MD_LogWatchDINT(&MD_LogWatchDINT_0);
(MD_LogWatchDINT_0.Enable=1);



(MD_LogWatchSTRING_0.Enable=0);;__AS__Local3_00000=(plcstring*)MD_LogWatchSTRING_0.LogName; __AS__Local4_00000=(plcstring*)"mylog"; for(__AS__Local0_00000=0; __AS__Local0_00000<5l && __AS__Local4_00000[__AS__Local0_00000]!=0; __AS__Local0_00000++) __AS__Local3_00000[__AS__Local0_00000] = __AS__Local4_00000[__AS__Local0_00000]; __AS__Local3_00000[__AS__Local0_00000] = 0;;__AS__Local3_00000=(plcstring*)MD_LogWatchSTRING_0.SignalName; __AS__Local4_00000=(plcstring*)"step"; for(__AS__Local0_00000=0; __AS__Local0_00000<4l && __AS__Local4_00000[__AS__Local0_00000]!=0; __AS__Local0_00000++) __AS__Local3_00000[__AS__Local0_00000] = __AS__Local4_00000[__AS__Local0_00000]; __AS__Local3_00000[__AS__Local0_00000] = 0;;(MD_LogWatchSTRING_0.EventID=BASIC_INFO_ID);;MD_LogWatchSTRING(&MD_LogWatchSTRING_0);
(MD_LogWatchSTRING_0.Enable=1);

(step=0);
__AS__Local3_00000=(plcstring*)stepStr; __AS__Local4_00000=(plcstring*)"_INIT"; for(__AS__Local0_00000=0; __AS__Local0_00000<5l && __AS__Local4_00000[__AS__Local0_00000]!=0; __AS__Local0_00000++) __AS__Local3_00000[__AS__Local0_00000] = __AS__Local4_00000[__AS__Local0_00000]; __AS__Local3_00000[__AS__Local0_00000] = 0;


do{
(MD_LogWatchDINT_0.Enable=1);;MD_LogWatchDINT(&MD_LogWatchDINT_0);
}
while(MD_LogWatchDINT_0.Busy);imp32769_endrepeat0_0:;



(MD_Dump_0.Execute=0);;__AS__Local3_00000=(plcstring*)MD_Dump_0.FileDeviceName; __AS__Local4_00000=(plcstring*)"Diagnosis"; for(__AS__Local0_00000=0; __AS__Local0_00000<9l && __AS__Local4_00000[__AS__Local0_00000]!=0; __AS__Local0_00000++) __AS__Local3_00000[__AS__Local0_00000] = __AS__Local4_00000[__AS__Local0_00000]; __AS__Local3_00000[__AS__Local0_00000] = 0;;__AS__Local3_00000=(plcstring*)MD_Dump_0.FileNamePrefix; __AS__Local4_00000=(plcstring*)"MyDumps"; for(__AS__Local0_00000=0; __AS__Local0_00000<7l && __AS__Local4_00000[__AS__Local0_00000]!=0; __AS__Local0_00000++) __AS__Local3_00000[__AS__Local0_00000] = __AS__Local4_00000[__AS__Local0_00000]; __AS__Local3_00000[__AS__Local0_00000] = 0;;(MD_Dump_0.MaxFileCount=10);;MD_Dump(&MD_Dump_0);


(n=0);
}}
#line 45 "C:/Projects/github/MyDiag/tools/AS/project/Logical/Program/Main.nodebug"
#line 48 "C:/Projects/github/MyDiag/tools/AS/project/Logical/Program/Main.st"
void _CYCLIC __BUR__ENTRY_CYCLIC_FUNCT__(void){int __AS__Local0_00000;plcstring* __AS__Local3_00000;plcstring* __AS__Local4_00000;{

if(event1){
(event1=0);
(counter=(counter+1));

__AS__Local3_00000=(plcstring*)MD_LogWrite_0.Ascii; __AS__Local4_00000=(plcstring*)"counter:"; for(__AS__Local0_00000=0; __AS__Local0_00000<8l && __AS__Local4_00000[__AS__Local0_00000]!=0; __AS__Local0_00000++) __AS__Local3_00000[__AS__Local0_00000] = __AS__Local4_00000[__AS__Local0_00000]; __AS__Local3_00000[__AS__Local0_00000] = 0;
brsitoa(counter,((unsigned long)(&tempstring)));
brsstrcat(((unsigned long)(&MD_LogWrite_0.Ascii)),((unsigned long)(&tempstring)));
(MD_LogWrite_0.Execute=1);;MD_LogWrite(&MD_LogWrite_0);
}

MD_LogWrite(&MD_LogWrite_0);
if((MD_LogWrite_0.Done|MD_LogWrite_0.Error)){
(MD_LogWrite_0.Execute=0);
}




(MD_LogWatchBOOL_0.Signal=light_barrier);;MD_LogWatchBOOL(&MD_LogWatchBOOL_0);






(((_1byte_bit_field_*)(&MD_LogWatch8Flags_0.Signal))->bit0=interface.from.PowerOn);
(((_1byte_bit_field_*)(&MD_LogWatch8Flags_0.Signal))->bit1=interface.from.StartAutomatic);
(((_1byte_bit_field_*)(&MD_LogWatch8Flags_0.Signal))->bit2=interface.to.PowerIsOn);
(((_1byte_bit_field_*)(&MD_LogWatch8Flags_0.Signal))->bit3=interface.to.AutomaticIsActive);
(((_1byte_bit_field_*)(&MD_LogWatch8Flags_0.Signal))->bit4=interface.to.CoverOpenPermission);
(((_1byte_bit_field_*)(&MD_LogWatch8Flags_0.Signal))->bit5=interface.to.Error);

MD_LogWatch8Flags(&MD_LogWatch8Flags_0);





(MD_LogWatchDINT_0.Signal=counter);;MD_LogWatchDINT(&MD_LogWatchDINT_0);



if((((unsigned long)(unsigned char)n<(unsigned long)(unsigned char)3))){
(light_barrier=(light_barrier^1));
(interface.to.AutomaticIsActive=(interface.to.AutomaticIsActive^1));
(counter=(counter+1));
(n=(n+1));
}





switch(step){
case 0:{
__AS__Local3_00000=(plcstring*)stepStr; __AS__Local4_00000=(plcstring*)"Step 0"; for(__AS__Local0_00000=0; __AS__Local0_00000<6l && __AS__Local4_00000[__AS__Local0_00000]!=0; __AS__Local0_00000++) __AS__Local3_00000[__AS__Local0_00000] = __AS__Local4_00000[__AS__Local0_00000]; __AS__Local3_00000[__AS__Local0_00000] = 0;
(step=1);

}break;case 1:{
__AS__Local3_00000=(plcstring*)stepStr; __AS__Local4_00000=(plcstring*)"Step 1"; for(__AS__Local0_00000=0; __AS__Local0_00000<6l && __AS__Local4_00000[__AS__Local0_00000]!=0; __AS__Local0_00000++) __AS__Local3_00000[__AS__Local0_00000] = __AS__Local4_00000[__AS__Local0_00000]; __AS__Local3_00000[__AS__Local0_00000] = 0;
(step=2);

}break;case 2:{
__AS__Local3_00000=(plcstring*)stepStr; __AS__Local4_00000=(plcstring*)"Step 2"; for(__AS__Local0_00000=0; __AS__Local0_00000<6l && __AS__Local4_00000[__AS__Local0_00000]!=0; __AS__Local0_00000++) __AS__Local3_00000[__AS__Local0_00000] = __AS__Local4_00000[__AS__Local0_00000]; __AS__Local3_00000[__AS__Local0_00000] = 0;
(step=3);

}break;case 3:{
__AS__Local3_00000=(plcstring*)stepStr; __AS__Local4_00000=(plcstring*)"Step 3"; for(__AS__Local0_00000=0; __AS__Local0_00000<6l && __AS__Local4_00000[__AS__Local0_00000]!=0; __AS__Local0_00000++) __AS__Local3_00000[__AS__Local0_00000] = __AS__Local4_00000[__AS__Local0_00000]; __AS__Local3_00000[__AS__Local0_00000] = 0;
(step=(-1));

}break;}

__AS__Local3_00000=(plcstring*)MD_LogWatchSTRING_0.Signal; __AS__Local4_00000=(plcstring*)stepStr; for(__AS__Local0_00000=0; __AS__Local0_00000<80l && __AS__Local4_00000[__AS__Local0_00000]!=0; __AS__Local0_00000++) __AS__Local3_00000[__AS__Local0_00000] = __AS__Local4_00000[__AS__Local0_00000]; __AS__Local3_00000[__AS__Local0_00000] = 0;;MD_LogWatchSTRING(&MD_LogWatchSTRING_0);



(MD_Dump_0.Execute=error_situation);;MD_Dump(&MD_Dump_0);

}}
#line 128 "C:/Projects/github/MyDiag/tools/AS/project/Logical/Program/Main.nodebug"
#line 130 "C:/Projects/github/MyDiag/tools/AS/project/Logical/Program/Main.st"
void _EXIT __BUR__ENTRY_EXIT_FUNCT__(void){{


}}
#line 133 "C:/Projects/github/MyDiag/tools/AS/project/Logical/Program/Main.nodebug"

void __AS__ImplInitMain_st(void){__BUR__ENTRY_INIT_FUNCT__();}

__asm__(".section \".plc\"");
__asm__(".ascii \"iecfile \\\"Logical/Global.typ\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/operator/operator.typ\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/runtime/runtime.typ\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/astime/astime.typ\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/AsIecCon/AsIecCon.typ\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/AsZip/AsZip.typ\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/FileIO/FileIO.typ\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/standard/standard.typ\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/AsBrStr/AsBrStr.typ\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/sys_lib/sys_lib.typ\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/brsystem/brsystem.typ\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/ArEventLog/ArEventLog.typ\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/DataObj/DataObj.typ\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/AsHttp/AsHttp.typ\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/AsArSdm/AsArSdm.typ\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"C:/Projects/github/MyDiag/sources/MyDiag/MyDiagTypes.typ\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/operator/operator.fun\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/runtime/runtime.fun\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/astime/astime.fun\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/AsIecCon/AsIecCon.fun\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/AsZip/AsZip.fun\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/FileIO/FileIO.fun\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/standard/standard.fun\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/AsBrStr/AsBrStr.fun\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/sys_lib/sys_lib.fun\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/brsystem/brsystem.fun\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/ArEventLog/ArEventLog.fun\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/DataObj/DataObj.fun\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/AsHttp/AsHttp.fun\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/AsArSdm/AsArSdm.fun\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"C:/Projects/github/MyDiag/sources/MyDiag/MyDiag.fun\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Global.var\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/operator/operator.var\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/runtime/runtime.var\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/astime/astime.var\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/AsIecCon/AsIecCon.var\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/AsZip/AsZip.var\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/FileIO/FileIO.var\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/standard/standard.var\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/AsBrStr/AsBrStr.var\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/sys_lib/sys_lib.var\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/brsystem/brsystem.var\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/ArEventLog/ArEventLog.var\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/DataObj/DataObj.var\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/AsHttp/AsHttp.var\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/AsArSdm/AsArSdm.var\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"C:/Projects/github/MyDiag/sources/MyDiag/MyDiagConstants.var\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Program/Types.typ\\\" scope \\\"local\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Program/Variables.var\\\" scope \\\"local\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"C:/Projects/github/MyDiag/tools/AS/project/Temp/Objects/Config2/X20CP0410/Program/Main.st.var\\\" scope \\\"local\\\"\\n\"");
__asm__(".ascii \"plcreplace \\\"C:/Projects/github/MyDiag/tools/AS/project/Temp/Objects/Config2/X20CP0410/Program/Main.st.c\\\" \\\"C:/Projects/github/MyDiag/tools/AS/project/Logical/Program/Main.st\\\"\\n\"");
__asm__(".previous");

__asm__(".section \".plciec\"");
__asm__(".ascii \"plcdata_const 'BASIC_INFO_ID'\\n\"");
__asm__(".previous");
