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
	res = printf("' %.1d '", 0);
	printf("res: [%d]\n", res);
	printf("\n[my]\n");
	res = ft_printf("' %.1d '", 0);
	printf("res: [%d]\n", res);
	return (0);
}

/*
	print(" %.1d ", 0)
*/
