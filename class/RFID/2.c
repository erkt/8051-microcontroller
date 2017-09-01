#include<reg51.h>
#include"uart.h"
sfr LCD = 0x80;
sbit RS = P3^4;
sbit RW = P3^5;
sbit EN = P3^6;
#include"lcd.h"
main()
{
	unsigned char i,j,l,buff[11],da[2][11]={"00318955","00336106"};
	inti();
	ini();
	while(1){
		str("Show your RFID\r\n");
		strr("Show your RFID");
		for(i=0;i<10;i++)
		   buff[i]=rx();
		l=i;
		lcmd(0xc0);
		for(j=0;j<2;j++){
			for(i=0;i<10;i++)
				if(da[j][i]!=buff[i])
				  	break;
		  if((l==i)&&(j==0)){
			  str("User 1\r\n ");
			  strr("User 1");
        delay(2000);
        break;				
			}
			else if((l==i)&&(j==1)){
			  str("User 2\r\n ");	
			  strr("User 2");
        delay(2000);
        break;				
			}
		}
			if ((j==2)&&(l!=i)){
				str("Inavalid User\r\n");
				strr("Invalid User");
			}
		delay(1000);
		lcmd(0x01);
		lcmd(0x02);
		
	}
}