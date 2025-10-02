#ifndef LIBSTR_H
#define LIBSTR_H

#include <stdlib.h>

int str_lenght(char *str);
int str_find(char c, char *str);
void str_reverse(char *str, int beg, int end);

char *str_tobase(int nb, char *base);
int str_frombase(char *nb, char *base);

#endif // LIBSTR_H
