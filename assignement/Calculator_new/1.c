#include<reg51.h>
sbit c0 = P2^0;  sbit c1 = P2^1;  sbit c2 = P2^2;  sbit c3 = P2^3;
sbit r0 = P2^4;  sbit r1 = P2^5;  sbit r2 = P2^6;  sbit r3 = P2^7;
sfr lcd = 0x80;  sbit RS = P3^4;  sbit RW = P3^5;  sbit EN = P3^6;
sbit sw = P1^0;
#include"delay.h"
#include"lcd.h"
#include"keypad.h"
main(){
	unsigned int dta[2],ans,sign,act[2],temp,ft,i,dt;
	l_init();
	dta[0]=dta[1]=ans=sign=act[0]=act[1]=ft=0;
	dt=1;
	l_string("   EXPRESSION   ");
	l_cmd(0xc0);
	while(1){
here:		while(sw==1);
		l_cmd(0x01);
		l_cmd(0x02);
		dta[0]=dta[1]=ans=sign=act[0]=act[1]=ft=temp=0;
		i=2;
		while(i){
					temp=keysearch();
					if(temp=='-'&&ft==0&&dt==1){
						ft=1;
						sign='-';
						l_data(temp);
					}
					else if(0<=temp && temp<=9){
					dta[i-1]=(dta[i-1]*10)+temp;
						l_data(temp+48);
						dt=0;
					}
					else {
						
						act[i-1]=temp;
						i--;
						if(temp=='=')
							i=0;
						l_data(temp);
					}				
		}
		if(act[1]=='+'&&ft){
			if(dta[1]>dta[0])
			ans=dta[1]-dta[0];
			else{
			ans=dta[0]-dta[1];
			ft=0;
			}
		}
		else if(act[1]=='+'&&ft==0)
			ans=dta[1]+dta[0];
		else if(act[1]=='-'&&ft)
			ans=dta[1]+dta[0];
		else if(act[1]=='-'&&ft==0){
			if(dta[1]<dta[0])
			ans=dta[0]-dta[1];
			else{
			ans=dta[1]-dta[0];
			ft=0;
			}
		}
		else if(act[1]=='*')
			ans=dta[1]*dta[0];
		else if(act[1]=='/'){
			if(dta[0]==0){
				l_string("Float Error..");
				goto here;
			}
			ans=act[1]/act[0];
		}
		else if(act[1]=='%'){
			ans = act[1]%act[0];
		}
		if(ft)
			l_data(sign);
		l_int(ans);
		
		
		
	}
}