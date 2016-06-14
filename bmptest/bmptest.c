

char bmpheader[54];

char pallt[1024];

char pixels[50310];

void main(void){
int fd1;
int fd2;
int i;
int ret;
int ch;
fd1 = libcall("fopen","./124a.bmp","rb");

fd2 = libcall("fopen","./output.bmp","wb");
output fd1;
outputc '\n';

output fd2;
outputc '\n';
ret = libfrd(fd1,bmpheader,54);

output ret;
outputc '\n';
ret = libfrd(fd1,pallt,1024);

output ret;
outputc '\n';
ret = libfrd(fd1,pixels,50310);


output ret;
outputc '\n';


i =0;
while( i < ret ){

   
  pixels[i] = pixels[i]+64;
  i = i+1;
}


outputc '\n';

ret = libfwt(fd2,bmpheader,54);

output ret;
outputc '\n';
ret = libfwt(fd2,pallt,1024);

output ret;
outputc '\n';
ret = libfwt(fd2,pixels,50310);



output ret;
outputc '\n';


libcall("fclose",fd1,0);
libcall("fclose",fd2,0);

}
