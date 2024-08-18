/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_4_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aenshin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 02:00:18 by aenshin           #+#    #+#             */
/*   Updated: 2024/08/19 02:39:55 by aenshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./bns/ft_printf_bonus.h"

int	reallyonlyminlen(char *str, t_wp wp, int flags, char c)
{
	int		delta;
	int		len;

	len = ft_strlen(str);
	delta = wp.width - len;
	if ((flags & FLAG_LEFT_ALIGN) != 0)
	{
		ft_putstr_fd(str, STDOUT_FILENO);
		while (delta-- > 0)
			ft_putchar_fd(' ', STDOUT_FILENO);
	}
	else
	{
		if (*str == '-' && c == '0')
		{
			ft_putchar_fd('-', STDOUT_FILENO);
			str++;
		}
		while (delta-- > 0)
			ft_putchar_fd(c, STDOUT_FILENO);
		ft_putstr_fd(str, STDOUT_FILENO);
	}
	return (wp.width);
}

int	withminlen(char *str, int flags, t_wp wp, char c)
{
	char	*padded;
	int		len;

	padded = NULL;
	if ((flags & FLAG_PRECISION_ARG) != 0 && wp.prec < wp.width)
	{
		padded = ft_pad_with_zeroes(str, wp.prec);
		str = padded;
	}
	len = ft_strlen(str);
	if (len > wp.width)
	{
		ft_putstr_fd(str, STDOUT_FILENO);
		free(padded);
		return (len);
	}
	else
	{
		len = reallyonlyminlen(str, wp, flags, c);
		free(padded);
		return (len);
	}
}

int	ft_print_str_in_width_nums(char *str, int width, int flags, int prec)
{
	int		len;
	char	c;
	char	*padded;
	t_wp	wp;

	padded = NULL;
	wp.width = width;
	wp.prec = prec;
	len = ft_strlen(str);
	if ((flags & FLAG_LEADING_ZERO) != 0
		&& (flags & FLAG_SIGN) == 0 && (flags & FLAG_PRECISION_ARG) == 0)
		c = '0';
	else
		c = ' ';
	if ((flags & FLAG_PRECISION_ARG) != 0 && prec > width)
	{
		padded = ft_pad_with_zeroes(str, prec);
		ft_putstr_fd(padded, STDOUT_FILENO);
		free(padded);
		return (ft_strlen(padded));
	}
	else
		return (withminlen(str, flags, wp, c));
}
