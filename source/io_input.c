#include "../include/libio.h"

int io_getchar(int fd, char *c)
{
  int count;

  count = read(fd, c, 1);
  return count;
}
