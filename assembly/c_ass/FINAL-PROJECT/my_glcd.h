#define PG0 0xB8
#define PG7 0xBF
#define LCD P0
#define ST_ADD 0x40

code unsigned char char_c_arr[][6]={/*A*/0x7e,0x11,0x11,0x11,0x7e,0x00,/*B*/0x7f,0x49,0x49,0x49,0x3e,0x00,
									/*C*/0x3e,0x41,0x41,0x41,0x22,0x00,/*D*/0x7f,0x41,0x41,0x41,0x3e,0x00,
									/*E*/0x7f,0x49,0x49,0x49,0x41,0x00,/*F*/0x7f,0x09,0x1D,0x01,0x03,0x00,
									/*G*/0x3e,0x41,0x41,0x49,0x3B,0x00,/*H*/0x7f,0x08,0x08,0x08,0x7f,0x00,
									/*I*/0x00,0x41,0x7f,0x41,0x00,0x00,/*J*/0x30,0x40,0x40,0x41,0x3f,0x00,
								  	/*K*/0x7f,0x08,0x14,0x22,0x41,0x00,/*L*/0x7f,0x40,0x40,0x40,0x60,0x00,
								  	/*M*/0x7f,0x06,0x08,0x06,0x7f,0x00,/*N*/0x7f,0x06,0x08,0x30,0x7f,0x00,
								  	/*O*/0x3e,0x41,0x41,0x41,0x3e,0x00,/*P*/0x7f,0x09,0x09,0x09,0x06,0x00,
								  	/*Q*/0x1e,0x21,0x61,0x61,0x1e,0x00,/*R*/0x7f,0x09,0x19,0x29,0x46,0x00,
								  	/*S*/0x66,0x49,0x49,0x49,0x33,0x00,/*T*/0x03,0x01,0x7f,0x01,0x03,0x00,
								  	/*U*/0x3f,0x40,0x40,0x40,0x3f,0x00,/*V*/0x0f,0x30,0x40,0x30,0x0f,0x00,
								  	/*W*/0x3f,0x40,0x30,0x40,0x3f,0x00,/*X*/0x63,0x14,0x08,0x14,0x63,0x00,
								  	/*Y*/0x03,0x0c,0x70,0x0c,0x03,0x00,/*Z*/0x61,0x51,0x49,0x45,0x43,0x00};
code unsigned char space[6]={0x00,0x00,0x00,0x00,0x00,0x00};
code unsigned char colon[6]={0x00,0x00,0x22,0x00,0x00,0x00};
code unsigned char dot[6]={0x00,0x40,0x00,0x00,0x00,0x00};
code unsigned char digit_arr[10][6]={/*0*/ 0x7f,0x41,0x41,0x41,0x7f,0x00, /*1*/  0x00,0x42,0x7f,0x40,0x00,0x00,
									 /*2*/ 0x42,0x61,0x51,0x49,0x46,0x00, /*3*/	0x49,0x49,0x49,0x49,0x7f,0x00,
									 /*4*/ 0x18,0x14,0x12,0x7f,0x10,0x00, /*5*/  0x4f,0x49,0x49,0x49,0x79,0x00,
									 /*6*/ 0x7f,0x49,0x49,0x49,0x79,0x00, /*7*/  0x01,0x71,0x09,0x05,0x03,0x00,
									 /*8*/ 0x36,0x49,0x49,0x49,0x36,0x00, /*9*/  0x4f,0x49,0x49,0x49,0x7f,0x00
									};
code unsigned char spe[]={0x40,0x60,0x70,0x78,0x7c,0x7e,0x7f,0x7e,0x7c,0x78,0x70,0x60,0x40,0x00,0x00,0xe0,0x84,0x83,0x83,0x84,0xe0};
void c_select(unsigned char chip){
	if(chip==0){
		CS1=CS2=0;
	}
	else if(chip==1){
	 CS1=1;CS2=0;
	}
	else if(chip==2){
	 CS1=0;CS2=1;
	}
	else if(chip==3){
	 CS1=1;CS2=1;
	}
}
void gwrite(unsigned char cmd){
	RW=0;
	LCD=cmd;
	EN=1;
	EN=0;
}

void gcmd(unsigned char cmd,unsigned char c){
	c_select(c);
	RS=0;
	gwrite(cmd);
}

void gdata(unsigned char dta){
	RS=1;
	gwrite(dta);
}
void dinit(){
		RST=0;
		RST=1;
		gcmd(0x3e,3);//Display  off 
		gcmd(0x3f,3);//Display on 
		gcmd(0x40,3);//starting of lcd on horizonatal of page
		gcmd(0xB8,3);///page value..1011 1xxx
		gcmd(0xc0,3);//vertical of line
}

void clrscreen(){
	unsigned char i,j;
	for(i=0;i<8;i++){
			gcmd(PG0+i,3);
			gcmd(0x40,3);
		for(j=0;j<64;j++)
			gdata(0x00);
	}
}
void clrpage(unsigned char i,unsigned char c){
	unsigned char j;
	gcmd(PG0+i,c);
	gcmd(ST_ADD,c);
	for(j=0;j<64;j++)
			gdata(0x00);
}

void sdigit(unsigned char i){
 unsigned char j;
 for(j=0;j<6;j++)
 	gdata(digit_arr[i][j]);
	return;
}
void string(char *p){
	unsigned char i,j;	
	for(i=0;p[i];i++)
		for(j=0;j<6;j++){
				if(p[i]>='A'&&p[i]<='Z')
						gdata(char_c_arr[p[i]-65][j]);
				else if(p[i]>='0' && p[i]<='9')
						sdigit(p[i]-48);
				else if(p[i]==' ')
						gdata(space[j]);
				else if(p[i]==':')
						gdata(colon[j]);
				else if(p[i]=='.')
						gdata(dot[j]);

			}
}	
void special(){
	unsigned char j;
	for(j=0;j<21;j++)
			gdata(spe[j]);
}