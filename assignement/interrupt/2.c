#include<reg51.h>
sfr LCD = 0x80;
sbit RS = P3^4;
sbit RW = P3^5;
sbit EN = P3^6;
#include"lcd.h"
unsigned char p[11],p1[11]="7204204020";
static unsigned char count=0,j=0,temp=0;
void UART_ISR(void) interrupt 4{
	if(TI==1){
		if(j==temp){
		    lcmd(0x01);
			lcmd(0xc0);
			lstring(">DATA TRANSFER<");
			temp=0;
		}
		TI=0;		
	}
	if(RI==1){
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
	for(j=0;p1[j];j++);
	while(1){
		lcmd(0x80);
		lstring("PRO.....");
		SBUF=p1[temp++];
	}
}
	