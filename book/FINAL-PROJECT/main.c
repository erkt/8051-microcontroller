#include<reg51.h>
#include"delay.h"
	unsigned char FLAG=0,ALM=0;

	sbit C0=P1^0;sbit C1=P1^1;sbit C2=P1^2;sbit C3=P1^3;
	sbit R0=P1^4;sbit R1=P1^5;sbit R2=P1^6;sbit R3=P1^7;

	sbit SDA = P3^6;	sbit SCL = P3^7;

	sbit RS=P2^0; sbit RW=P2^1; sbit EN=P2^2;

	sbit RST=P2^3; sbit CS2=P2^4; sbit CS1=P2^5;

#include"i2c.h"
#include"i2c_device.h"
#include"my_glcd.h"
#include"clock_set.h"
#include"clock_read.h"
#include"alarm.h"
#include"keypad.h"
#include"A_N_C_set.h"
//small lookuptable remain
void External_Interrupt() interrupt 0{
	FLAG=1;
}
main(){
	//unsigned char HH,MM,D,DD,MO,YY,SS,i,k=1,temp,count=0;
	
	unsigned char i,k=1,count=0;
	EA=EX0=1;
		IT0=0;
	dinit();
	for(i=PG0;i<PG6;i++)
		clrpage(i,3);
	/* sec min hour day date month year */
	clock_set(0x55,0x59,0x71,0x01,0x16,0x07,0x16);	
	while(1){
		gcmd(PG0+1,1);
		gcmd(ST_ADD,1);
		clock();
		alarm();
		if(FLAG){
			set_clock();		
		}
	}	
	while(1);	
}																			