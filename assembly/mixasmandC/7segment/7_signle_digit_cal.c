#include<reg51.h>
void my_delay(int i){
	unsigned char j;
	for(;i>0;i--){
			for(j=250;j>0;j--);
			for(j=247;j>0;j--);
	}
}
sbit c0 = P2^0;  sbit c1 = P2^1;  sbit c2 = P2^2;  sbit c3 = P2^3;
sbit r0 = P2^4;  sbit r1 = P2^5;  sbit r2 = P2^6;  sbit r3 = P2^7;
sfr se = 0x80;
sbit s=P1^0;
code unsigned char lut[]={0x40,0x79,0x24,0x30,0x19,0x12,0x02,0x78,0x00,0x10};
#include"keypad.h"
// void di(unsigned char te){
// 	unsigned char j;
// 		for(j=0;j<100;j++){
// 			P1=0xfe;
// 			se=lut[te];
// 			my_delay(2);
// 			P1=0xff;
// 		}
// }
main(){
	unsigned char d[2],a[2],temp,i=2,ans;
	unsigned char j;
	while(1){
		
			temp=keysearch(0);
				if(9>=temp&&temp<=0){
					d[1]=temp;
				}
			temp=keysearch(d[1]);	
				if(temp!='=')
					a[1]=temp;
			temp=keysearch('p');
				if(9>=temp&&temp<=0){
					d[0]=temp;
				}
			temp=keysearch(d[0]);	
				if(temp=='=')
					a[0]=temp;	
				
				if(a[0]=='='){
			if(a[1]=='+')
				ans=a[1]+a[0];
			else if(a[1]=='-')
				ans=a[1]-a[0];
			else if(a[1]=='*')
				ans=a[1]*a[0];
			else if(a[1]=='/')
				ans=a[1]/a[0];
		}
				for(j=0;j<200;j++){
					s=0;
					se=lut[ans];
					my_delay(2);
					s=1;
				}
		}
		
		while(1);
}