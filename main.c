#include "include/libfs.h"
#include "include/libio.h"

#define ERR_OF_MSG "ERROR: failed to open file"

char **parse_file_list(char **av, int ac);
void dump_file(int fd);

int main(int ac, char **av) {
  char **files;
  int file_count;
  int index;
  int fd;

  index = 0;
  file_count = ac - 1;
  files = parse_file_list(av, ac);
  while (index < file_count) {
    fd = fs_openfile_for_read(files[index]);
    if (fd) {
      dump_file(fd);
      fs_closefile(fd);
    } else {
      io_putstr(1, ERR_OF_MSG);
    }
    index++;
  }
  return (0);
}

char **parse_file_list(char **av, int ac) {
  char **files;

  files = 0;
  if (ac > 1)
    files = &av[1];
  return (files);
}

