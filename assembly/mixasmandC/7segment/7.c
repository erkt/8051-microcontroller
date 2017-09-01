#include<reg51.h>
sfr seg=0x80;
sbit s1 = P2^0;
sbit s2 = P2^1;
sbit s3 = P2^2;
sbit s4 = P2^3;
void delay(int i){
	unsigned char j;
	for(;i>0;i--){
		for(j=250;j>0;j--);
		for(j=247;j>0;j--);
	}
}
code unsigned char l[][4]={0x80,0xc0,0x92,0x92, //ca
													 0x83,0xa3,0x92,0x92};
main(){
	unsigned char i,j,k,l1;
	while(1){
	for(i=0;i<2;i++){
		for(k=0;k<100;k++){
			for(j=0;j<4;j++){
				for(k=0;k<250;k++)
				if(j<1){
					s1=0;s2=s3=s4=1;
					seg=l[i][j];
					delay(2);
				}
				for(k=0;k<250;k++)
				if(j<2&&j!=0){
					
					s1=0;s2=s3=s4=1;
					seg=l[i][j-1];
					delay(2);
					s2=0;s1=s3=s4=1;
					seg=l[i][j];
					delay(2);
				}
				
				for(k=0;k<160;k++)
				if(j<3&&j!=1&&j!=0){
					s1=0;s2=s3=s4=1;
					seg=l[i][j-2];
					delay(2);
					s2=0;s1=s3=s4=1;
					seg=l[i][j-1];
					delay(2);
					s3=0;s1=s2=s4=1;
					seg=l[i][j];
					delay(2);
				}
				for(k=0;k<125;k++)
				if(j<4&&j!=2&&j!=1&&j!=0){
					s1=0;s2=s3=s4=1;
					seg=l[i][j-3];
					delay(2);
					s2=0;s1=s3=s4=1;
					seg=l[i][j-2];
					delay(2);
					s3=0;s1=s2=s4=1;
					seg=l[i][j-1];
					delay(2);
					s4=0;s1=s2=s3=1;
					seg=l[i][j];
					delay(2);
				}
			}
		}
	}
}
}
