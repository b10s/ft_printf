// main part
// cspdiuxX%
// c - char: DONE
// s - string: DONE
// p - void *: DONE
// d - int: DONE
// i - int: DONE
// u - int as unsigned int: DONE
// x - int as unsigned in hex: DONE
// X - int as unsigned in HEX: DONE 
// % - % itself: DONE

// bonus
// 1) Manage any combination of the following flags: ’-0.’ and the field minimum widt under all conversions.
// or
// 2) Manage all the following flags: ’# +’ (Yes, one of them is a spa)

#include <stdio.h>
#include <stdarg.h>
#include "./libft/libft.h"
#include <limits.h>

#include <stdlib.h>

static	short	int	ft_count_future_len(unsigned int n);
static	short	int	ft_count_future_len_hx(unsigned int n);

char *
	ft_utoax(unsigned int n) {
	unsigned long	x;
	short int		len;
	short int		i;
	char			*res;
	char *base = "0123456789abcdef";
	/*
	int x = c / 16;
	int y = c % 16;
	ft_putchar_fd(base[y], 1);
	 */

	x = n;
	res = NULL;
	// TODO: leading zero - check and calculate len or assign \0 by i not by len
	len = ft_count_future_len_hx(n);
	len = len*2;
	res = malloc(len + 1);
	if (res == NULL)
		return (NULL);
	i = len - 1;
	while (i >= 0)
	{
		int b = x % 256;

		int xx = b / 16;
		int yy = b % 16;
		res[i] = base[yy];
		i--;
		res[i] = base[xx];
		i--;

		x = x / 256;
	}

	res[len] = '\0';
	return (res);
}

char *
	ft_utoa(unsigned int n) {
	unsigned long	x;
	short int		len;
	short int		i;
	char			*res;

	x = n;
	res = NULL;
	len = ft_count_future_len(n);
	res = malloc(len + 1);
	if (res == NULL)
		return (NULL);
	i = 0;
	while (++i <= len)
	{
		res[len - i] = '0' + x % 10;
		x = x / 10;
	}
	res[len] = '\0';
	return (res);
}

// WHAT static means here in return value?
// or it is function not value?
static short int
	ft_count_future_len_hx(unsigned int n) {
	short int	res;

	if (n == 0)
		return (1);
	res = 0;
	while (n != 0)
	{
		res++;
		n = n / 256;
	}
	return (res);
}

static short int
	ft_count_future_len(unsigned int n) {
	short int	res;

	if (n == 0)
		return (1);
	res = 0;
	while (n != 0)
	{
		res++;
		n = n / 10;
	}
	return (res);
}

void
print_hx(unsigned char c, int first) {
	char *base = "0123456789abcdef";
	int x = c / 16;
	int y = c % 16;

	if ( first == 1 && c < 16) {
		ft_putchar_fd(base[y], 1);
	} else {
		ft_putchar_fd(base[x], 1);
		ft_putchar_fd(base[y], 1);
	}
}

void
print_big_hx(unsigned char c, int first) {
	char *base = "0123456789ABCDEF";
	int x = c / 16;
	int y = c % 16;

	if ( first == 1 && c < 16) {
		ft_putchar_fd(base[y], 1);
	} else {
		ft_putchar_fd(base[x], 1);
		ft_putchar_fd(base[y], 1);
	}
}

void
print_in_hex(char *p, short sz)
{
	//printf("((%p))", *p);
	int started = 0;
	int first = 0;
	for (short i=sz-1; i >= 0; i--) {
		if ( p[i] != 0 && started == 0 ) {
			started = 1;
			first = 1;
		}
		if (started == 1 ) {
			//printf("(%d)", p[i]);
			print_hx(p[i], first);
		}
		first = 0;
	}
}


