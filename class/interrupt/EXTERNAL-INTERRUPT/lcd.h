void delay(unsigned int i){
	unsigned char j;
	for( ; i>0; i--){
		for(j=250;j>0;j--);
		for(j=247;j>0;j--);
	}
}
void cmd(unsigned char cm){
	LCD =cm;
	RS=RW=0;
	EN=1;
	delay(2);
	EN=0;
}
void dat(unsigned char dt){
	LCD= dt;
	RS=1;RW=0;
	EN=1;
	delay(2);
	EN=0;
}
void ini(){
 	cmd(0x01);
	cmd(0x02);
	cmd(0x06);
	cmd(0x80);
	cmd(0x0c);
	cmd(0x38);
}
void string(char *p){
	while(*p)
		dat(*p++);
}