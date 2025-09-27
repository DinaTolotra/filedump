#include "./include/libio.h"
#include <fcntl.h>

char *parse_arg(int ac, char **av);
int open_file(char *file);

int main(int ac, char **av)
{
	char c;
	int fd;
  char *file;
	
  file = parse_arg(ac, av);
	fd = open_file(file);
  if (fd >= 0)
  {
    while (fd >= 0 && io_getchar(fd, &c) > 0)
      io_putchar(1, c);
    close(fd);
  }
  else
  {
    io_putstr(1, "Failed to open file\n");
  }
	return (0);
}

int open_file(char *file)
{
  int fd;

  fd = open(file, O_RDONLY);
  if (fd < 0)
    fd = -1;
  return (fd);
}

char *parse_arg(int ac, char **av)
{
  char *file;

  file = 0;
  if (ac > 1)
    file = av[1];
  return (file);
}
