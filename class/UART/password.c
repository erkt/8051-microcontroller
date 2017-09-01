#include<reg51.h>
#include<string.h>
#include"uart.h"
sfr LCD =0x80;
sbit RS = P3^4;
sbit RW = P3^5;
sbit EN = P3^6;
#include"lcd.h"
main(){
	unsigned char buf[11],i,temp,pass[]="krezzy",l;
	linit();
	uart_inti();
		i=0;
		lstring("Enter Password:");
		uart_tx_string("Enter Password:");
		lcmd(0xc0);
		while((temp=uart_rx())!='\x0D'){
			buf[i++]=temp;
			uart_tx('*');
			ldata('*');
		}
		
		buf[i]=0;
		l=i;
		lcmd(0x01);lcmd(0x02);
		for(i=0;buf[i];i++)
		if(buf[i]!=pass[i])
			break;
		if(l==i){
			uart_tx_string("login Correct.");
			lstring("Correct login.");
			while(1){
			P1=0xff;
			delay(500);
			P1=0x00;
			delay(500);
			}
		}
		else{
			uart_tx_string("WRONG Pass.");
			lstring("WRONG Pass.");
		}
	while(1);
}