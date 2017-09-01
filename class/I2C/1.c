#include<reg51.h>
#include"delay.h"
sfr lcd =0x80;
sbit rs=P3^4;
sbit rw=P3^5;
sbit en =P3^6;
sbit sda=P2^0;
sbit scl=P2^1;
#include"lcd.h"
#include"i2c.h"
#include"i2c_device.h"
main(){
 init();
 ldata('k');
 while(1){
 d_write(0x90,0xaa);

 }

}