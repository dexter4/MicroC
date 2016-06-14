

char bmpheader[54];

char pallt[1024];

char pixels[3249];
//108
void main(void){
int fd1;
int i;
int ret;
int ch;
int j;
fd1 = libcall("fopen","./124_1.bmp","rb");

ret = libfrd(fd1,bmpheader,54);
ret = libfrd(fd1,pallt,1024);
ret = libfrd(fd1,pixels,3249);

i =56;
while( i >=0 ){
    j = 0;
    while(j<60){
       ch = pixels[ i*60 +j];
       if(ch >-40){
            outputc '_';
       }else {
            outputc 'W';
       }
       j = j  +1;
    }
    outputc '\n';
i = i-1;
}


libcall("fclose",fd1,0);

}
