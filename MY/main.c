#define F_CPU 16000000UL
#include <avr/io.h>
#include "MyBluetooth.h"

int main(void)
{
	char rx_txt;
	bluetooth_Init();
	
    while (1) 
    {
		rx_txt = bluetooth_Rx();
		switch(rx_txt)
		{
			case "1":
				break;
			case "2":
				break;
			case "3":
				break;
			case "4":
				break;
		}
    }
}

