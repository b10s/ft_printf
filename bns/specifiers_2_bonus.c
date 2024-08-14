/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specifiers_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aenshin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 17:44:36 by aenshin           #+#    #+#             */
/*   Updated: 2024/08/13 01:00:27 by aenshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "./ft_printf_bonus.h"
#include <unistd.h>
#include <stdlib.h>

int	uspecifier(va_list ap)
{
	int		cnt;
	int		x;
	char	*str;

	cnt = 0;
	x = va_arg(ap, int);
	str = ft_utoa(x);
	cnt = cnt + ft_strlen(str);
	ft_putstr_fd(str, STDOUT_FILENO);
	free(str);
	return (cnt);
}

int	dispecifier(va_list	ap, unsigned short flags)
{
	int		cnt;
	int		x;
	char	*str;

	cnt = 0;
	x = va_arg(ap, int);
	str = ft_itoa(x);
	cnt = cnt + ft_strlen(str);
	if ((flags & FLAG_SIGN) != 0)
	{
		if (x >= 0)
		{
			ft_putchar_fd('+', STDOUT_FILENO);
			cnt++;
		}
	}
	else if ((flags & FLAG_BLANK) != 0 && x >= 0)
	{
		ft_putchar_fd(' ', STDOUT_FILENO);
		cnt++;
	}
	ft_putstr_fd(str, STDOUT_FILENO);
	free(str);
	return (cnt);
}

int	allspecifiers(va_list ap, const char *fmt, unsigned short flags, int width)
{
	int	cnt;

	cnt = 0;
	if (*(fmt) == 's' )
		cnt = cnt + strspecifier(ap, width);
	else if (*(fmt) == 'p')
		cnt = cnt + voidpspec(ap);
	else if (*(fmt) == 'd' || *(fmt) == 'i' )
		cnt = cnt + dispecifier(ap, flags);
	else if (*(fmt) == 'u')
		cnt = cnt + uspecifier(ap);
	else if (*(fmt) == 'x')
		cnt = cnt + hexspecifier(ap, flags);
	else if (*(fmt) == 'X')
		cnt = cnt + bigxspecifier(ap, flags);
	else
	{
		if (*(fmt) == 'c' )
			ft_putchar_fd((char)va_arg(ap, int), STDOUT_FILENO);
		else
			ft_putchar_fd(*(fmt), STDOUT_FILENO);
		cnt++;
	}
	return (cnt);
}
