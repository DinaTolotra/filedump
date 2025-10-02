#ifndef LIBIO_H
#define LIBIO_H

#include <unistd.h>

int io_putchar(int fd, char c);
void io_putchar_hex(int fd, char c);
int io_putstr(int fd, char *str);
int io_putnb(int fd, int nb);

int io_getchar(int fd, char *c);

#endif // LIBIO_H
