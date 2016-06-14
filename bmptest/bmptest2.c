

char bmpheader[54];

char pallt[1024];

char pixels[65536];

void main(void){
int fd1;
int fd2;
int i;
int ret;
int ch;
int t;
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
ret = libfrd(fd1,pixels,65536);


output ret;
outputc '\n';


i =0;
while( i < ret ){
  t = pixels[i];
 outputs "if";
outputc '\n';
  if(t>= 0 && t<127){
outputs "true";
outputc '\n';

  pixels[i] =  t -33;
  }else{
outputs "false";
outputc '\n';
  pixels[i] = t-66;
}
 outputs "ifend";
outputc '\n';
  i = i+1;
}


outputc '\n';

ret = libfwt(fd2,bmpheader,54);

output ret;
outputc '\n';
ret = libfwt(fd2,pallt,1024);

output ret;
outputc '\n';
ret = libfwt(fd2,pixels,65536);



output ret;
outputc '\n';


libcall("fclose",fd1,0);
libcall("fclose",fd2,0);

}
