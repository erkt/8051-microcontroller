	 // this define in main  unsigned char ss,mi,hh,d,dd,mm,yy,temp;
void clock(){

	hh=D_read(0xD0,0x02);//hour
	   temp=hh;
	   hh&=0x1f;
	sdigit(hh/16);
	sdigit(hh%16);
	string(":");

	mi=D_read(0xD0,0x01);//minute
	sdigit(mi/16);
	sdigit(mi%16);
	string(":");
	
	ss=D_read(0xD0,0x00);//second
	sdigit(ss/16);
	sdigit(ss%16);
	string(":");

	if(temp&0x20)
		string(" PM");
	else
		string(" AM");	

	gcmd(PG0+4,1);
	gcmd(ST_ADD,1);

	d=D_read(0xD0,0x03);//day
	if(d==0){
	   	string("  SUNDAY ");
	}
	else if(d==1){
		string("  MONDAY ");
	}
	else if(d==2){
		string(" TUESDAY ");
	}
	else if(d==3){
		string(" WEDNESDAY ");
	}
	else if(d==4){
		string(" THURSDAY ");
	}
	else if(d==5){
		string("  FRIDAY ");
	}
	else if(d==6){
		string(" SATURDAY ");
	}
	
	gcmd(PG0+6,1);
	gcmd(ST_ADD,1);

	
	string("  ");
	dd=D_read(0xD0,0x04);//date
	sdigit(dd/16);
	sdigit(dd%16);
	string(":");
	
	mm=D_read(0xD0,0x05);//month
	sdigit(mm/16);
	sdigit(mm%16);
	string(":");
	
	yy=D_read(0xD0,0x06);//year
	sdigit(yy/16);
	sdigit(yy%16);
}

