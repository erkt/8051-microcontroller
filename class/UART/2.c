#include<reg51.h>
#include"uart.h"
main(){
	uart_inti();
	uart_tx_string("OOOOOOOOOMC");
	while(1);
}