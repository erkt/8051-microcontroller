#include<reg51.h>
#include"delay.h"
sfr LCD =0x80;
sbit RS = P3^4;
sbit RW = P3^5;
sbit EN = P3^6;
#include"lcd.h"
sbit SDA = P2^0;
sbit SCL = P2^1;
#include"i2c.h"
#include"i2c-device.h"
main(){
		unsigned char temp1,temp,date,*year="20";
		init();
// 		D_write(0xD0,0x00,0x00);
// 		D_write(0xD0,0x01,0x39);
// 		D_write(0xD0,0x02,0x66);
// 		D_write(0xD0,0x03,0x03);
// 		D_write(0xD0,0x04,0x13);
// 		D_write(0xD0,0x05,0x07);
// 		D_write(0xD0,0x06,0x16);

		while(1){
			cmd(0xc0);
			temp1=D_read(0xD0,0x02);
			if(temp1&0x20)
				string("PM  ");
			else
				string("AM  ");
				temp1=temp1&0x1f;
			ldata(temp1/16+48);
			ldata(temp1%16+48);
			ldata(':');	
			temp=D_read(0xD0,0x01);
			ldata(temp/16+48);
			ldata(temp%16+48);
			ldata(':');
			temp=D_read(0xD0,0x00);
			ldata(temp/16+48);
			ldata(temp%16+48);
			
			cmd(0x80);
			date=D_read(0xD0,0x03);
			switch(date){
				case 0: string("SUN");
						break;
				case 1: string("MON");
						break;
				case 2: string("TUE");
						break;
				case 3: string("WED");
						break;
		    	case 4: string("THU");
						break;
		    	case 5: string("FRI");
						break;
				case 6: string("SAT");
						break;
			}
			date=D_read(0xD0,0x04);
			ldata(date/16+48);
			ldata(date%16+48);
			ldata(':');
			date=D_read(0xD0,0x05);
			ldata(date/16+48);
			ldata(date%16+48);
			ldata(':');
			date=D_read(0xD0,0x06);
			string(year);
			ldata(date/16+48);
			ldata(date%16+48);
			ldata(' ');

			
		}
}