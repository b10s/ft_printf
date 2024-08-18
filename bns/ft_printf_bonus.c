/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aenshin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 22:34:41 by aenshin           #+#    #+#             */
/*   Updated: 2024/08/18 23:18:18 by aenshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>
#include "./libft/libft.h"
#include "./ft_printf_bonus.h"
#include <limits.h>
#include <stdlib.h>
#include <unistd.h>

void	sprint_hx(unsigned char c, char *str)
{
	char	*base;
	int		x;
	int		y;

	x = c / 16;
	y = c % 16;
	base = "0123456789abcdef";
	str[0] = base[x];
	str[1] = base[y];
}

char	*sprint_in_hex(char *p, short sz)
{
	short	i;
	char	*str;
	char	*res;

	i = sz - 1;
	str = malloc(sz * 2 + 3);
	if (str == NULL)
		return (0);
	res = str;
	str[0] = '0';
	str[1] = '0';
	str = str + 2;
	while (i >= 0)
	{
		sprint_hx(p[i], str);
		str = str + 2;
		i--;
	}
	*str = 0;
	return (res);
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

	res = 0;
	while (*fmt == '#' || *fmt == ' ' || *fmt == '+'
		|| *fmt == '-' || *fmt == '0')
	{
		if (*fmt == '#')
			res = res | FLAG_ALT;
		if (*fmt == ' ')
			res = res | FLAG_BLANK;
		if (*fmt == '+')
			res = res | FLAG_SIGN;
		if (*fmt == '-')
			res = res | FLAG_LEFT_ALIGN;
		if (*fmt == '0')
			res = res | FLAG_LEADING_ZERO;
		fmt++;
	}
	return (res);
}

size_t	count_flags(const char *fmt)
{
	size_t	res;

	res = 0;
	while (*fmt == '#' || *fmt == ' ' || *fmt == '+'
		|| *fmt == '-' || *fmt == '0')
	{
		fmt++;
		res++;
	}
	return (res);
}

void	flg(const char **fmt, unsigned short *flags, int *width, int *prec)
{
	*flags = parse_flags(*fmt);
	*fmt = *fmt + count_flags(*fmt);
	*width = ft_atoi(*fmt);
	while (ft_isdigit(**fmt))
		(*fmt)++;
	if (**fmt == '.')
	{
		*flags = *flags | FLAG_PRECISION_ARG;
		(*fmt)++;
		*prec = ft_atoi(*fmt);
		while (ft_isdigit(**fmt))
			(*fmt)++;
	}
}

int	ft_printf(const char *fmt, ...)
{
	unsigned short	flags;
	va_list			ap;
	int				cnt;
	int				prec;
	int				width;

	cnt = 0;
	va_start(ap, fmt);
	while (*fmt != 0)
	{
		if (*fmt == '%')
		{
			fmt++;
			flg(&fmt, &flags, &width, &prec);
			cnt = cnt + allspecifiers(ap, fmt, flags, width, prec);
			fmt++;
		}
		else
		{
			ft_putchar_fd(*fmt++, STDOUT_FILENO);
			cnt++;
		}
	}
	va_end(ap);
	return (cnt);
}
