void delay(int i){
	unsigned char j;
	for(;i>0;i--){
		for(j=250;j>0;j--);
		for(j=247;j>0;j--);
	}
}
void lcmd(unsigned char cmd){
	lcd = cmd;
	RS=RW=0;EN=1;
	delay(2);
	EN=0;
}
void ldata(unsigned char dta){
	lcd = dta;
	RS=1;RW=0;EN=1;
	delay(2);
	EN=0;
}
void lint(unsigned char temp){
	ldata((temp/10)+48);
	ldata((temp%10)+48);
}
void ini(){
	lcmd(0x01);
	lcmd(0x02);
	lcmd(0x06);
	lcmd(0x0c);
	lcmd(0x38);
	lcmd(0x80);
}