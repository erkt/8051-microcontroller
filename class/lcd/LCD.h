void l_cmd(unsigned char cmd){
	lcd=cmd;
	RS=0;RW=0;EN=1;
	my_delay(2);
	EN=0;
}
void l_data(unsigned char dta){
	lcd=dta;
	RS=1;RW=0;EN=1;
	my_delay(2);
	EN=0;
}
void l_init(){
	l_cmd(0x01);
	l_cmd(0x02);
	l_cmd(0x06);
	l_cmd(0x80);
	l_cmd(0x38);
	l_cmd(0x0C);
}

void l_string(char *s){
	while(*s)
		l_data(*s++);
}
