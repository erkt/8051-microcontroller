#include<reg51.h>
sbit sw = P1^0;
sfr led = 0x80; 
main(){
	led = 0x0f;
	while(1){
		if(sw == 0){
			led=0xf0;
			while(sw==0);
		}
		else
			led=0x0f;
	}
}