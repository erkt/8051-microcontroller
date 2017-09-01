#include<reg51.h>
sbit sw=P2^0;
sbit led =P1^0;
main(){
	while(1){
		if(sw==0)
			led=1;
		else
			led=0;
	}
		
}