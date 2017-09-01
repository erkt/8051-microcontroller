void cmd(unsigned char cmd){
lcd =cmd;
rs=rw=0;en=1;
delay(2);
en=0;
}
void ldata(unsigned char dta){
lcd=dta;
rs=1;rw=0;en=1;
delay(2);
en=0;
}
void init(){
cmd(0x01);
cmd(0x02);
cmd(0x06);
cmd(0x0c);
cmd(0x38);
cmd(0x80);
}