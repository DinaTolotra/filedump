#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

char *parse_arg(int ac, char **av);
int file_get_char(int fd, char *c);
int open_file(char *file);
void put_char(char c);
void put_str(char *str);

int main(int ac, char **av)
{
	char c;
	int fd;
  char *file;
	
  file = parse_arg(ac, av);
	fd = open_file(file);
  if (fd >= 0)
  {
    while (fd >= 0 && file_get_char(fd, &c) > 0)
      put_char(c);
    close(fd);
  }
  else
  {
    put_str("Failed to open file\n");
  }
	return (0);
}

void put_char(char c)
{
	write(1, &c, 1);
}

void put_str(char *str)
{
  int index;

  index = 0;
  while (str[index])
  {
    putchar(str[index]);
    index++;
  }
}

int file_get_char(int fd, char *c)
{
	return read(fd, c, 1);
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
