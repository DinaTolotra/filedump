#include "./include/libio.h"
#include "./include/libfs.h"
#include "./include/libstr.h"
#include <stdlib.h>

int printline_in_file(int fd);
void printprintable(char *str);
void getstr(int fd, char *str, int count);

int main(int ac, char **av)
{
  char **files;
  int index;
  int count;
  int fd;

  count = 1;
  index = 0;
  if (ac > 1)
    files = av + 1;
  while (index < ac - 1)
  {
    fd = fs_openfile_for_read(files[index]);
    while (count)
    {
      count = printline_in_file(fd);
      io_putchar(1, '\n');
    }
    fs_closefile(fd);
    index++;
  }
  return (0);
}

int printline_in_file(int fd)
{
  char *str;
  char *hex;
  int index;

  index = 0;
  str = malloc(sizeof(char) * 17);
  getstr(fd, str, 16);
  while (index < 16 && str[index])
  {
    hex = str_tobase(str[index], "0123456789ABCDEF"); 
    if (str_lenght(hex) == 1)
      io_putchar(1, '0');
    io_putstr(1, hex);
    if (index % 2 == 1)
      io_putchar(1, ' ');
    free(hex);
    index++;
  }
  if (index)
  {
    io_putchar(1, ' ');
    printprintable(str);
  }
  return index;
}

void getstr(int fd, char *str, int count)
{
  int index;
  char c;

  index = 0;
  while (index < count && io_getchar(fd, &c) > 0)
  {
    str[index] = c;
    index++;
  }
  str[index] = 0;
}

void printprintable(char *str)
{
  int index;
  char c;

  index = 0;
  while (str[index])
  {
    c = '.';
    if (32 <= str[index] && str[index] <= 126)
      c = str[index];
    io_putchar(1, c);
    index++;
  }
}
