#include "../include/libfs.h"
#include <fcntl.h>
#include <unistd.h>

int fs_openfile_for_read(char *file)
{
  int fd;

  fd = open(file, O_RDONLY);
  return (fd);
}

int fs_openfile_for_write(char *file)
{
  int fd;

  fd = open(file, O_WRONLY);
  return (fd);
}

int fs_createfile(char *file)
{
  int fd;

  fd = open(file, O_CREAT, S_IRWXU | S_IRGRP | S_IWGRP | S_IROTH);
  fs_closefile(fd);
  return (fd >= 0);
}

int fs_closefile(int fd)
{
  int closed;

  closed = close(fd);
  return (closed == 0);
}
