#include<reg51.h>
#include"UART.h"
sfr lcd = 0x80;
sbit RS =P3^4;
sbit RW =P3^5;
sbit EN =P3^6;
#include"lcd.h"
main(){
	unsigned char t,j,aa='A';
	uart_init();
	linit();
	while(1){
		t=uart_rx();
		uart_tx(t);
		lcmd(0x01);
		lcmd(0x02);

		ldata(t);
		ldata(' ');
		j=t^(1<<5);
		uart_tx(j);
		ldata(j);
		ldata(' ');
		///convert decimal ascii
		uart_tx(t/10+48);
		ldata(t/10+48);
		uart_tx(t%10+48);
		ldata(t%10+48);
		ldata('d');
		ldata(' ');
		///convert hex ascii
		uart_tx(t/16+48);
		ldata(t/16+48);
		if((t%16)>9){
			if((t%16)==10){
			uart_tx(aa+0);
			ldata(aa+0);
			}
			else if((t%16)==11){
			uart_tx(aa+1);
			ldata(aa+1);
			}
			else if((t%16)==12){
			uart_tx(aa+2);
			ldata(aa+2);
			}
			else if((t%16)==13){
			uart_tx(aa+3);
			ldata(aa+3);
			}
			else if((t%16)==14){
			uart_tx(aa+4);
			ldata(aa+4);
			}
			else if((t%16)==15){
			uart_tx(aa+5);
			ldata(aa+5);
			}
		}
		else
		{
		uart_tx(t%16+48);
		ldata(t%16+48);
		}
		uart_string("H\r\n");
		ldata('H');
		ldata(' ');
}
}
