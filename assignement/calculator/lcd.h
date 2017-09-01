//define lcd and control pin
void l_cmd(unsigned char cmd){
	lcd = cmd;
	RS=0;RW=0;EN=1;
	my_delay(2);
	EN=0;
}
void l_data(unsigned char dta){
	lcd = dta;
	RS=1;RW=0;EN=1;
	my_delay(2);
	EN=0;
}
void l_init(){
	l_cmd(0x01);
	l_cmd(0x02);
	l_cmd(0x06);
	l_cmd(0x0c);
	l_cmd(0x38);
	l_cmd(0x80);
}
void l_string(const char *s){
	while(*s)
	l_data(*s++);
}
void l_int(int k){
	int i,k1=0,j,c_zero=0,g=k;
	if(k==0){
		l_data(k+48);
	}
	else{
	while(g){
	  if(!(g%10))
	  c_zero++;
	  g=g/10;
	}
	while(k){
		j=k%10;
		k1=((k1*10)+j);
		k=k/10;
	}
	while(k1){
		i=k1%10;
		l_data(i+48);
		k1=k1/10;
	}
	while(c_zero){
	l_data(48);
	c_zero--;
	}
}
}