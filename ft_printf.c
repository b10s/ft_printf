/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aenshin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 22:34:41 by aenshin           #+#    #+#             */
/*   Updated: 2024/08/11 20:02:34 by aenshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// main part
// cspdiuxX%
// c - char: DONE
// s - string: DONE
// p - void *: DONE
// d - int: DONE
// i - int: DONE
// u - int as unsigned int: DONE
// x - int as unsigned in hex: DONE
// X - int as unsigned in HEX: DONE 
// % - % itself: DONE

// bonus
// 1) Manage any combination of the following flags: 
// ’-0.’ and the field minimum widt under all conversions.
// or
// 2) Manage all the following flags: ’# +’ (Yes, one of them is a spa)

#include <stdio.h>
#include <stdarg.h>
#include "./libft/libft.h"
#include "./ft_printf.h"
#include <limits.h>
#include <stdlib.h>
#include <unistd.h>

//TODO: separate functions to utils, specifiers, etc

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

// 1. parse fmt and call appropriate function to get arg and print it
// 2. write functions for each specifier
// 3. run against public tester
// 4. check upstream implementation
// 5. check 42 public repo implementation
//

// TODO: check NULL ptr, other edge cases
int	ft_printf(const char *fmt, ...)
{
	va_list			ap;
	char			*str;
	int				x;
	int				cnt;
	short			alt;

	cnt = 0;
	va_start(ap, fmt);
	while (*fmt != 0)
	{
		alt = 0;
		if (*fmt == '%')
		{
			if (*(fmt + 1) == '#')
			{
				alt = 1;
				fmt++;
			}
			if (*(fmt + 1) == 'c' )
			{
				ft_putchar_fd((char)va_arg(ap, int), STDOUT_FILENO);
				cnt++;
			}
			else if (*(fmt + 1) == 's' )
			{
				str = va_arg(ap, char *);
				cnt = cnt + ft_strlen(str);
				ft_putstr_fd(str, STDOUT_FILENO);
			}
			else if (*(fmt + 1) == 'p')
				cnt = cnt + voidpspec(ap);
			else if (*(fmt + 1) == 'd' || *(fmt + 1) == 'i' )
			{
				x = va_arg(ap, int);
				str = ft_itoa(x);
				cnt = cnt + ft_strlen(str);
				ft_putstr_fd(str, STDOUT_FILENO);
				free(str);
			}
			else if (*(fmt + 1) == 'u')
			{
				x = va_arg(ap, int);
				str = ft_utoa(x);
				// these three lines can be separated as function?
				cnt = cnt + ft_strlen(str);
				ft_putstr_fd(str, STDOUT_FILENO);
				free(str);
			}
			else if (*(fmt + 1) == 'x')
				cnt = cnt + hexspecifier(ap, alt);
			else if (*(fmt + 1) == 'X')
				cnt = cnt + bigxspecifier(ap, alt);
			else
			{
				ft_putchar_fd(*(fmt + 1), STDOUT_FILENO);
				cnt++;
			}
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
