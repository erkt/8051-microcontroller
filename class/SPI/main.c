#include<reg51.h>
#include"delay.h"
sfr LCD = 0x80;
sbit RS = P3^4;
sbit RW = P3^5;
sbit EN = P3^6;
#include"lcd.h"
sbit clk  = P2^0;
sbit dout = P2^1;
sbit din  = P2^2;
sbit cs	  = P2^3;
#include"adc.h"
main(){
	unsigned int temp;
	ini();
	cmd(0x80);
	ldata('K');
	ldata(' ');
	inte(9090);	 
	while(1){
		temp = read();
		cmd(0xc0);
		floata((temp*0.0012));
		delay(100);
	}				  
}