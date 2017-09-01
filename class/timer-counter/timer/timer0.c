#include<reg51.h>
main(){
	 TMOD = 0x00;
	 TH0 = 0XE0;
	 TL0 = 0X17;
	TR0=1;
	while(TF0==0);
	TR0=0;
	TF0=0;
	while(1);
}