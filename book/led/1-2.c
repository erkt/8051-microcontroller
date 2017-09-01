//BOOK -1-2
#include<reg51.h>
#include"delay.h"
sfr led = 0xA0;
main(){
		unsigned char count=0;
		led=0x0f;
		while(1){
	   		/*if( count < 20){
	  			led  = ~ led;
				delay(1000);
				count++;
				}
			*/
			if( count <10){
				led = 0xf0;
				delay(1000);
				led =0x0f;
				delay(1000);
				count++;
	   		}
			else
				led = 0xf0;
		}
}