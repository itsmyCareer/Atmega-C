#include <avr/io.h>

void DC_INIT(void)
{
	DDRB=0x60;			// PINB5, 6
	TCCR1A=0x82;
	TCCR1B=0x1A;
	OCR1A=0;
}
void DC_Motor(int speed)
{
	if(speed<  0) speed=  0;
	if(speed>100) speed=100;
	OCR1A=speed;
}