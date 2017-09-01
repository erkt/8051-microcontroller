#include<reg51.h>
sbit r=P1^4;
sbit c1=P1^1;
sbit c2=P1^2;
#define led P2
main()
{
	led=0xf0;
	while(1){
		r=0;
		while((c1&c2)==1);
		if(c1==0)
			led= 0x78;
		else if (c2 ==0)
			led = 0xb4;
		while((c1|c2)==0);
	}
}