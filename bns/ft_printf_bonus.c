/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aenshin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 22:34:41 by aenshin           #+#    #+#             */
/*   Updated: 2024/08/13 20:50:33 by aenshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>
#include "./libft/libft.h"
#include "./ft_printf_bonus.h"
#include <limits.h>
#include <stdlib.h>
#include <unistd.h>

void	print_big_hx(unsigned char c, int first)
{
	char	*base;
	int		x;
	int		y;

	x = c / 16;
	y = c % 16;
	base = "0123456789ABCDEF";
	if (first == 1 && c < 16)
	{
		ft_putchar_fd(base[y], 1);
	}
	else
	{
		ft_putchar_fd(base[x], 1);
		ft_putchar_fd(base[y], 1);
	}
}

int	print_in_hex(char *p, short sz)
{
	int		started;
	int		first;
	short	i;
	int		cnt;

	started = 0;
	cnt = 0;
	first = 0;
	i = sz - 1;
	while (i >= 0)
	{
		if (p[i] != 0 && started == 0)
		{
			started = 1;
			first = 1;
		}
		if (started == 1)
		{
			cnt = cnt + print_hx(p[i], first);
		}
		first = 0;
		i--;
	}
	return (cnt);
}

// 00000001 - #
// 00000010 - space
// 00000100 - +
// 00000101 - # and +
// ...
// Q: why I can not pass &fmt and modify fmt here?
unsigned short	parse_flags(const char *fmt)
{
	unsigned short	res;

	fmt++;
	res = 0;
	while (*fmt == '#' || *fmt == ' ' || *fmt == '+')
	{
		if (*fmt == '#')
			res = res | FLAG_ALT;
		if (*fmt == ' ')
			res = res | FLAG_BLANK;
		if (*fmt == '+')
			res = res | FLAG_SIGN;
		fmt++;
	}
	return (res);
}

size_t	count_flags(const char *fmt)
{
	size_t	res;

	fmt++;
	res = 0;
	while (*fmt == '#' || *fmt == ' ' || *fmt == '+')
	{
		fmt++;
		res++;
	}
	return (res);
}

int	ft_printf(const char *fmt, ...)
{
	unsigned short	flags;
	va_list			ap;
	int				cnt;

	cnt = 0;
	va_start(ap, fmt);
	while (*fmt != 0)
	{
		if (*fmt == '%')
		{
			flags = parse_flags(fmt);
			fmt = fmt + count_flags(fmt);
			cnt = cnt + allspecifiers(ap, fmt, flags);
			fmt++;
		}
		else
		{
			ft_putchar_fd(*fmt, STDOUT_FILENO);
			cnt++;
		}
		fmt++;
	}
	va_end(ap);
	return (cnt);
}
