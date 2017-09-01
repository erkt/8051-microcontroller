#include<reg51.h>
#include"uart.h"
main(){
	unsigned char i,buff[11];
	inti();
	while(1){
	for(i=0;i<11;i++)
	buff[i]=rx();
	buff[i]='\0';
	str(buff);
		
	}
		while(1);
}