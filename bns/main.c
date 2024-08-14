#include <stdio.h>
#include "./ft_printf_bonus.h"

int main() {
	int res;

	printf("[origin]\n");
	//res =    printf("'%#-00#10d', '%#-10s', '%10p'\n", 42, "foo");
	res =    printf("'%10s'\n", "foo");
	printf("res: [%d]\n", res);

	printf("\n[my]\n");
	res =    ft_printf("'%10s'\n", "foo");
	printf("res: [%d]\n", res);
	return (0);
}
