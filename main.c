#include<stdio.h>
#include <libusb-1.0/libusb.h>
#include <stdlib.h> // for exit

#define readEndpointAddress     0x81  //EP 1 IN
#define writeEndpointAddress     0x01  //EP 1 OUT

#define wMaxPacketSize     0x0020  //1x 32 bytes

#define deviceVendorID 		 	0x045e  //Microsoft Corp.
#define   deviceProductID		0x028e //Xbox360 Controller


int sendData(unsigned char sendData[],libusb_device_handle *handler,int size);
uint8_t* receiveData(libusb_device_handle *handler,int size);

int main(int argc, char *argv[])
{
	int argCount = argc;
	uint8_t message = 0x0A;
	char* s1=argv[1];
	char* s2=argv[2];
	switch(argCount){
		case 2:
			if(s2 != NULL){
					
			}

	}
	libusb_init(NULL);
	libusb_device_handle *h =NULL;
	unsigned char data[] = { 1, 3,message};
	unsigned char rumble[] = {0x0,0x8,0x0,0xFF,0xFF,0x0,0x0,0x0};
	unsigned char receive[20];
	h = libusb_open_device_with_vid_pid(NULL,deviceVendorID, deviceProductID);
	if (h != NULL) {
		
		while(1)
			{
				int received;
				int r = libusb_interrupt_transfer(h, readEndpointAddress ,receive,sizeof(receive), &received, 0);				
				if(r == 0)
					for(int i=1;i<9;i++){
						printf("%x \t",receive[i]);
					}
					printf("\n");
			}					
	}
	libusb_close(h);
    libusb_exit(NULL);
    return 0;
}
int sendData(unsigned char sendData[],libusb_device_handle *handler,int size){
	int transferred;
	int send_status = libusb_interrupt_transfer(handler, writeEndpointAddress ,sendData,size, &transferred, 0);
		if(send_status == 0 )
			printf("Done sending data");
		else
			printf("Failed sending");
	return send_status;			
}
uint8_t* receiveData(libusb_device_handle *handler,int size){
		uint8_t* receive=malloc(sizeof(uint8_t)*20);
		int received;
		int r = libusb_interrupt_transfer(handler, readEndpointAddress ,receive,sizeof(receive), &received, 0);				
		if(r == 0)
			return receive;
		return NULL;
			
}