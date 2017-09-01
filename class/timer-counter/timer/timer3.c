#include<reg51.h>
main(){
	TMOD = 0x03;
	TH0 = 155;
	TL0 = 100;
	TR0 = 1;
	TR1 = 1;
	while((TF0 == 0)||(TF1==0));
	TR0=TR1=0;
	TF0=TF1=0;
	while(1);
}