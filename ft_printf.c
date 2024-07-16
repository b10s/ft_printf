// main part
// cspdiuxX%

// bonus
// 1) Manage any combination of the following flags: ’-0.’ and the field minimum widt under all conversions.
// or
// 2) Manage all the following flags: ’# +’ (Yes, one of them is a spa)

#include <stdio.h>
#include <stdarg.h>
#include "./libft/libft.h"

void
print_hx(char c) {
	char *base = "0123456789abcdef";
	int x = c / 16;
	int y = c % 16;

	ft_putchar_fd(base[y], 1);
	ft_putchar_fd(base[x], 1);
}

void
print_in_hex(char *p, short sz)
{
	printf("((%p))", *p);
	for (short i=0; i < sz; i++) {
		printf("(%d)", p[i]);
		print_hx(p[i]);
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
				printf("1. [%p]\n", *ptr_in_mem);
				ft_bzero(ptr_in_mem, ptr_size);
				printf("2. [%p]\n", *ptr_in_mem);
				*ptr_in_mem = va_arg(ap, void *);
				printf("3. [%p]\n", *ptr_in_mem);
				ft_putchar_fd('0', fd);
				ft_putchar_fd('x', fd);
				print_in_hex(ptr_in_mem, ptr_size);
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
  char *fmt = "c: [%c], str: [%s], void * [%p], digit [%d] %w and %%\n";
  printf(fmt, c, str, p, x);
  ft_printf(fmt, c, str, p, x);

	printf("size of void * is: [%d]\n", sizeof(void *));
}
