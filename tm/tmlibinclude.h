
#ifndef TMLIBINCLUDE_H
#define TMLIBINCLUDE_H


#define LIBPTBL_SIZE 2048
#define LIBDADDR_SIZE 16384
#define LIBSADDR_SIZE 1024
#define LIBTBUF_SIZE 1024
#define MAXSTR 256
#define LIBFDT_SIZE 256
#define REGI_RETURN 27

void lib_init(void);
int libcall_handle(int op,int prm1,int prm2);
int libinst_frd(int prm1,int prm2,int prm3);
int libinst_wrt(int prm1,int prm2,int prm3);




#endif //TMLIBINCUDE_H
