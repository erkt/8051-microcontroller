unsigned char look[]={'0','1','2','3','4','5','6','7','8','9'};
void delay(int i) {
	unsigned char j;
	for(;i>0;i--){
		for(j=250;j>0;j--);
		for(j=247;j>0;j--);
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
	EN = 0;
}
void lstring(char *p){
	while(*p)
		ldata(*p++);
}
void ldigi(int j){
	int k,count=0,temp=0;
	k=j;
	while(k){
		if((k%10)==0)
			count++;
		k/=10;
	}
	k=j;
	while(k){
		temp=(temp*10)+(k%10);
		k/=10;
	}
	while(temp){
		ldata(look[(temp%10)]);
		temp/=10;
	}
	for(;count;count--)
	ldata(look[0]);
}
void linit(){
	lcmd(0x01);
	lcmd(0x02);
	lcmd(0x06);
	lcmd(0x0c);
	lcmd(0x80);
	lcmd(0x38);
}
	