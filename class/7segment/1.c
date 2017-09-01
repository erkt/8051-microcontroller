#include<reg51.h>
#include"delay.h"
sfr led=0xA0;
code unsigned char look[]={0x40,0x79,0x24,0x30,0x19,0x12,0x02,0x78,0x00,0x10};
main(){
	int i;
	P1=0x00;
	while(1){
		for(i=0;i<10;i++){
			led=look[i];
			my_delay(1000);
		}
	}
}