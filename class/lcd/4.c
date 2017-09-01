#include<reg51.h>
#include<string.h>
sfr lcd = 0x80;
sbit RS = P3^4;
sbit RW = P3^5;
sbit EN = P3^6;
#include"delay.h"
#include"LCD.h"
main(){
	char i,len,l;
	//char *s="Krezzy :: 7204204020";
	char *s="ABCDEFGHIJKLMNOPQRSTUVWXYZ" ;
	len=strlen(s);
	l_init();	
	
	while(1){
		l=len;
		if(len>15){
		for(i=0;i<len;i++){
			l_cmd(0x80+i);
			l_string(s);
			
			my_delay(1000);
			l_cmd(0x01);
			l_cmd(0x02);
			if((i+l)==(len)){
				l_cmd(0x80);
				l_string(s+(l--));
			}
		}
		}
		else{
		for(i=0;i<16;i++){
			l_cmd(0x80+i);
			l_string(s);
			my_delay(1000);
			l_cmd(0x01);
			l_cmd(0x02);
			if((i+l)==15){
				l_cmd(0x80);
				l_string(s+(l--));
			}
		}
		}
	}
}
		
