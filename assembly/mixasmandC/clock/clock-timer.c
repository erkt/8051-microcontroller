#include<reg51.h>
sfr lcd = 0x80;
sbit RS = P3^4;
sbit RW = P3^5;
sbit EN = P3^6;
#include"lcd.h"
void delay_timer(unsigned char i){
	while(i--){
	TMOD = 0x01;
	TH0= (15535>>8);
	TL0= (15535&0x0f);
	TR0=1;
	while(TF0==0);
	TR0=TF0=0;
	}
}
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
					if(hou>12){
						ldata('P');
						ldata('M');
					}
					else{
						ldata('A');
						ldata('M');
					}
					delay_timer(20);
					lcmd(0x01);
					lcmd(0x02);
					
				}
			}
}