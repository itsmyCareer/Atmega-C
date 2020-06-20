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
		if(rx_txt == "1")
		{
			DC_Motor(30);
			toggle = 1;
		}
		else if(rx_txt == "2")
		{
			DC_Motor(60);
			toggle = 2;
		}
		else if(rx_txt == "3")
		{
			DC_Motor(100);
			toggle = 3;
		}
		else if(rx_txt == "4")
		{
			toggle = 4;
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

