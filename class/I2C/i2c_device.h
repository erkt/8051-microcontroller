void d_write(unsigned char sa,unsigned char mr,unsigned char dt){
start();
write(sa);
ack();
write(mr);
ack();
write(dt);
ack();
stop();
delay(10);
}

unsigned char d_read(unsigned char sa,unsigned mr){
unsigned char temp=0;
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
