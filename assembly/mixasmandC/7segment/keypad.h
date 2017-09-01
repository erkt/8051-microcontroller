code unsigned char look[4][4] = {1,2,3,'+',
							  4,5,6,'-',
							  7,8,9,'*',
							  '%',0,'/','='};
unsigned char keysearch(unsigned char temp)
{
		unsigned char row,col;
		r0=r1=r2=r3=0;
		c0=c1=c2=c3=1;
		while(c0&c1&c2&c3){
					s=0;
					se=lut[temp];
					my_delay(2);
					s=1;
		}
		r0=0;
		r1=r2=r3=1;
		if(!(c0&c1&c2&c3)){
			row=0;
			goto coloum;
		}
		r1=0;
		r0=r2=r3=1;
		if(!(c0&c1&c2&c3)){
			row=1;
			goto coloum;
		}
		r2=0;
		r1=r0=r3=1;
		if(!(c0&c1&c2&c3)){
			row=2;
			goto coloum;
		}
		r3=0;
		r1=r2=r0=1;
		if(!(c0&c1&c2&c3)){
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
		my_delay(200);
		while(!(c0&c1&c2&c3)){
				s=0;
					se=lut[temp];
					my_delay(2);
					s=1;
		}
		return look[row][col];
}