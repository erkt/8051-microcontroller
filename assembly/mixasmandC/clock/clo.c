#include<reg51.h>
sfr lcd = 0x80;
sbit RS = P3^4;
sbit RW = P3^5;
sbit EN = P3^6;
#include"lcd.h"
main(){
	unsigned char sec,min,hou;
ini();
	while(1){
		for(hou=0;hou<24;hou++)
			for(min =0; min<60;min++)
				for(sec =0; sec <60;sec++){
					lint(hou);
						ldata(':');
					lint(min);
					ldata(':');
					lint(sec);
					delay(1000);
					lcmd(0x01);
					lcmd(0x02);
				}
			}
}