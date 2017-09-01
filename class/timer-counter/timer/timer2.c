#include<reg51.h>
main(){
	TMOD = 0X02;
	TH0 = 255;
	TL0 = 1;
	TR0=1;
	while(TF0==0);
	TR0=TF0=0;
	while(1);
}