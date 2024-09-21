TOP=../..

include $(TOP)/configure/CONFIG
#----------------------------------------
#  ADD MACRO DEFINITIONS AFTER THIS LINE
#=============================
USR_INCLUDES = -I$(USB_INCLUDE)
usb-1.0_DIR = $(USB_LIB)
USR_LIBS_Linux += usb-1.0

#LIBUSB=/reg/g/pcds/package/external/libusb-1.0.0

#=============================
# build an ioc application

PROD_IOC = reset_usb

reset_usb_SRCS += reset_usb.c

#USR_CPPFLAGS += -I$(LIBUSB)/include/libusb-1.0
#reset_usb_LDFLAGS += -L$(LIBUSB)/lib/x86_64-linux-dbg -Wl,-rpath,$(LIBUSB)/lib/$(ARCH)-linux-dbg -lusb-1.0
#reset_usb_LDFLAGS += -lusb-1.0

#===========================

include $(TOP)/configure/RULES
#----------------------------------------
#  ADD RULES AFTER THIS LINE

