#include<reg51.h>
#include"delay.h"
sfr seg = 0x80;
sbit s0 =P2^0;
sbit s1 =P2^1;
sbit s2 =P2^2;
sbit s3 =P2^3;
unsigned char look[]={ 0x40,0x79,0x24,0x30,0x19,0x12,0x02,0x78,0x00,0x10};

main(){
	unsigned char sec,min,i;
	while(1){
	for(min=0;min<60;min++)	
	for(sec=0;sec<60;sec++){
		for(i=0;i<125;i++){
		s0=0;s1=s2=s3=1;
		seg=look[(sec%10)];
		delay(2);
		s1=0;s0=s2=s3=1;
		seg=look[(sec/10)];
		delay(2);
		
		s2=0;s1=s1=s3=1;
		seg=look[(min%10)];
		delay(2);
		
		s3=0;s1=s2=s2=1;
		seg=look[(min/10)];
		delay(2);
		}
		
	}
}
}
	
	