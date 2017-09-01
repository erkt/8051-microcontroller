#include<reg51.h>
#include"delay.h"
#include"keypad.h"
main(){
	while(1){
		P0=key();
	}
}
