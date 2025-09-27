#include "../include/libio.h"

int io_putchar(int fd, char c)
{
  int count;

  count = write(fd, &c, 1);
  return (count);
}

int io_putstr(int fd, char *str)
{
  int count;

  count = 0;
  while (str[count])
  {
    io_putchar(fd, str[count]);
    count++;
  }
  return (count);
}

int io_putnb(int fd, int nb)
{
  int count;
  long lnb;

  count = 0;
  lnb = nb;
  if (lnb < 0)
  {
    io_putchar(fd, '-');
    lnb = -lnb;
    count++;
  }
  if (lnb >= 10)
    count = io_putnb(fd, (int)(lnb / 10));
  io_putchar(fd, (char)((lnb % 10) + '0'));
  return count + 1;
}
