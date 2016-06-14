


void main(void){
char buf[256];
int fd;
int i;
int ret;
fd = libcall("fopen","./myfile","rb");


ret = libfrd(fd,buf,64);

outputc '\n';
output fd;
outputc '\n';
output ret;



outputc '\n';
outputs "st";
outputc '\n';
for(i=0 ; i < ret ; i=i+1){
  outputc buf[i];
}

libcall("fclose",0,0);

}
