void cmd(unsigned char cmd){
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
void ini(){
	cmd(0x01);
	cmd(0x02);
	cmd(0x06);
	cmd(0x0c);
	cmd(0x80);
	cmd(0x38);
}

void inte(unsigned int dt){
	unsigned char z_c=0;
	unsigned int temp=dt;
	if(dt==0)
		ldata(48);
	else{
		while(!(temp%10)){
			  z_c++;
			  temp/=10;
		}				  
		temp=0;
		while(dt){
			temp = (temp*10)+(dt%10);
			dt/=10;
		}					
		while(temp){
			ldata(temp%10+48) ;
			temp/=10;
		}
		while(z_c--)
			ldata(48);
		}
}
void floata(float asd){
	int g;
	g=asd;
	inte(g);
	ldata('.');
	inte(((asd-g)*1000));
}