#include<reg51.h>
#include"UART.h"
sfr lcd = 0x80;
sbit RS =P3^4;
sbit RW =P3^5;
sbit EN =P3^6;
unsigned char hexv[]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
#include"lcd.h"
main(){
	unsigned char t,j,a;
	uart_init();
	linit();
	while(1){
		t=uart_rx();
		lcmd(0x01);
		lcmd(0x02);
		ldata(t);
		ldata(' ');
		j=t^(1<<5);
		ldata(j);
		ldata(' ');
		///convert decimal ascii
		a=t;
		if(a>99){
		ldata(hexv[(a/100)]);
		a=a%100;
		}
		ldata(hexv[(a/10)]); 
		ldata(hexv[(a%10)]); 
		ldata('d');
		ldata(' ');
		///convert hex ascii
		ldata(hexv[(t/16)]);
		ldata(hexv[(t%16)]);
        ldata('H');
		ldata(' ');
		
}
}
