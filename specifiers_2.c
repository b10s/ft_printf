/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specifiers_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aenshin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 17:44:36 by aenshin           #+#    #+#             */
/*   Updated: 2024/08/13 00:56:48 by aenshin          ###   ########.fr       */
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

int	dispecifier(va_list	ap)
{
	int		cnt;
	int		x;
	char	*str;

	cnt = 0;
	x = va_arg(ap, int);
	str = ft_itoa(x);
	cnt = cnt + ft_strlen(str);
	ft_putstr_fd(str, STDOUT_FILENO);
	free(str);
	return (cnt);
}

int	allspecifiers(va_list ap, const char *fmt)
{
	int	cnt;

	cnt = 0;
	if (*(fmt + 1) == 's' )
		cnt = cnt + strspecifier(ap);
	else if (*(fmt + 1) == 'p')
		cnt = cnt + voidpspec(ap);
	else if (*(fmt + 1) == 'd' || *(fmt + 1) == 'i' )
		cnt = cnt + dispecifier(ap);
	else if (*(fmt + 1) == 'u')
		cnt = cnt + uspecifier(ap);
	else if (*(fmt + 1) == 'x')
		cnt = cnt + hexspecifier(ap);
	else if (*(fmt + 1) == 'X')
		cnt = cnt + bigxspecifier(ap);
	else
	{
		if (*(fmt + 1) == 'c' )
			ft_putchar_fd((char)va_arg(ap, int), STDOUT_FILENO);
		else
			ft_putchar_fd(*(fmt + 1), STDOUT_FILENO);
		cnt++;
	}
	return (cnt);
}
