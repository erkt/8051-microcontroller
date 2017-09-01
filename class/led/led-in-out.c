#include<reg51.h>
#include"delay.h"
sfr led=0xA0;
main(){
	unsigned char i,j;
	while(1)
		{
			/*for(i=0,j=7;i<8;i++,j--)
			{
				if(i<4)
   				led=((0x0f)&(1<<i))|((~((0xf0)&(1<<j)))&0xf0);
				else
				led=((~((0xf0)&(1<<i)))&0xf0)|((0x0f)&(1<<j));
				my_delay(1000);
			}
		*/
		
		for(i=0,j=7;i<8;i++,j--){
				if(i<4)
				led=(0x00^(1<<i))|(0xf0^(1<<j));
				else
				led=(0xf0^(1<<i))|(0x00^(1<<j));
				my_delay(1000);
				}				
		}
}