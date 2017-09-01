void uart_inti(){
	SCON = 0x50;
	TMOD = 0x20;
	TH1 = 253;
	TR1 =1;
}
void uart_tx(unsigned char DATA){
	SBUF = DATA;
	while(TI == 0);
	TI = 0;
}
unsigned char uart_rx(){
	while(RI == 0 );
	RI = 0;
	return SBUF;
}
void uart_tx_string(char *s){
	while(*s)
		uart_tx(*s++);
}