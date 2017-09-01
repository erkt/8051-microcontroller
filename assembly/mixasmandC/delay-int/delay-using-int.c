void delay(unsigned int i){
	unsigned int j;
	for( ;i>0;i--)
		for(j=1275;j>0;j--);
	for(j=209;j>0;j--);
}
main(){
delay(90);
while(1);
}