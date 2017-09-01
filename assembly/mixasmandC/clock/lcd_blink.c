#include<reg51.h>
sfr lcd = 0x80;
sbit RS=P3^4;
sbit RW=P3^5;
sbit EN=P3^6;
#include"lcd.h"
main(){
	unsigned char *p="PAGAL",*s="KING";
	ini();
	string(p);
	lcmd(0xc0);
	while(1){
		delay(1000);
		string(s);
		delay(1000);
		lcmd(0x08);
		
	}

}	