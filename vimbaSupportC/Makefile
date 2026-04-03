TOP=../
include $(TOP)/configure/CONFIG
#----------------------------------------
#  ADD MACRO DEFINITIONS AFTER THIS LINE
#=============================

INC += $(patsubst ../%, %, $(wildcard ../VmbC/*.h))
INC += $(patsubst ../%, %, $(wildcard ../VmbC/thirdparty/*.h))
INC += $(patsubst ../%, %, $(wildcard ../VmbImageTransform/*.h))
INC += $(patsubst ../%, %, $(wildcard ../Common/*.h))

# Note, the following files were manually copied from the Spinnaker distribution lib directories on Windows
# and from /usr/lib on Linux.
# SLAC Note: We're only using linux-x86_64, rhel7-x86_64, rhel9-x86_64 - also VimbaX removes 32bit support!
ifeq (windows-x64, $(findstring windows-x64, $(T_A)))
LIB_INSTALLS    += ../os/windows-x64/VmbC.lib
LIB_INSTALLS    += ../os/windows-x64/VmbImageTransform.lib
BIN_INSTALLS    += ../os/windows-x64/VimbaGigETL.cti
BIN_INSTALLS    += ../os/windows-x64/VimbaGigETL.xml

else ifeq (linux-x86_64, $(findstring linux-x86_64, $(T_A)))
LIB_INSTALLS    += ../os/linux-x86_64/libVmbC.so
LIB_INSTALLS    += ../os/linux-x86_64/libVmbImageTransform.so
LIB_INSTALLS    += ../os/linux-x86_64/libGCBase_GNU8_4_0_v3_2_AVT.so
LIB_INSTALLS    += ../os/linux-x86_64/libGenApi_GNU8_4_0_v3_2_AVT.so
LIB_INSTALLS    += ../os/linux-x86_64/liblog4cpp_GNU8_4_0_v3_2_AVT.so
LIB_INSTALLS    += ../os/linux-x86_64/libLog_GNU8_4_0_v3_2_AVT.so
LIB_INSTALLS    += ../os/linux-x86_64/libMathParser_GNU8_4_0_v3_2_AVT.so
LIB_INSTALLS    += ../os/linux-x86_64/libNodeMapData_GNU8_4_0_v3_2_AVT.so
LIB_INSTALLS    += ../os/linux-x86_64/libXmlParser_GNU8_4_0_v3_2_AVT.so
BIN_INSTALLS    += ../os/linux-x86_64/VimbaUSBTL.cti
BIN_INSTALLS    += ../os/linux-x86_64/VimbaUSBTL.xml
BIN_INSTALLS    += ../os/linux-x86_64/VimbaGigETL.cti
BIN_INSTALLS    += ../os/linux-x86_64/VimbaGigETL.xml

else ifneq (, $(findstring rhel, $(T_A)))
LIB_INSTALLS    += ../os/linux-x86_64/libVmbC.so
LIB_INSTALLS    += ../os/linux-x86_64/libVmbImageTransform.so
LIB_INSTALLS    += ../os/linux-x86_64/libGCBase_GNU8_4_0_v3_2_AVT.so
LIB_INSTALLS    += ../os/linux-x86_64/libGenApi_GNU8_4_0_v3_2_AVT.so
LIB_INSTALLS    += ../os/linux-x86_64/liblog4cpp_GNU8_4_0_v3_2_AVT.so
LIB_INSTALLS    += ../os/linux-x86_64/libLog_GNU8_4_0_v3_2_AVT.so
LIB_INSTALLS    += ../os/linux-x86_64/libMathParser_GNU8_4_0_v3_2_AVT.so
LIB_INSTALLS    += ../os/linux-x86_64/libNodeMapData_GNU8_4_0_v3_2_AVT.so
LIB_INSTALLS    += ../os/linux-x86_64/libXmlParser_GNU8_4_0_v3_2_AVT.so
BIN_INSTALLS    += ../os/linux-x86_64/VimbaGigETL.cti
BIN_INSTALLS    += ../os/linux-x86_64/VimbaGigETL.xml
BIN_INSTALLS    += ../os/linux-x86_64/VimbaUSBTL.cti
BIN_INSTALLS    += ../os/linux-x86_64/VimbaUSBTL.xml
endif

#=============================

include $(TOP)/configure/RULES
#----------------------------------------
#  ADD RULES AFTER THIS LINE

