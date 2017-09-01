#include<reg51.h>
sfr lcd = 0x80;
sbit RS = P2^0;
sbit RW = P2^1;
sbit EN = P2^2;
#include"delay.h"
#include"LCD.h"
main(){
	l_init();
	while(1){
		l_cmd(0x80+5);
		l_string("VECTOR");
		my_delay(1000);
		l_cmd(0x01);
		l_cmd(0x02);
		l_cmd(0xc0+3);
		l_string("BANGALORE");
		my_delay(1000);
	}
}
		