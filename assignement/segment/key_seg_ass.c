#include<reg51.h>
#include"delay.h"
#include"keypad.h"
#include"segment.h"
main(){
	unsigned char t,i;
	while(1){
		
		t=keysearch();
		for(i=250;i>0;i--)
		seg(t);
	}
}
		