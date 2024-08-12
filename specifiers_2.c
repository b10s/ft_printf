/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specifiers_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aenshin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 17:44:36 by aenshin           #+#    #+#             */
/*   Updated: 2024/08/12 17:52:48 by aenshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "./ft_printf.h"
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
