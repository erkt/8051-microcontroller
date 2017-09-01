///USING BITWISE LED ON/OFF


#include"delay.h"
sfr P2=0xA0;
sbit led =P2^0;
main()
{
	 while(1)
	{
	led=0;
	my_delay(1000);	
	led=1;
	my_delay(1000);
	}

}

