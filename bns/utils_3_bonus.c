/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_3_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aenshin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 00:57:13 by aenshin           #+#    #+#             */
/*   Updated: 2024/08/19 01:55:26 by aenshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./bns/ft_printf_bonus.h"

int	hexspecifier(va_list ap, int width, unsigned short flags, int prec)
{
	unsigned int	xx;
	char			*str;
	int				cnt;
	char			*buf;
	char			*tmp;

	cnt = 0;
	xx = va_arg(ap, int);
	str = ft_utoax(xx);
	buf = malloc(ft_strlen(str)+3);
	tmp = buf;
	buf[0] = '0';
	buf[1] = '0';
	ft_strlcpy(buf + 2, str, ft_strlen(str) + 1);
	movestr(&buf);
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

int	foobar(char *str, int len, int width, int flags)
{
	int	delta;

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
		if ((flags & FLAG_LEFT_ALIGN) == 0)
			ft_putstr_fd(str, STDOUT_FILENO);
		return (width);
	}
}

int	ft_print_str_in_width(char *str, int width, int flags, int prec)
{
	int	len;
	int	i;

	len = ft_strlen(str);
	if ((flags & FLAG_PRECISION_ARG) != 0 && prec >= 0)
	{
		if (len >= prec)
		{
			i = prec;
			while (i > 0)
			{
				ft_putchar_fd(*str, STDOUT_FILENO);
				i--;
				str++;
			}
			return (prec);
		}
	}
	return (foobar(str, len, width, flags));
}

char	*bz(char *str, int pre, int prec, char *tmp)
{
	int	needed;
	int	d;
	char	*res;

	d = 0;
	while (ft_ishexdigit(*str))
	{
		d++;
		str++;
	}
	needed = prec - d;
	if (needed < 0)
		needed = 0;
	res = malloc(ft_strlen(str) + needed + 1);
	str = tmp;
	tmp = res;
	while (pre > 0)
	{
		*res = *str;
		str++;
		res++;
		pre--;
	}
	while (needed > 0)
	{
		*res = '0';
		res++;
		needed--;
	}
	ft_strlcpy(res, str, ft_strlen(str) + 1);
	return (tmp);
}

char	*ft_pad_with_zeroes(char *str, int prec)
{
	char	*tmp;
	int		pre;

	pre = 0;
	tmp = str;
	if (*str == '-')
	{
		pre++;
		str++;
	}
	if (ft_strlen(str) > 2)
	{
		if (str[0] == '0' && str[1] == 'x')
		{
			str = str + 2;
			pre = pre + 2;
		}
	}
	tmp = bz(str, pre, prec, tmp);
	return (tmp);
}

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
