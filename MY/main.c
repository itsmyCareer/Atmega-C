#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include "MyBluetooth.h"
#include "MYDC.h"
#include "MYServo.h"

int main(void)
{
	char rx_txt;
	int cnt = 125, toggle = 0;
	bluetooth_Init();
	DC_INIT();
	Servo_INIT();

	while (1) 
    {
		rx_txt = bluetooth_Rx();
		switch(rx_txt)
		{
			case "1":
				DC_Motor(30);
				toggle = 1;
				break;
			case "2":
				DC_Motor(60);
				toggle = 2;
				break;
			case "3":
				DC_Motor(100);
				toggle = 3;
				break;
			case "4":
				toggle = 4;
				break;
		}
		
		while(!(UCSR1A & 0x80))
		{
			if(toggle != 4)
			{
				Servo_Motor(cnt++);
				_delay_ms(4);
				if(cnt > 725)	cnt = 125;
			}
		}
    }

}

