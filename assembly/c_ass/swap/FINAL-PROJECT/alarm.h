void alarm(){
   unsigned char mm,hh;
   gcmd(PG0,2);
   gcmd(ST_ADD,2);
   string("ALARM");
	
   gcmd(PG0+2,2);
   gcmd(ST_ADD,2);
   string("ON");

   gcmd(PG0+4,2);
   gcmd(ST_ADD,2);
   mm=D_read(0xA0,0x00);
   hh=D_read(0xA0,0x01);
   sdigit(hh/10);
   sdigit(hh%10);
   string(":");
   sdigit(mm/10);
   sdigit(mm%10);

}
void alarm_set(unsigned char hh,unsigned char mm){
 D_write(0xA0,0x00,mm);
 D_write(0xA0,0x01,hh);
}