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
		l_data('a');
		my_delay(2000);
	}
}