#include<reg51.h>
sbit c0 = P2^0;  sbit c1 = P2^1;  sbit c2 = P2^2;  sbit c3 = P2^3;
sbit r0 = P2^4;  sbit r1 = P2^5;  sbit r2 = P2^6;  sbit r3 = P2^7;
sfr lcd = 0x80;  sbit RS = P3^4;  sbit RW = P3^5;  sbit EN = P3^6;
sbit sw = P1^0;
#include"delay.h"
#include"lcd.h"
#include"keypad.h"
main(){
	unsigned char temp,i=4,op,action[2]={0,0},fl;
	int j[2]={0,0},l=0,ans;
	l_init();
	l_string("Expression");
	l_cmd(0xc0);
	while(1){
		while(sw==1);
		while(i){
		    temp=keysearch();			
			if(temp>=0 && temp<=9){
				l = (l*10)+ temp;
				l_data(temp+48);
			}
			else {
				op=temp;
				l_data(op);
				action[--i]=op;
				j[i]=l;
				l=0;
			}
		}
		 if(action[1]=='+')		
			 l=j[1]+j[0];
		 else if(action[1]=='-') {
			 l=j[1]-j[0];
		 	 if( l & 1<<7)
			 	fl = 1;
			else 
				fl =0;
		 }
		 else if(action[1]=='*')
			l=j[1]*j[0];
 		 else if(action[1]=='/'){
			 if(j[0]==0)
		 		l_string("Error..Floating pt ");
		 	 else
				l=j[1]/j[0];
		}
		 else if(action[1]=='%')
			l=j[1]%j[0];
			if(fl ==1)
				l_data('-');				
		 l_int(l);
		 i=2;
		 while(sw==1);
		 l_cmd(0x01);
		 temp=0;j[0]=0;j[1]=0;action[1]=0;action[0]=0;l=0;op=0;
	}	 	
	while(1);
}