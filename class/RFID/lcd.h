void delay(int j){
	unsigned char i;
	for(;j>0;j--){
		for(i=250;i>0;i--);
		for(i=247;i>0;i--);
}
}

void lcmd(unsigned char cmd){
	LCD = cmd;
	RS=RW=0;EN=1;
	delay(2);
	EN=0;
}
void ldata(unsigned char dta){
	LCD = dta;
	RS=1;RW=0;EN=1;
	delay(2);
	EN=0;
}
void strr(char *s){
	while(*s)
		ldata(*s++);
}
void ini(){
	lcmd(0x01);
	lcmd(0x02);
	lcmd(0x06);
	lcmd(0x0c);
	lcmd(0x38);
	lcmd(0x80);
}

	