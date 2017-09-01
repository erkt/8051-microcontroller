#include<reg51.h>
sbit sw = P1^0;
sbit led = P2^7;
main(){
P2=0xf0;
while(1){
if(sw==0)
led =0;
else
led =1;
}
}