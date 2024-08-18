/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_4_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aenshin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 02:00:18 by aenshin           #+#    #+#             */
/*   Updated: 2024/08/19 02:11:29 by aenshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./bns/ft_printf_bonus.h"

int	ft_print_str_in_width_nums(char *str, int width, int flags, int prec)
{
	int delta;
	int len;
	char	c;
	char	*padded;

	padded = NULL;
	len = ft_strlen(str);
	if ((flags & FLAG_LEADING_ZERO) != 0 && (flags & FLAG_SIGN) == 0 && (flags & FLAG_PRECISION_ARG) == 0 )
		c = '0';
	else
		c = ' ';
	if ( (flags & FLAG_PRECISION_ARG) !=0 && prec > width)
	{
		padded = ft_pad_with_zeroes(str, prec);
		len = ft_strlen(padded);
		ft_putstr_fd(padded, STDOUT_FILENO);
		free(padded);
		return (len);
	} else {
		if ( (flags & FLAG_PRECISION_ARG) !=0 && prec < width)
		{
			padded = ft_pad_with_zeroes(str, prec);
			str = padded;
		}

		if (len > width)
		{
			ft_putstr_fd(str, STDOUT_FILENO);
			free(padded);
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
			free(padded);
			return (width);
		}
	}
}
