void delay(int i){
	unsigned char j;
	for(;i>0;i--){
		for(j=250;j>0;j--);
		for(j=247;j>0;j--);
	}
}
void lcmd(unsigned char cmd){
	LCD=cmd;
	RS=RW=0;EN=1;
	delay(2);
	EN=0;
}
void ldata(unsigned char dta){
	LCD=dta;
	RS=1;RW=0;EN=1;
	delay(2);
	EN=0;
}
void lini(){
	lcmd(0x01);
	lcmd(0x02);
	lcmd(0x06);
	lcmd(0x0c);
	lcmd(0x38);
	lcmd(0x80);
}
void lstring(char *p){
	while(*p)
		ldata(*p++);
}
void lcg(char *p,unsigned char j){
	unsigned char i;
	lcmd(0x40);
	for(i=0;i<j;i++)
	ldata(p[i]);
	lcmd(0x80);
}