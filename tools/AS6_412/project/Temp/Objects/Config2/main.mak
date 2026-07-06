SHELL := cmd.exe
CYGWIN=nontsec
export PATH := C:\WINDOWS\system32;C:\WINDOWS;C:\WINDOWS\System32\Wbem;C:\WINDOWS\System32\WindowsPowerShell\v1.0\;C:\Program Files (x86)\Pulse Secure\VC142.CRT\X64\;C:\Program Files (x86)\Pulse Secure\VC142.CRT\X86\;C:\Program Files (x86)\Common Files\Pulse Secure\TNC Client Plugin\;C:\Program Files\Python311;C:\Users\hilchenbachc\AppData\Roaming\Python\Python311\Scripts;C:\Program Files\dotnet\;C:\Program Files\Microsoft VS Code\bin;C:\Program Files\Git\cmd;C:\Users\hilchenbachc\AppData\Local\Microsoft\WindowsApps;C:\Program Files\CMake\bin;C:\Users\hilchenbachc\AppData\Local\Programs\Microsoft VS Code\bin;C:\Program Files (x86)\Common Files\Hilscher GmbH\TLRDecode;C:\Users\hilchenbachc\AppData\Local\Microsoft\WindowsApps;C:\Program Files\CMake\bin;C:\Users\hilchenbachc\AppData\Local\Programs\Microsoft VS Code\bin;C:\Program Files (x86)\Common Files\Hilscher GmbH\TLRDecode;C:\Program Files\BRAutomation4\AS412\bin-en\4.12;C:\Program Files\BRAutomation4\AS412\bin-en\4.11;C:\Program Files\BRAutomation4\AS412\bin-en\4.10;C:\Program Files\BRAutomation4\AS412\bin-en\4.9;C:\Program Files\BRAutomation4\AS412\bin-en\4.8;C:\Program Files\BRAutomation4\AS412\bin-en\4.7;C:\Program Files\BRAutomation4\AS412\bin-en\4.6;C:\Program Files\BRAutomation4\AS412\bin-en\4.5;C:\Program Files\BRAutomation4\AS412\bin-en\4.4;C:\Program Files\BRAutomation4\AS412\bin-en\4.3;C:\Program Files\BRAutomation4\AS412\bin-en\4.2;C:\Program Files\BRAutomation4\AS412\bin-en\4.1;C:\Program Files\BRAutomation4\AS412\bin-en\4.0;C:\Program Files\BRAutomation4\AS412\bin-en
export AS_BUILD_MODE := Rebuild
export AS_VERSION := 4.12.6.106
export AS_WORKINGVERSION := 4.12
export AS_COMPANY_NAME := B&R Industrial Automation GmbH
export AS_USER_NAME := hilchenbachc
export AS_PATH := C:/Program Files/BRAutomation4/AS412
export AS_BIN_PATH := C:/Program Files/BRAutomation4/AS412/bin-en
export AS_PROJECT_PATH := C:/Projects/github/MyDiag/tools/AS/project
export AS_PROJECT_NAME := project
export AS_SYSTEM_PATH := C:/Program\ Files/BRAutomation4/AS/System
export AS_VC_PATH := C:/Program\ Files/BRAutomation4/AS412/AS/VC
export AS_TEMP_PATH := C:/Projects/github/MyDiag/tools/AS/project/Temp
export AS_CONFIGURATION := Config2
export AS_BINARIES_PATH := C:/Projects/github/MyDiag/tools/AS/project/Binaries
export AS_GNU_INST_PATH := C:/Program\ Files/BRAutomation4/AS412/AS/GnuInst/V6.3.0
export AS_GNU_BIN_PATH := C:/Program\ Files/BRAutomation4/AS412/AS/GnuInst/V6.3.0/4.9/bin
export AS_GNU_INST_PATH_SUB_MAKE := C:/Program Files/BRAutomation4/AS412/AS/GnuInst/V6.3.0
export AS_GNU_BIN_PATH_SUB_MAKE := C:/Program Files/BRAutomation4/AS412/AS/GnuInst/V6.3.0/4.9/bin
export AS_INSTALL_PATH := C:/Program\ Files/BRAutomation4/AS412
export WIN32_AS_PATH := "C:\Program Files\BRAutomation4\AS412"
export WIN32_AS_BIN_PATH := "C:\Program Files\BRAutomation4\AS412\bin-en"
export WIN32_AS_PROJECT_PATH := "C:\Projects\github\MyDiag\tools\AS\project"
export WIN32_AS_SYSTEM_PATH := "C:\Program Files\BRAutomation4\AS\System"
export WIN32_AS_VC_PATH := "C:\Program Files\BRAutomation4\AS412\AS\VC"
export WIN32_AS_TEMP_PATH := "C:\Projects\github\MyDiag\tools\AS\project\Temp"
export WIN32_AS_BINARIES_PATH := "C:\Projects\github\MyDiag\tools\AS\project\Binaries"
export WIN32_AS_GNU_INST_PATH := "C:\Program Files\BRAutomation4\AS412\AS\GnuInst\V6.3.0"
export WIN32_AS_GNU_BIN_PATH := "C:\Program Files\BRAutomation4\AS412\AS\GnuInst\V6.3.0\bin"
export WIN32_AS_INSTALL_PATH := "C:\Program Files\BRAutomation4\AS412"

.suffixes:

ProjectMakeFile:

	@'$(AS_BIN_PATH)/4.9/BR.AS.AnalyseProject.exe' '$(AS_PROJECT_PATH)/project.apj' -t '$(AS_TEMP_PATH)' -c '$(AS_CONFIGURATION)' -o '$(AS_BINARIES_PATH)'   -sfas -buildMode 'Rebuild'   

