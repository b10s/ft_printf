#include <stdio.h>
#include "./ft_printf_bonus.h"

int main() {
	int res;

	printf("[origin]\n");
	res = printf("'%04d'", -14);
	printf("res: [%d]\n", res);

	printf("\n[my]\n");
	res = ft_printf("'%04d'", -14);
	printf("res: [%d]\n", res);

	return (0);
}

/*
90, 91
        TEST(90, print(" %-4u ", 9));
        TEST(91, print(" %-1u ", 10));

*/
