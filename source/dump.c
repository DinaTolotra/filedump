#include "../include/libstr.h"
#include "../include/libio.h"
#include <stdlib.h>

#define LINE_CH_COUNT 16
#define INDEX_CH_COUNT 8

void read_line(int fd, int count, char **line, int *size);
void print_ch_index(int line, int ch_count);
void print_line_hex(char *line, int length, int count);
void print_alphanum(char *str, int length);
int is_alphanum(char c);

void dump_file(int fd) {
  char *line;
  int line_length;
  int line_count;

  line_length = 1;
  line_count = 0;
  while (line_length > 0) {
    read_line(fd, LINE_CH_COUNT, &line, &line_length);
    if (line_length) {
      print_ch_index(line_count, LINE_CH_COUNT);
      print_line_hex(line, line_length, LINE_CH_COUNT);
      print_alphanum(line, line_length);
      io_putchar(1, '\n');
    }
    line_count++;
    free(line);
  }
}

void read_line(int fd, int count, char **line, int *size) {
  int index;
  char c;

  index = 0;
  (*line) = malloc(sizeof(char) * count);
  while (io_getchar(fd, &c) == 1 && index < count) {
    if (c < 0)
      c = 0;    // not using null terminated string
    (*line)[index] = c;
    index++;
  }
  (*size) = index;
}

void print_ch_index(int line, int ch_count) {
  char *hex_ch_index;
  char *hex_base;
  int ch_index;
  int hex_len;
  int index;

  index = 0;
  hex_base = "0123456789abcdef";
  ch_index = (line * ch_count);
  hex_ch_index = str_tobase(ch_index, hex_base);
  hex_len = str_length(hex_ch_index);
  while (index < (INDEX_CH_COUNT - hex_len)) {
    io_putchar(1, '0');
    index++;
  }
  io_putstr(1, hex_ch_index);
  io_putstr(1, ": ");
  free(hex_ch_index);
}

void print_line_hex(char *line, int line_length, int count) {
  char *hex_base;
  char *hex;
  int index;
  int sp;

  sp = 0;
  index = 0;
  hex_base = "0123456789abcdef";
  while (index < count && index < line_length) {
    hex = str_tobase(line[index], hex_base);
    if (str_length(hex) < 2)
      io_putchar(1, '0');
    io_putstr(1, hex);
    if (sp)
      io_putchar(1, ' ');
    free(hex);
    sp = !sp;
    index++;
  }
  while (index < count) {
    io_putstr(1, "  ");
    if (sp)
      io_putchar(1, ' ');
    sp = !sp;
    index++;
  }
}

void print_alphanum(char *str, int length) {
  int index;
  char c;

  index = 0;
  while (index < length) {
    c = '.';
    if (is_alphanum(str[index]))
      c = str[index];
    io_putchar(1, c);
    index++;
  }
}

int is_alphanum(char c) {
  int lower;
  int upper;
  int num;

  lower = (c >= 'a' && c <= 'z');
  upper = (c >= 'A' && c <= 'Z');
  num = (c >= '0' && c <= '9');
  return (lower || upper || num);
}
