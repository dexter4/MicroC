

char bmpheader[54];

char pallt[1024];

char pixels[65536];

void main(void){
int fd1;
int fd2;
int i;
int ret;
int ch;
char t;
fd1 = libcall("fopen","./LENNA.bmp","rb");

fd2 = libcall("fopen","./output.bmp","wb");

ret = libfrd(fd1,bmpheader,54);


ret = libfrd(fd1,pallt,1024);


ret = libfrd(fd1,pixels,65536);




i =0;
while( i < ret ){
 
    if( pixels[i]>0){
        pixels[i] = -1;

    }else{
        pixels[i] = 0;
    }
 
  i = i+1;
}




ret = libfwt(fd2,bmpheader,54);


ret = libfwt(fd2,pallt,1024);


ret = libfwt(fd2,pixels,65536);



outputs  "image processing success! ";
outputc '\n';


libcall("fclose",fd1,0);
libcall("fclose",fd2,0);

}
