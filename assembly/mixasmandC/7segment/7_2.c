#include<reg51.h>
void delay(int i){
	unsigned char j;
	for(;i>0;i--){
			for(j=250;j>0;j--);
			for(j=247;j>0;j--);
	}
}
sfr se=0x80;
sbit s=P2^0;
sbit s1=P2^1;
sbit s2=P2^2;
sbit s3=P2^3;
code unsigned char l[4]={0x80,0xc0,0x92,0x92}; //ca
void digi(char i,char on,char off){
		P2=on;
		se=l[i];
		delay(2);
		P2=off;
	
}
main(){
	unsigned char k,i,j,on,off=0x0f,l1;
	s=s1=s2=s3=1;
	while(1){
			for(i=0;i<4;i++)
				for(j=0;j<250;j++)
					for(k=i,l1=0;k<=3;k++,l1++){
						on=~(1<<l1);
						digi(k,on,off);
					}
		}
}