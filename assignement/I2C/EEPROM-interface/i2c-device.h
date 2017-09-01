void device_write(unsigned char	sa,  unsigned char mr,  unsigned char da){
		
		start();
		write(sa);
		ack();
		
		write(mr);
		ack();
		
		write(da);
		ack();
		
		stop();
		delay(10);
}
unsigned char device_read(unsigned char sa, unsigned char mr){
		unsigned  char temp;
		start();
		write(sa);
		ack();
		write(mr);
		ack();
		start();
		write(sa|1);
		ack();
		temp=read();
		noack();
		stop();
		return temp;
}