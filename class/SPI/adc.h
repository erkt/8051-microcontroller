unsigned int read(){
	unsigned int temp=0;
	char i;
	cs = 0;//start comm
	clk=0; din =1; clk=1;//start bit
	clk=0; din =1; clk=1;//signle ended mode

	clk=0; din =1; clk=1;
	clk=0; din =0; clk=1;
	clk=0; din =0; clk=1;

	clk=0;  clk=1;
	clk=0;  clk=1;

	for(i=11;i>=0;i--){
		clk = 0;
		if(dout==1)
			temp = temp|(1<<i);
		clk = 1;
	}
	cs = 1;
	return temp;
}