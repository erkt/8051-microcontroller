//book-3
#include<reg51.h>
#include"delay.h"
sfr led=0xA0;
main(){
	unsigned char count=0,i;
	led = 0xf0;
	delay(1000);
	while(1){
		if(count < 5 ){
 			for ( i=0; i< 8;i++){
				if(i<4)
				led  = 0xf0|(1<<i);
				else
				led = ~(1<<i)&0xf0; 
			 	delay(1000*(i+1));
			}
			count ++;
			led = 0xf0;
			delay(3000);
		}
		else {
			led = 0xf0;
		}
	}
}

