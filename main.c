#include <stdio.h> //remove me!
#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>
#include <limits.h>

#include "./ft_printf.h"

int main() {
  char c = 'x';
  char *str = "test";

	void *p = str;
	int x = 42;
	int y = -42;
	int z = 0;
	int m = 9;
	int n = 11;
	int mm = INT_MAX;
	int nn = INT_MIN;
	int umm = UINT_MAX;
	int mo = -1;

  char *fmt = "c: [%c], str: [%s], void * [%p], digits [%d %d %d %d %d %d %d %d %d] u: [%u %u %u %u %u %u %u %u %u] %w and %%\n";
	char *fmt2 = "x: [%x %x %x %x %x %x %x %x %x], X: [%X %X %X %X %X %X %X %X %X]\n";
	char *fmtb = "x: [%#x %#x %#x %#x %#x %#x %#x %#x %#x], X: [%#X %#X %#X %#X %#X %#X %#X %#X %#X]\n";

	int res;

	printf("orig: ");
   res = printf(fmt, c, str, p, x, y, z, m, n, mm, nn, mo, umm, x, y, z, m, n, mm, nn, mo, umm);
	 printf("res [%d]\n", res);
	 res = printf(fmt2, x, y, z, m, n, mm, nn, mo, umm, x, y, z, m, n, mm, nn, mo, umm);
	 printf("res [%d]\n", res);
	 res = printf(fmtb, x, y, z, m, n, mm, nn, mo, umm, x, y, z, m, n, mm, nn, mo, umm);
	 printf("res [%d]\n", res);

	ft_printf("\nmy:   ");
res = ft_printf(fmt, c, str, p, x, y, z, m, n, mm, nn, mo, umm, x, y, z, m, n, mm, nn, mo, umm);
	 printf("res [%d]\n", res);
res = ft_printf(fmt2, x, y, z, m, n, mm, nn, mo, umm, x, y, z, m, n, mm, nn, mo, umm);
	 printf("res [%d]\n", res);
res = ft_printf(fmtb, x, y, z, m, n, mm, nn, mo, umm, x, y, z, m, n, mm, nn, mo, umm);
	 printf("res [%d]\n", res);

	//printf("size of void * is: [%d]\n", sizeof(void *));
	 return (0);
}
