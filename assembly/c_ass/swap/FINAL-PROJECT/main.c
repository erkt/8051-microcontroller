#include<reg51.h>
#include"delay.h"
	unsigned char ss,mi,hh,d,dd,mm,yy,temp,FLAG=0,ALM=0;///read purpose
	sbit SDA = P1^0;
	sbit SCL = P1^1;

	sbit RS=P2^0; 
	sbit RW=P2^1;
	sbit EN=P2^2;

	sbit RST=P2^3;
	sbit CS2=P2^4;
	sbit CS1=P2^5;
#include"i2c.h"
#include"i2c_device.h"
#include"my_glcd.h"
#include"clock_set.h"
#include"clock_read.h"
#include"alarm.h"
//small lookuptable remain
void External_Interrupt(void) interrupt 0{
	FLAG=1;
}
main(){
	unsigned char HH,MM,D,DD,MO,YY,SS,i;
	dinit();
	for(i=PG0;i<PG6;i++)
		clrpage(i,3);

	/* sec min hour day date month year */
	clock_set(0x55,0x59,0x71,0x06,0x16,0x07,0x16);	
	string(" 7204204020 ");
	sdigit(0);
	while(1){
		gcmd(PG0,1);
		gcmd(ST_ADD,1);
		clock();
		alarm();
		clrscreen();	
		if(!FLAG){


			clock_set(SS,MM,HH,D,DD,MO,YY);
			alarm_set(HH,MM);
		}
	}
		
}																			