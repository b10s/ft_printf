/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aenshin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 22:34:41 by aenshin           #+#    #+#             */
/*   Updated: 2024/08/06 23:32:17 by aenshin          ###   ########.fr       */
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
#include <limits.h>

#include <stdlib.h>

static	short	int	ft_count_future_len(unsigned int n);
static	short	int	ft_count_future_len_hx(unsigned int n);

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

// WHAT static means here in return value?
// or it is function not value?
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

void	print_hx(unsigned char c, int first)
{
	char	*base;
	int		x;
	int		y;

	x = c / 16;
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
	}
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

void	print_in_hex(char *p, short sz)
{
	int		started;
	int		first;
	short	i;

	started = 0;
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
			print_hx(p[i], first);
		}
		first = 0;
		i--;
	}
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
	int				fd;
	char			*str;
	short			ptr_size;
	void			**ptr_in_mem;
	int				x;
	unsigned int	xx;
	char			*bigs;
	char			*tmp;
	char			c;

	fd = 1;
	va_start(ap, fmt);
	while (*fmt != 0)
	{
		if (*fmt == '%')
		{
			if (*(fmt + 1) == 'c' )
			{
				c = va_arg(ap, char);
				ft_putchar_fd(c, fd);
				fmt++;
			}
			else if (*(fmt + 1) == 's' )
			{
				str = va_arg(ap, char *);
				ft_putstr_fd(str, fd);
				fmt++;
			}
			else if (*(fmt + 1) == 'p')
			{
				ptr_size = sizeof(void *);
				ptr_in_mem = malloc(ptr_size);
				ft_bzero(ptr_in_mem, ptr_size);
				*ptr_in_mem = va_arg(ap, void *);
				ft_putchar_fd('0', fd);
				ft_putchar_fd('x', fd);
				print_in_hex(ptr_in_mem, ptr_size);
				fmt++;
			}
			else if (*(fmt + 1) == 'd' || *(fmt + 1) == 'i' )
			{
				x = va_arg(ap, int);
				str = ft_itoa(x);
				ft_putstr_fd(str, fd);
				free(str);
				fmt++;
			}
			else if (*(fmt + 1) == 'u')
			{
				x = va_arg(ap, int);
				str = ft_utoa(x);
				ft_putstr_fd(str, fd);
				free(str);
				fmt++;
			}
			else if (*(fmt + 1) == 'x')
			{
				xx = va_arg(ap, int);
				str = ft_utoax(xx);
				if (*str == '0')
				{
					ft_putstr_fd(str + 1, fd);
				}
				else
				{
					ft_putstr_fd(str, fd);
				}
				free(str);
				fmt++;
			}
			else if (*(fmt + 1) == 'X')
			{
				xx = va_arg(ap, int);
				str = ft_utoax(xx);
				bigs = malloc(ft_strlen(str));
				ft_strlcpy(bigs, str, ft_strlen(str) + 1);
				tmp = bigs;
				while (*tmp)
				{
					c = ft_toupper(*tmp);
					*tmp = c;
					tmp++;
				}
				if (*bigs == '0')
				{
					ft_putstr_fd(bigs + 1, fd);
				}
				else
				{
					ft_putstr_fd(bigs, fd);
				}
				free(str);
				free(bigs);
				fmt++;
			}
			else
			{
				ft_putchar_fd(*(fmt + 1), fd);
				fmt++;
			}
		}
		else
		{
			ft_putchar_fd(*fmt, fd);
		}
		fmt++;
	}
}

void main() {
  char c = 'x';
  char *str = "test";

	void *p = str;
	int x = 42;
	int y = -42;
	int z = 0;
	int m = 9;
	int n = 11;
	int mm = INT_MAX;
	int nn = INT_MIN;
	int umm = UINT_MAX;
	int mo = -1;

  char *fmt = "c: [%c], str: [%s], void * [%p], digits [%d %d %d %d %d %d %d %d %d] u: [%u %u %u %u %u %u %u %u %u] %w and %%\n";
	char *fmt2 = "x: [%x %x %x %x %x %x %x %x %x], X: [%X %X %X %X %X %X %X %X %X]\n";

	printf("orig: ");
   printf(fmt, c, str, p, x, y, z, m, n, mm, nn, mo, umm, x, y, z, m, n, mm, nn, mo, umm);
	 printf(fmt2, x, y, z, m, n, mm, nn, mo, umm, x, y, z, m, n, mm, nn, mo, umm);

	ft_printf("\nmy:   ");
ft_printf(fmt, c, str, p, x, y, z, m, n, mm, nn, mo, umm, x, y, z, m, n, mm, nn, mo, umm);
ft_printf(fmt2, x, y, z, m, n, mm, nn, mo, umm, x, y, z, m, n, mm, nn, mo, umm);

	//printf("size of void * is: [%d]\n", sizeof(void *));
}
