/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aenshin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 00:22:09 by aenshin           #+#    #+#             */
/*   Updated: 2024/08/13 01:00:55 by aenshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// WHAT static means here in return value?
// or it is function not value?
#include <stdlib.h>
#include "./libft/libft.h"

int	print_hx(unsigned char c, int first)
{
	char	*base;
	int		x;
	int		y;
	int		cnt;

	x = c / 16;
	cnt = 1;
	y = c % 16;
	base = "0123456789abcdef";
	if (first == 1 && c < 16)
	{
		ft_putchar_fd(base[y], 1);
	}
	else
	{
		ft_putchar_fd(base[x], 1);
		ft_putchar_fd(base[y], 1);
		cnt = 2;
	}
	return (cnt);
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

char *
	ft_utoax(unsigned int n) {
	short int		len;
	short int		i;
	char			*res;
	char			*base;
	int				b;

	base = "0123456789abcdef";
	res = NULL;
	len = ft_count_future_len_hx(n);
	len = len * 2;
	res = malloc(len + 1);
	if (res == NULL)
		return (NULL);
	i = len - 1;
	while (i >= 0)
	{
		b = n % 256;
		res[i] = base[b % 16];
		i--;
		res[i] = base[b / 16];
		i--;
		n = n / 256;
	}
	res[len] = '\0';
	return (res);
}
