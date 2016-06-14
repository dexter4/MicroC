


void main(void){
char buf[256];
int fd1;
int fd2;
int i;
int ret;
int ch;
fd1 = libcall("fopen","./myfile","rt");

fd2 = libcall("fopen","./newfile","wt");

ret = libfrd(fd1,buf,64);



i =0;
while( i < ret ){
  outputc buf[i];

  buf[i] = buf[i]+1; 
  i = i+1;
}


outputc '\n';
ret = libfwt(fd2,buf,ret);


output ret;
outputc '\n';



libcall("fclose",fd1,0);
libcall("fclose",fd2,0);

}
