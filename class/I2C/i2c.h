void start(){
scl=1;sda=1;sda=0;
}
void stop(){
scl=1;sda=0;sda=1;scl=1;
}
void write(unsigned char a){
char i;
for(i=7;i>=0;i--){
scl=1;
sda= (a&(1<<i))?1:0;
scl=0;
}
}
unsigned char read(){
char i;
unsigned char temp;
for(i=7;i>=0;i--){
scl=1;
if(sda==1)
temp=temp|(1<<i);
scl=0;
}
return temp;
}
void ack(){
scl=0;
sda=1;
scl=1;
while(sda==1);
scl=0;
}
void noack(){
scl=0;
sda=1;
scl=1;
}