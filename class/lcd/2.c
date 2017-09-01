#include<reg51.h>
sfr lcd = 0x80;
sbit RS = P2^0;
sbit RW = P2^1;
sbit EN = P2^2;
#include"delay.h"
#include"LCD.h"
main(){
	l_init();
	
		
		l_string("VECTOR");
		l_cmd(0xc0);
		l_string("BANGALORE");
	while(1);
}
		