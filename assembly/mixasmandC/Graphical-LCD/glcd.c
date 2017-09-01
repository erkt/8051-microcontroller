#include <reg51.h>
#include "delay.h"
#include "GLCD.h"

void main(void)
{
  unsigned char i;
  InitGLCD();
  ClrScreen(); 

   while(1)
   {
		 ShowImage();/*
     CmdGLCD(PAGE_0,3);
     CmdGLCD(COL_ADDR,3);
  
     for(i=0;i<10;i++)
     {
  	   ShowDigit(i);
           
       DelayMS(100);
     }
	 ClrPage(0,3);*/
	 DelayMS(500);
   }
   //while(1);	    
}

