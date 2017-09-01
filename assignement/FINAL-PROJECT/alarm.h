void alarm(){
   unsigned char mm,hh,ampm;
   gcmd(PG0+1,2);
   gcmd(ST_ADD,2);
   string("ALARM");
	 if(ALM==1){
			gcmd(PG0+3,2);
			gcmd(ST_ADD,2);
			string("ON");
	 }
	 else if(ALM==0){
			gcmd(PG0+3,2);
			gcmd(ST_ADD,2);
			string("OFF");
	 }
   gcmd(PG0+5,2);
   gcmd(ST_ADD,2);
   mm=D_read(0xA0,0x00);
   hh=D_read(0xA0,0x01);
   ampm=D_read(0xA0,0x02);
   sdigit(hh/10);
   sdigit(hh%10);
   string(":");
   sdigit(mm/10);
   sdigit(mm%10);
   if(ampm==0)
   string(" AM");
   else
   string(" PM");



}/* hh mm ampm*/
void alarm_set(unsigned char hh,unsigned char mm){
 D_write(0xA0,0x00,mm);
 D_write(0xA0,0x01,hh);
 //D_write(0xA0,0x02,ampm);  //ampm==1 pm	and ampm=0 am
}

void alarm_check(){
 	
	if(ALM==1){	
		//unsigned char a_mm,a_hh,c_mm,c_hh,ampm,temp,h,m;
		unsigned char a_mm,a_hh,c_mm,c_hh;
		a_mm=D_read(0xA0,0x00);//read alarm min
   		a_hh=D_read(0xA0,0x01);//read alarm hour
//		ampm=D_read(0xA0,0x02);//read status of ampm
		c_mm=D_read(0xD0,0x01);//read clock min
   		c_hh=D_read(0xD0,0x02);//read clock hour

//		temp=c_hh&(1<<5);
//		c_hh&=0x1f;
//		h=c_hh%16;
//		c_hh/=16;
//		c_hh*=10;
//		c_hh+=h;
//		if(ampm==(temp>>5))
			//if(a_hh==(c_hh&0x1f)){
			if(a_hh==c_hh){
					//m=c_mm%16;
				//	c_mm/=16;
				//	c_mm*=10;
				//	c_mm+=m;
				if(a_mm==c_mm){
								 
					gcmd(PG0+6,2);
					gcmd(ST_ADD,2);
					if(c_mm!=(a_mm+1)){
						special();
						LED=~LED;
						DelayMS(2000);
						ALM=0;
					}
				}
			}
	}
	else{
	 clrpage(6,2);
	}
	
}