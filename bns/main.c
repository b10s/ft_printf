#include <stdio.h>
#include "./ft_printf_bonus.h"

int main() {
	int res;

	printf("[origin]\n");
	res = printf(" %.2x ", -1);
	printf("res: [%d]\n", res);

	printf("\n[my]\n");
res = ft_printf(" %.2x ", -1);
	printf("res: [%d]\n", res);

	return (0);
}

/*
	        TEST(98, print(" %.2x ", -1));
        TEST(101, print(" %.2x ", 10));
*/
