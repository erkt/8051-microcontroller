	#include<reg51.h>
	sbit sw=P2^0;
	sbit sw1=P2^1;
	sbit led=P1^0;
	#define on 0
	#define off 1
	main(){
		 while(1){
		// led=((sw==0)&(sw1==0))	;
			if((sw==on) & (sw1==on))
			led=1;
			else
			led=0;

		 }
 }