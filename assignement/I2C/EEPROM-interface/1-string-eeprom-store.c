#include<reg51.h>
#include"delay.h"
sfr LCD = 0x80;
sbit RS = P3^4;
sbit RW = P3^5;
sbit EN = P3^6;
#include"lcd.h"
sbit SDA = P2^0;
sbit SCL = P2^1;
#include"i2c.h"
#include"i2c-device.h"

main(){
   unsigned char buffer[]="I2C INTERFACING WITH AT24c08!",add=0x00,i;
   ini();
   for(add=0;buffer[add];add++)
   device_write(0xA2,add,buffer[add]);
   i=add;
   for(add=0;add<i;add++)
   {
   if(add==16)
   cmd(0xc0);
   ldata(device_read(0xA2,add));
   }
   while(1);
}