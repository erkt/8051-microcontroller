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
void digit(char n){
	if(n==0){
		s=0;
		se=l[n];
		delay(2);
		s=1;
	}
	else if(n==1){
		s1=0;
		se=l[n];
		delay(2);
		s1=1;
	}
	else if(n==2){
		s2=0;
		se=l[n];
		delay(2);	
		s2=1;
	}
	else if(n==3){
		s3=0;
		se=l[n];
		delay(2);
		s3=1;
	}
}
main(){
	unsigned char i,j,k;
	s=s1=s2=s3=1;
	while(1){
		for(k=0;k<4;k++){
			for(j=0;j<250;j++){
				for(i=0;i<=k;i++)
					digit(i);
			}
		}
		for(k=4;k>0;k--)
			for(j=0;j<250;j++){
				for(i=4;i>=k;i--)
					digit(i-1);
			}
	}
}