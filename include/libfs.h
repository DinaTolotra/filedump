#ifndef LIBFS_H
#define LIBFS_H

#include <fcntl.h>

int fs_openfile_for_read(char *file);
int fs_openfile_for_write(char *file);
int fs_createfile(char *file);
int fs_closefile(int fd);

#endif // LIBFS_H
