#include<reg51.h>
sbit sw = P1^0;
sfr led = 0xA0;
main(){
	unsigned char count=0;
	led= 0xf0;
	while(1){
		if(count < 4){
			if( sw == 0 ){
				led = (~(1 << (count+4) ) & 0xf0) ;
				count++	;
				while(sw ==0);
			}
			else
			continue;
		}
		else
			led = 0x00;
		}
}
