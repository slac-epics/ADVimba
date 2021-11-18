TOP=../..

include $(TOP)/configure/CONFIG
#----------------------------------------
#  ADD MACRO DEFINITIONS AFTER THIS LINE
#=============================

#=============================
# build an ioc application

PROD_IOC = ListCameras

USR_CFLAGS += -DBINPATH=\"$(shell pwd)/../../../bin/$(T_A)\"

ListCameras_SRCS += ListCameras.c program.c PrintVimbaVersion.c DiscoverGigECameras.c

PROD_SYS_LIBS_Linux += VimbaC

#===========================

include $(TOP)/configure/RULES
#----------------------------------------
#  ADD RULES AFTER THIS LINE

