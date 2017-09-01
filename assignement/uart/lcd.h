void delay(int j){
unsigned char i;
for(;j>0;j--){
for(i=250;i>0;i--);
for(i=247;i>0;i--);
}
}
void lcmd(unsigned char cmd){
lcd = cmd;
RS=RW=0;
EN=1;
delay(2);
EN=0;
}
void ldata(unsigned char dt){
lcd = dt;
RS=1;RW=0;EN=1;
delay(2);
EN=0;
}
void linit(){
lcmd(0x01);
lcmd(0x02);
lcmd(0x06);
lcmd(0x0c);
lcmd(0x38);
lcmd(0x80);
}