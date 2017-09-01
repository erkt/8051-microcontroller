#include<reg51.h>
#include"delay.h"
sbit s3=P2^3;
sbit s2=P2^2;
sbit s1=P2^1;
sbit s=P2^0;
sfr led = 0x80;
#define NN 2
code unsigned char look[]={0x40,0x79,0x24,0x30,0x19,0x12,0x02,0x78,0x00,0x10};
main(){
	int num,k,temp;
	P2=0xff;
	while(1){
			for(num=00;num<10000;num++){
				for(k=250	;k>0;k--){
					s=0;s1=s2=s3=1;
					P0=look[num/1000];
					my_delay(NN);
					temp=num%1000;
					s1=0;s=s2=s3=1;
					P0=look[temp/100];
					my_delay(NN);
					temp=num%100;
					s2=0;s=s1=s3=1;
					P0=look[temp/10];
					my_delay(NN);
					s3=0;s=s1=s2=1;
					P0=look[temp%10];
					my_delay(NN);
					
				}
			}
		}
	}
