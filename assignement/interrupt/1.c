#include<reg51.h>
sfr LCD = 0x80;
sbit RS = P3^4;
sbit RW = P3^5;
sbit EN = P3^6;
#include"lcd.h"
unsigned char p[35];
static unsigned char count=0;
void UART_ISR(void) interrupt 4{
	if(TI==1){
		TI=0;		
	}
	if(RI==1){
		if(SBUF!='\x0D')
		p[count++]=SBUF;
		else
		if(count<35)
		{
		    lcmd(0x01);
			lcmd(0x02);	
			lstring(p);
			count=0;
		}
		RI=0;
	}
}
main(){
	lini();
	SCON = 0X50;
	TMOD = 0X20;
	TH1=TL1=253;
	TR1=1;
	EA=ES=1; 
	while(1){
	}		 
}
	