// 1. parse fmt and call appropriate function to get arg and print it
// 2. write functions for each specifier
// 3. run against public tester
// 4. check upstream implementation
// 5. check 42 public repo implementation
int
ft_printf(const char *fmt, ...)
{
  va_list ap;
  va_start(ap, fmt);
  // is fd int or another type?
  int fd = 1;

  for (; *fmt !=0; fmt++) {
    if (*fmt == '%') {
      // print a char
      if (*(fmt+1) == 'c' ) {
        char c = va_arg(ap, char);
        ft_putchar_fd(c, fd);
        fmt++;
      // print a string
      } else if (*(fmt+1) == 's' ){
        char *str = va_arg(ap, char*);
        ft_putstr_fd(str, fd);
        fmt++;
			// print a void *
			// TODO: check NULL ptr, other edge cases
      } else if (*(fmt+1) == 'p') {
				short ptr_size = sizeof(void *);
				void **ptr_in_mem = malloc(ptr_size);
				//printf("1. [%p]\n", *ptr_in_mem);
				ft_bzero(ptr_in_mem, ptr_size);
				//printf("2. [%p]\n", *ptr_in_mem);
				*ptr_in_mem = va_arg(ap, void *);
				//printf("3. [%p]\n", *ptr_in_mem);
				ft_putchar_fd('0', fd);
				ft_putchar_fd('x', fd);
				print_in_hex(ptr_in_mem, ptr_size);
				fmt++;
			// what is d and what is size of d?
			// what type in c for d?
			// from man 3 printf we assume arg is int
			// converted to signed decimal
			// what difference between d and i ?
      } else if (*(fmt+1) == 'd' || *(fmt+1) == 'i' ) {
				int x = va_arg(ap, int);
				char *str = ft_itoa(x);
        ft_putstr_fd(str, fd);
				free(str);
				fmt++;
      } else if (*(fmt+1) == 'u') {
				int x = va_arg(ap, int);
				// how to represent int as unsigned if it is negative?
				// A: rely on type conversion of C? unsigned int = int (size should be enough)
				// INT_MIN?
				char *str = ft_utoa(x);
        ft_putstr_fd(str, fd);
				free(str);
				fmt++;
      } else if (*(fmt+1) == 'x') {
				unsigned int x = va_arg(ap, int);
				char *str = ft_utoax(x);
				if (*str == '0') {
        	ft_putstr_fd(str+1, fd);
				} else {
        	ft_putstr_fd(str, fd);
				}
				free(str);
				fmt++;
      } else if (*(fmt+1) == 'X') {
				unsigned int x = va_arg(ap, int);
				char *str = ft_utoax(x);
				//TODO: check for null and in other places read code check for return values for malloc and other funcs
				char *bigS = malloc(ft_strlen(str));
				// TODO check for return value
				ft_strlcpy(bigS, str, ft_strlen(str)+1);
				char *tmp;
				tmp = bigS;
				char c;
				//printf("s [%s]\n", tmp);
				while(*tmp) {
					c  = ft_toupper(*tmp);
					*tmp = c;
					tmp++;
				}
				if (*bigS == '0') {
        	ft_putstr_fd(bigS+1, fd);
				} else {
        	ft_putstr_fd(bigS, fd);
				}
				free(str);
				free(bigS);
				fmt++;
			// prints %% and unknown like %w
			} else {
      	ft_putchar_fd(*(fmt+1), fd);
				fmt++;
			}
    } else {
      ft_putchar_fd(*fmt, fd);
    }
  }
}



void main() {
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

	printf("orig: ");
   printf(fmt, c, str, p, x, y, z, m, n, mm, nn, mo, umm, x, y, z, m, n, mm, nn, mo, umm);
	 printf(fmt2, x, y, z, m, n, mm, nn, mo, umm, x, y, z, m, n, mm, nn, mo, umm);

	ft_printf("\nmy:   ");
ft_printf(fmt, c, str, p, x, y, z, m, n, mm, nn, mo, umm, x, y, z, m, n, mm, nn, mo, umm);
ft_printf(fmt2, x, y, z, m, n, mm, nn, mo, umm, x, y, z, m, n, mm, nn, mo, umm);

	//printf("size of void * is: [%d]\n", sizeof(void *));
}
