#include<reg51.h>
main(){
	unsigned char temp;
	TMOD = 0x04;
	TH0=TL0=0;
	TR0=1;
	while(TF0==0){
		temp = TH0 *32 +TL0;  ///if counter 0   and counter 1 =256 multiply
	}
	TR0=TF0=0;
	while(1);
}