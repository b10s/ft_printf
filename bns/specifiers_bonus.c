/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specifiers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aenshin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 17:26:00 by aenshin           #+#    #+#             */
/*   Updated: 2024/08/18 23:00:14 by aenshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdlib.h>
#include "./libft/libft.h"
#include "./ft_printf_bonus.h"
#include <unistd.h>
#include <stdio.h>

int	voidpspec(va_list ap, int width, int flags)
{
	short			ptr_size;
	void			**ptr_in_mem;
	int				cnt;
	char 			*str;
	char			*tmp;

	ptr_size = sizeof(void *);
	ptr_in_mem = malloc(ptr_size);
	if (ptr_in_mem == NULL)
		return (0);
	ft_bzero(ptr_in_mem, ptr_size);
	*ptr_in_mem = va_arg(ap, void *);
	tmp = NULL;
	if (*ptr_in_mem == NULL)
		str = "(nil)";
	else
	{
		str = sprint_in_hex((char *)ptr_in_mem, ptr_size);
		if (str == NULL)
			return (0);
		tmp = str;
		while (*(str + 1) == '0')
		{
			str[0] = '0';
			str[1] = 'x';
			str++;
		}
		str--;
	}
	cnt = ft_print_str_in_width(str, width, flags, 0);
	//ft_putstr_fd("kek", STDOUT_FILENO);
	free(tmp);
	free(ptr_in_mem);
	return (cnt);
}

// modifies in place the same string
// TODO: can be used in to_hex to replce base?
void ft_toupper_str(char *str)
{
	while (*str)
	{
		*str = ft_toupper(*str);
		str++;
	}
}

int	ft_print_toupper_str(char *str)
{
	char			*bigs;
	char			*tmp;
	int				cnt;

	cnt = 0;
	bigs = malloc(ft_strlen(str) + 1);
	if (bigs == NULL)
		return (0);
	ft_strlcpy(bigs, str, ft_strlen(str) + 1);
	tmp = bigs;
	while (*tmp)
	{
		*tmp = ft_toupper(*tmp);
		tmp++;
	}
	if (*bigs == '0')
	{
		ft_putstr_fd(bigs + 1, STDOUT_FILENO);
		cnt = -1;
	}
	else
		ft_putstr_fd(bigs, STDOUT_FILENO);
	free(bigs);
	return (cnt);
}

int	bigxspecifier(va_list ap, unsigned short flags)
{
	unsigned int	xx;
	char			*str;
	int				cnt;

	cnt = 0;
	xx = va_arg(ap, int);
	str = ft_utoax(xx);
	if (str == NULL)
		return (0);
	cnt = ft_strlen(str);
	if (xx != 0)
	{
		if ((flags & FLAG_ALT) != 0)
		{
			ft_putstr_fd("0X", STDOUT_FILENO);
			cnt = cnt + 2;
		}
	}
	cnt = cnt + ft_print_toupper_str(str);
	free(str);
	return (cnt);
}

int	hexspecifier(va_list ap, int width, unsigned short flags, int big, int prec)
{
	unsigned int	xx;
	char			*str;
	int				cnt;
	char			*buf;
	char			*tmp;

	cnt = 0;
	xx = va_arg(ap, int);
	str = ft_utoax(xx);
	if (str == NULL)
		return (0);
	buf = malloc(ft_strlen(str)+3);
	if (buf == NULL)
		return (0);
	tmp = buf;
	buf[0] = '0';
	buf[1] = '0';
	ft_strlcpy(buf+2, str, ft_strlen(str) + 1);
	while (*(buf + 1) == '0')
	{
		buf[0] = '0';
		buf[1] = 'x';
		buf++;
	}
	buf--;

	if (big == 1)
	{
		ft_toupper_str(buf);
		ft_toupper_str(str);
	}
	if (xx != 0 && (flags & FLAG_ALT) != 0)
		cnt = ft_print_str_in_width_nums(buf, width, flags, prec);
	else if (*str == '0')
		cnt = ft_print_str_in_width_nums(str + 1, width, flags, prec);
	else
		cnt = ft_print_str_in_width_nums(str, width, flags, prec);

	free(tmp);
	free(str);
	return (cnt);
}

int	strspecifier(va_list	ap, int width, int flags, int prec)
{
	char	*str;
	int		cnt;

	cnt = 0;
	str = va_arg(ap, char *);
	if (str == NULL)
		str = "(null)";
	cnt = cnt + ft_print_str_in_width(str, width, flags, prec);
	return (cnt);
}

// TODO: add to %p (nil)

// TODO: after or before (minus flag)
// 0 for interegers or so
int ft_print_str_in_width(char *str, int width, int flags, int prec)
{
	int delta;
	int len;

	len = ft_strlen(str);
	// prec
	if ((flags & FLAG_PRECISION_ARG) != 0 && prec >= 0 ) {
		//printf("prec is [%d], len [%d]\n", prec, len);
		if (len >= prec) {
			int i = prec;
			while (i > 0) {
				ft_putchar_fd(*str, STDOUT_FILENO);
				i--;
				str++;
			}
			return (prec);
		}
	}

	if (len > width)
	{
		ft_putstr_fd(str, STDOUT_FILENO);
		return (len);
	}
	else
	{
		delta = width - len;
		if ((flags & FLAG_LEFT_ALIGN) != 0)
			ft_putstr_fd(str, STDOUT_FILENO);
		while (delta > 0)
		{
			ft_putchar_fd(' ', STDOUT_FILENO);
			delta--;
		}
		//ft_putchar_fd('K', STDOUT_FILENO);
		if ((flags & FLAG_LEFT_ALIGN) == 0)
			ft_putstr_fd(str, STDOUT_FILENO);
		return (width);
	}
}


int
	ft_ishexdigit(int c) {
	if (c >= (int) '0' && c <= (int) '9')
	{
		return (1);
	}
	if (c >= (int) 'a' && c <= (int) 'f')
	{
		return (1);
	}
	if (c >= (int) 'A' && c <= (int) 'F')
	{
		return (1);
	}
	return (0);
}

		// pad with 0 and then pad with spaces
		// di, if there is sign, pad after sign
		// xX pad after 0x
		// u just pad
char * ft_pad_with_zeroes(char *str, int prec) {
	char *res;
	char *tmp;
	int	pre;

	pre = 0;
	tmp = str;
	if (*str == '-') {
		pre++;
		str++;
	}

	// it is hex
	if (ft_strlen(str) > 2) {
		if (str[0] == '0' && str[1] == 'x') {
			str = str + 2;
			pre = pre + 2;
		}
	}

	int d = 0;
	while (ft_ishexdigit(*str)) {
		d++;
		str++;
	}

	int needed = prec - d;
	//printf("prec: [%d], needed: [%d]\n", prec, needed);

	if (needed < 0)
		needed = 0;

	res = malloc(ft_strlen(str) + needed + 1);
	if (res == NULL)
		return (NULL);
	str = tmp;
	tmp = res;
	while(pre > 0) {
		*res = *str;
		str++;
		res++;
		pre--;
	}
	while (needed > 0) {
		*res = '0';
		res++;
		needed--;
	}
	ft_strlcpy(res, str, ft_strlen(str) + 1);

	//printf("padded tmp: [%s]\n", tmp);
	return (tmp);
}

// %05.7d, -7

// 0x
// sign - of +
int ft_print_str_in_width_nums(char *str, int width, int flags, int prec)
{
	//printf("func prec: [%d]\n", prec);
	int delta;
	int len;
	char	c;

	len = ft_strlen(str);
	// TODO add here precicision flag 
	//printf("flags: [%d]\n", flags);
	if ((flags & FLAG_LEADING_ZERO) != 0 && (flags & FLAG_SIGN) == 0 && (flags & FLAG_PRECISION_ARG) == 0 )
	{
		c = '0';
	}
	else
		c = ' ';

	if ( (flags & FLAG_PRECISION_ARG) !=0 )
	{
		// pad with 0 and then pad with spaces
		// di, if there is sign, pad after sign
		// xX pad after 0x
		// u just pad
		if (width > prec)
		{
			char * padded = ft_pad_with_zeroes(str, prec);
			//if (padded == NULL)
				// return 0/NULL
			free(padded);
			// maybe keep running to next branch since we need to do min width logic
			return (123);
		}
		else
		{
			// just pad with 0
			char * padded = ft_pad_with_zeroes(str, prec);
			if (padded == NULL)
				return (0);
			// print an return
			len = ft_strlen(padded);
			ft_putstr_fd(padded, STDOUT_FILENO);
			free(padded);
			return (len);
		}
	} else {
		// go here if no precision is presented

		if (len > width)
		{
			ft_putstr_fd(str, STDOUT_FILENO);
			return (len);
		}
		else
		{
			delta = width - len;
			if ((flags & FLAG_LEFT_ALIGN) != 0)
			{
				ft_putstr_fd(str, STDOUT_FILENO);
				while (delta > 0)
				{
					ft_putchar_fd(' ', STDOUT_FILENO);
					delta--;
				}
			}
			else
			{
				if (*str == '-' && c == '0')
				{
					ft_putchar_fd('-', STDOUT_FILENO);
					str++;
				}
				while (delta > 0)
				{
					ft_putchar_fd(c, STDOUT_FILENO);
					delta--;
				}
				ft_putstr_fd(str, STDOUT_FILENO);
			}
			return (width);
		}
	}
}
