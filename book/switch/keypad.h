scode unsigned char look[4][4]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,0};
sbit c0=P2^0;
sbit c1=P2^1;
sbit c2=P2^2;
sbit c3=P2^3;
sbit r0=P2^4;
sbit r1=P2^5;
sbit r2=P2^6;
sbit r3=P2^7;
unsigned char key(){
	unsigned char row,col;
	r0=r1=r2=r3=0;
	c0=c1=c2=c3=1;
	while((c0&c1&c2&c3)==1);
	r0=0;r1=r2=r3=1;
	if((c0&c1&c2&c3)==0){
		row=0;
		goto coloum;
	}
	r1=0;r0=r2=r3=1;
	if((c0&c1&c2&c3)==0){
		row=1;
		goto coloum;
	}
	r2=0;r1=r0=r3=1;
	if((c0&c1&c2&c3)==0){
		row=2;
		goto coloum;
	}
	r3=0;r1=r2=r0=1;
	if((c0&c1&c2&c3)==0){
		row=3;
		goto coloum;
	}
	coloum:
	if(c0==0)
		col=0;
	else if(c1==0)
		col=1;
	else if(c2==0)
		col=2;
	else if(c3==0)
		col=3;
	
	delay(100);
	while((c0&c1&c2&c3)==0);
	return look[row][col];
}