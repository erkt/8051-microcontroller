#include<reg51.h>
sfr LCD = 0x80;
sbit RS = P3^4;
sbit RW = P3^5;
sbit EN = P3^6;
#include"lcd.h"
void external() interrupt 0{
	   cmd(0xc0);
	   string("Ex interrupt...");
}
main(){
		EA=EX0=1;
		IT0=0;	
	  ini();
		while(1){
		cmd(0x80);
		string("MAIN......");
		delay(1000);
		cmd(0x01);
		}
}