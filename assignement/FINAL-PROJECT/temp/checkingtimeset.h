gcmd(PG0,2);
	 gcmd(ST_ADD,2);
	 for(i=0;i<3;i++){
				sdigit(tm[i]/10);
				sdigit(tm[i]%10);
				string(":");
		}
			gcmd(PG0+1,2);
	 gcmd(ST_ADD,2);
	 for(i=3;i<6;i++){
				sdigit(tm[i]/10);
				sdigit(tm[i]%10);
		 string(":");
 }
 gcmd(PG0+2,2);
	 gcmd(ST_ADD,2);
	 for(i=6;i<7;i++){
				sdigit(tm[i]/10);
				sdigit(tm[i]%10);
		 string(":");
 }