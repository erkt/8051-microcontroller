sfr led= 0x80;
sbit s = P2^0;
sbit s1 = P2^1;
code unsigned char loop[]={0x40,0x79,0x24,0x30,0x19,0x12,0x02,0x78,0x00,0x10};
void seg(unsigned char j){
	s=0;
	led=loop[j/16];
	my_delay(2);
	s=1;s1=0;
	led=loop[j%16];
	my_delay(2);
	s1=1;s=1;
}