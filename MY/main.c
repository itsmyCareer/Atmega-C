#define F_CPU 16000000UL
#include <avr/io.h>
#include "MyBluetooth.h"
#include "MYDC.h"
#include "MYServo.h"

int main(void)
{
	char rx_txt;
	bluetooth_Init();
	DC_INIT();
    while (1) 
    {
		rx_txt = bluetooth_Rx();
		switch(rx_txt)
		{
			case "1":
				DC_Motor(30);
				break;
			case "2":
				DC_Motor(60);
				break;
			case "3":
				DC_Motor(100);
				break;
			case "4":
				break;
		}
    }
}

