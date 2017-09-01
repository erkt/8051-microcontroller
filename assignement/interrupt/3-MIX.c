#include<reg51.h>
sfr LCD = 0x80;
sbit RS = P3^4;
sbit RW = P3^5;
sbit EN = P3^6;
sbit L = P1^0;
sbit L1 = P1^7;
sbit L2 = P1^4;
#include"lcd.h"
unsigned char lo[]={0x00,0x11,0x1B,0x0E,0x0E,0x1B,0x11,0x00};
unsigned char dat[32];
static char i=0,count;
void UART(void) interrupt 4{

 if(TI==1){
   	if(i!=count){
   		SBUF=dat[i++];
   		L2=~L2;
   	}
   	else{
   		lcmd(0x80);
   		lstring(">> DATA TX <<");
		i=count=0;
   	}
	TI=0;
 }
 if(RI==1){
	if(SBUF != '\x0D'){
		dat[i++]=SBUF;
		L1=~L1;
	}
	else{
		lini();
		lcmd(0xc0);
		dat[i]=0;
	  	lstring(dat);
		lcmd(0xc0+i+1);
		ldata(0);
		count=i;
	  	i=0;
		SBUF=dat[i++];
	}
	RI=0;
 }
}
main(){
		SCON = 0x50;
		TMOD = 0x20;
		TH1=TL1=253;
		TR1=1;
		EA=ES=1;
		lini();
		lcg(lo,8);
		while(1){
			L=~L;
			delay(200);
		}	
}