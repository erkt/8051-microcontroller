#include<reg51.h>
#include<string.h>
sfr lcd = 0x80;
sbit RS = P3^4;
sbit RW = P3^5;
sbit EN = P3^6;
#include"delay.h"
#include"LCD.h"
main(){
	char i,len,l,len1,l1;
	char *s="Krezzy :: 7204204020";
	char *p="->->crezzy<-<-";

// char *s="abcdef ghijkl mnopqur stuvwx yz ";
// char *p="7204204020";

	len=strlen(s);
	len1=strlen(p);
	l_init();	

	while(1){
		l=len;
		l1=len1;
		if(len>15){
			for(i=0;i<len;i++){
				l_cmd(0x80+i);
				l_string(s);
				if(i<len1){
				l_cmd(0xc0+i);
				l_string(p);
				}
				my_delay(1000);
				l_init();
				if((i+l)==(len)){
					l_cmd(0x80);
					l_string(s+(l--));
					if(i<len1){
					l_cmd(0xc0);
					l_string(p+(l1--));
				}
			}
			}
		}
		else{
			for(i=0;i<16;i++){
				l_cmd(0x80+i);
				l_string(s);
				l_cmd(0xc0+i);
				l_string(p);
				my_delay(1000);
				l_init();
				if((i+l)==15){
					l_cmd(0x80);
					l_string(s+(l--));
					l_cmd(0xc0);
					l_string(p+(l1--));
				}
			}
		}
	}
}

