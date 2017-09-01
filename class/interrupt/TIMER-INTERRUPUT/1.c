#include<reg51.h>
sfr lcd = 0x80;
sbit rs = P3^4;
sbit rw = P3^5;
sbit en = P3^6;
#include"lcd.h"
static unsigned int count=0;
void timerinter() interrupt 1{
	 cmd(0xc0);
	 string("EX::");
	 cmd(0xc0+4);
	 inti(count++);
}
main(){
	unsigned int i=0;
	TMOD = 0X01;
	TH0 = (15535>>8);
	TL0 = (15535&0XFF);
	TR0 = 1;
	ET0 = EA = EX0 = 1;
	IT0 = 0;
 	ini();
	while(1){
		string("Main::");
		cmd(0x80+6);
		inti(i);
		i++;
		delay(500);
		cmd(0x01);
		cmd(0x02);
	}
} 