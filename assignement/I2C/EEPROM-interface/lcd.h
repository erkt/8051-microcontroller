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
		cmd(0x0e);
		cmd(0x38);
		cmd(0x80);
}