#include "../include/libstr.h"

#define ABS(val) (val < 0)? -val: val

int _is_basevalid(char *base);
void _swap(char *a, char *b);
void _create_res(char **res, char *base);
void _to_positive(long *lnb, char *res, int *index);

void str_reverse(char *str, int beg, int end)
{
  while (beg < end)
    _swap(&str[beg++], &str[end--]);
}

int str_find(char c, char *str)
{
  int index;

  index = 0;
  while (str[index] && str[index] != c)
    index++;
  if (str[index] == 0)
    index = -1;
  return (index);
}

int _is_basevalid(char *base)
{
  int valid;
  int index;
  int repeat;

  valid = 1;
  index = 0;
  while (base[index])
  {
    repeat = (str_find(base[index], &base[index + 1]) != -1);
    valid = valid && (base[index] != '-');
    valid = valid && (base[index] != '+');
    valid = valid && (!repeat);
    index++;
  }
  valid = valid && (index > 1);
  return (valid);
}

void _swap(char *a, char *b)
{
  char temp;

  temp = *a;
  *a = *b;
  *b = temp;
}

void _create_res(char **res, char *base)
{
  (*res) = malloc(sizeof(char) * 34);
  (*res)[0] = base[0];
  (*res)[1] = 0;
}

void _to_positive(long *lnb, char *res, int *index)
{
  if ((*lnb) < 0)
  {
    res[(*index)] = '-';
    (*lnb) = -(*lnb);
    (*index)++;
  }
}

int str_length(char *str)
{
  int length;

  length = 0;
  while (str[length])
    length++;
  return length;
}

int str_frombase(char *nb, char *base)
{
  long lnb;
  int sign;
  int index;
  int val;
  int baseval;

  if (!_is_basevalid(base))
    return (0);
  baseval = str_length(base);
  index = 0;
  sign = 1;
  lnb = 0;
  if (nb[index] == '-')
    sign = -1;
  val = str_find(nb[index], base);
  while (val != -1)
  {
    lnb = lnb * baseval;
    lnb = lnb + val;
    index++;
  }
  return (sign * lnb);
}

char *str_tobase(int nb, char *base)
{
  long lnb;
  char *res;
  int index;
  int baseval;
  int beg;

  if (!_is_basevalid(base))
    return (0);
  lnb = nb;
  index = 0;
  baseval = str_length(base);
  _create_res(&res, base);
  _to_positive(&lnb, res, &index);
  beg = index;
  while (lnb)
  {
    res[index] = base[lnb % baseval];
    lnb = lnb / baseval;
    res[index + 1] = 0;
    index++;
  }
  str_reverse(res, beg, index - 1);
  return (res);
}
