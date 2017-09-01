#include<reg51.h>
#include"uart.h"
main(){
	unsigned char t;
	uart_inti();
	
	while(1){
		//t=uart_rx();
		uart_tx(uart_rx());	
	}
}