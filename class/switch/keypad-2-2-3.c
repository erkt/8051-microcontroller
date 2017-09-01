#include<reg51.h>
#include"delay.h"
#include"keypad.h"
main(){
	unsigned char temp;
	P2=0xf0;
	while(1){
		temp = keysearch();
		P2=temp;
	}
}