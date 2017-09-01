void inti(){
SCON=0x50;
TMOD=0x20;
TH1=TL1=253;
TR1=1;
}
void tx(unsigned char dta){
	SBUF = dta;
	while(TI==0);
	TI=0;
}
unsigned char rx(){
	while(RI==0);
	RI=0;
	return SBUF;
}
void str(char *p){
	while(*p)
		tx(*p++);
}