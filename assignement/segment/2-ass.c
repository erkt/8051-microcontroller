#include<reg51.h>
#include"delay.h"
sfr se = 0x80;
sbit s1=P2^0;
sbit s2=P2^1;
sbit s3=P2^2;
sbit s4=P2^3;
code unsigned char b[4][4]={0x03,0x40,0x12,0x12,//boss
						0xc6,0x40,0xc7,0xa1,//cold
						0x12,0x40,0xa1,0x88,//soda
						0x89,0x86,0xc7,0x8c//help
						};
main(){
	unsigned char i,j;
	   while(1){ 
		   for(i=0;i<4;i++)	{
		   		for(j=125;j>0;j--){
		   			s1=0;s2=s3=s4=1;
		   			se=b[i][0]|0x80;
		   			my_delay(2);
		   			s2=0;s1=s3=s4=1;
		   			se=b[i][1]|0x80;
		   			my_delay(2);
		   			s3=0;s2=s1=s4=1;
		   			se=b[i][2]|0x80;
		   			my_delay(2);
		   			s4=0;s2=s3=s1=1;
		   			se=b[i][3]|0x80;
		   			my_delay(2);
		   		}
		   }
	  }
}
	
	
