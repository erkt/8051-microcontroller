#include<reg51.h>
#include"delay.h"

main(){

while(1) {
P2=	0xFF;
my_delay(1000);
P2= 0xFE ;
my_delay(1000);
}
}