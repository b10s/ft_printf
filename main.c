#include <stdio.h> //remove me!
#include <unistd.h>
#include <stdarg.h>
int main() {
	printf("hi\n");
}

int ft_printf(const char *, ...);

int ft_printf(const char * args, ...) {
	write(1, (const void *)args, 3);
	return 1;
}
