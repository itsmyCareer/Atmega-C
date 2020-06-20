void bluetooth_Init(void)
{
	UCSR0A = 0x00;
	UCSR0B = 0x98;
	UCSR0C = 0x06;
	UBRR0H = 0x00;
	UBRR0L = 103;
}
char bluetooth_Rx(void)
{
	while((UCSR0A & 0x80) == 0);
	return UDR0;
}