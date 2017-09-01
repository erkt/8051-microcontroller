sbit RS=P2^0; 
sbit RW=P2^1;
sbit EN=P2^2;

sbit RST=P2^3;
sbit CS2=P2^4;
sbit CS1=P2^5;


#define GLCD P0  // 8 data lines

#define PAGE_0 0xb8  // first page address
#define PAGE_7 0xbf  // last  page address
#define COL_ADDR 0x40 //base address of 64 columns

#define NONE 0
#define C1   1
#define C2   2
#define BOTH 3
	
void InitGLCD(void);
void CmdGLCD(unsigned char,unsigned char);
void DispGLCD(unsigned char);
void WriteGLCD(unsigned char);
void ChipSel(unsigned char);
void ClrScreen();
void ClrPage(unsigned char,unsigned char );

void ShowDigit(unsigned char);
void ShowImage(void);

code unsigned char digit_arr[10][4]={
							/*0*/	 0xff,0x81,0x81,0xff,
							/*1*/    0xff,0x00,0x00,0x00,
							/*2*/	 0xf9,0x89,0x89,0x8f,
							/*3*/	 0x89,0x89,0x89,0xff,
							/*4*/	 0x0f,0x08,0x08,0xff,
							/*5*/    0x8f,0x89,0x89,0xf9,
							/*6*/    0xff,0x89,0x89,0xf9,
							/*7*/    0x01,0x01,0x01,0xff,
							/*8*/    0xff,0x89,0x89,0xff,
							/*9*/    0x9f,0x91,0x91,0xff

									};
void ShowDigit(unsigned char);

void InitGLCD(void)
{
    RST = 0;
    RST = 1;
    CmdGLCD(0x3e,3);// 0x3E turn it Off. 
    CmdGLCD(0x3f,3);// 0x3F Display ON.     
    CmdGLCD(0xb8,3);// page 0 base address
    CmdGLCD(0x40,3);// col base address
    CmdGLCD(0xc0,3);//taking cursor to top line of refresh ram
}

void CmdGLCD(unsigned char cmd,unsigned char chip)
{
    ChipSel(chip);
    RS = 0;
    WriteGLCD(cmd);
}	

void DispGLCD(unsigned char ch)
{
    RS = 1;
	WriteGLCD(ch);
}

void WriteGLCD(unsigned char val)
{
	RW = 0;
    GLCD = val;
    EN = 1;
    EN = 0;
}

void ChipSel(unsigned char cs)
{
   switch(cs)
   {
     case 0: CS1=0; CS2=0;return;
     case 1: CS1=1; CS2=0;return;
     case 2: CS1=0; CS2=1;return;
     case 3: CS1=1; CS2=1;return;
   }  
} 
 
void ClrScreen()
{
   int i,y;
   for(i=PAGE_0;i<=PAGE_7;i++)          
   {
     CmdGLCD(i,BOTH);      // Select Pages.  
     CmdGLCD(COL_ADDR,BOTH);                      
     for(y=0;y<64;y++)
        DispGLCD(0x00); // Clear data in the LCD.
   }    
}

void ClrPage(unsigned char page,unsigned char chip)
{
  unsigned char y;
  CmdGLCD(PAGE_0+page,chip);  	    	
  CmdGLCD(COL_ADDR,chip);
  for (y=0;y<64;y++)
       DispGLCD(0x00); // Clear data in the LCD.
}

void ShowDigit(unsigned char dig)
{
   unsigned char i;
   for(i=0;i<4;i++)
   {
     DispGLCD(digit_arr[dig][i]);
   } 
   DispGLCD(0x00);    
}

/*
void ShowImage()
{	
      int i,j;
      
      for(i=0;i<8;i++)
      {
        CmdGLCD(0xB8+i,BOTH);
	    CmdGLCD(0x40,BOTH);
	
        ChipSel(1);  
        for(j=0;j<128;j++)
        {
          if(j==64)
          {
                ChipSel(2);
          }

          DispGLCD(arr[i][j]);
        }  
            
       }  
       
}*/
