/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aenshin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 00:35:48 by aenshin           #+#    #+#             */
/*   Updated: 2024/08/19 02:04:52 by aenshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "./ft_printf_bonus.h"

int	main(void)
{
	int	res;

	printf("[origin]\n");
	res = printf("'%10.2x'\n", 42);
	printf("res: [%d]\n", res);
	printf("\n[my]\n");
res = ft_printf("'%10.2x'\n", 42);
	printf("res: [%d]\n", res);
	return (0);
}

/*
	        TEST(98, print(" %.2x ", -1));
        TEST(101, print(" %.2x ", 10));
*/
