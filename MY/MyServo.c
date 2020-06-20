#include <avr/io.h>

void Servo_INIT(void)
{
    TCCR3A = (1 << COM3A1) | (1 << WGM11);
	TCCR3B = (1 << WGM33) | (1 << WGM32) | (1 << CS31) | (1 << CS30);
	ICR3 = 4999; // ICR1 set to TOP
	OCR3A = 375; // 0 degree
	TCNT3 = 0X00; // Strating point
   	DDRE = 0x08;
}
//125 ~ 725
void Servo_Motor(int degree)
{
    if      (degree < 125)      degree = 125;
    else if (degree > 725)      degree = 725;
    OCR3A = degree;
}