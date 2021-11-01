#include<unistd.h>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<libusb.h>

static int reset_usb(char *serial)
{
    int n = 0;
    libusb_context* pctx;
    libusb_device **list;
    unsigned char buf[1024];
    int i;

    libusb_init(&pctx);
    n = libusb_get_device_list(pctx, &list);
    for (i = 0; i < n; i++) {
        struct libusb_device_descriptor desc;
	libusb_device_handle *h;
        libusb_get_device_descriptor(list[i], &desc);
	if (libusb_open(list[i], &h))
	    continue;
	if (libusb_get_string_descriptor_ascii(h, desc.iSerialNumber, buf, sizeof(buf)) < 0)
	    continue;
	if (!serial) {
	    printf("%04x:%04x --> %s\n", desc.idVendor, desc.idProduct, buf);
	} else if (!strcmp((char*)buf, serial)) {
	    printf("Found %s, resetting.\n", serial);
	    libusb_reset_device(h);
	    libusb_close(h);
	    break;
	}
	libusb_close(h);
    }
    libusb_exit(pctx);
    return n;
}

int main(int argc, char **argv)
{
    reset_usb(argv[1]);
    return 0;
}
