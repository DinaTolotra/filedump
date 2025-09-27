#ifndef LIB_FS_H
#define LIB_FS_H

#include <fcntl.h>

int fs_openfile_for_read(char *file);
int fs_openfile_for_write(char *file);
int fs_createfile(char *file);
int fs_closefile(int fd);

#endif // LIB_FS_H
