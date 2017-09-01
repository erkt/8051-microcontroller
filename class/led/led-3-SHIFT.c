#include<reg51.h>
#include"delay.h"
main(){
	unsigned char i;
	while(1){
		for(i=0;i<8;i++){
			P2=(1<<i);
			my_delay(1000);
		}
	}
}