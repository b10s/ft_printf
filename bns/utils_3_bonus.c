/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_3_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aenshin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 00:57:13 by aenshin           #+#    #+#             */
/*   Updated: 2024/08/19 02:00:35 by aenshin          ###   ########.fr       */
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
	int		needed;
	int		d;
	char	*res;

	d = 0;
	while (ft_ishexdigit(*str++))
		d++;
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
	while (needed-- > 0)
		*res++ = '0';
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
