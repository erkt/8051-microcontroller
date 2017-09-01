sbit r0=P1^4;
sbit r1=P1^5;
sbit r2=P1^6;
sbit r3=P1^7;
sbit c0=P1^0;
sbit c1=P1^1;
sbit c2=P1^2;
sbit c3=P1^3;
code unsigned char table[4][4]= { 0xe1,0xd2,0xc3,0xb4,0xa5,0x96,0x87,0x78,0x69,0x5a,0x4b,0x3c,0x2d,0x1e,0x0f,0xf0};

unsigned char keysearch(){
	unsigned char row,col;
	
	r0=r1=r2=r3=0;
	c0=c1=c2=c3=1;		
 	while(	(c0&c1&c2&c3) == 1);
 	r0=0;	r1=1; r2=1; r3=1;
	if((c0&c1&c2&c3) == 0){
 		row=0;
 		goto search_coloum;
  	}	
  	r0=1;  	r1=0; r2=1; r3=1;
  	if(( c0&c1&c2) == 0 ){
  		row =1;
  		goto search_coloum;
  	}
	r0=1; r1=1; r2=0; r3=1;
	if((c0&c1&c2&c3) == 0){
		row =2;
		goto search_coloum;
	}
	r0=1; r1=1; r2=1; r3=0;
	if((c0&c1&c2&c3) == 0 ){
		row =3;
		goto search_coloum;
	}
search_coloum:
	if(c0==0)
		col = 0;
	else if (c1 == 0)
		col = 1;
	else if (c2 == 0)
		col = 2;
	else if (c3 == 0)
		col = 3;
	
	my_delay(100);
	 

	while( ( c0&c1&c2&c3) == 0);
	return table[row][col];
}