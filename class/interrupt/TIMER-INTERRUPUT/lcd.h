void delay(unsigned int i){
	unsigned char j;
	for( ;i>0;i--){
		for(j=250;j>0;j--);
		for(j=247;j>0;j--);
	}
}
void cmd(unsigned char cd){
	lcd = cd ; 
	rs=rw=0;en=1;
	delay(2);
	en=0;
}
void dat(unsigned char dt){
	lcd = dt;
	rs=1;rw=0;en=1;
	delay(2);
	en=0;
}
void ini(){
	cmd(0x01);
	cmd(0x02);
	cmd(0x06);
	cmd(0x0c);
	cmd(0x38);
	cmd(0x80);
}
void string(char *p){
	while(*p)
		dat(*p++);
}
void inti(unsigned int h){
	unsigned int temp=h,z_c=0,rev=0;
	if(h==0)
	dat(48);
	else{	
		while(!(temp%10)){
			z_c++;
			temp/=10;
		}
	
		while(h){
			rev=(rev*10)+(h%10);
			h/=10;
		}
		while(rev){
			dat((rev%10)+48);
			rev/=10;
		}
		while(z_c){
	   		dat(48);
	   		z_c--;
		}
	}
}