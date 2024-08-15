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

int	uspecifier(va_list ap, int width, int flags)
{
	int		cnt;
	int		x;
	char	*str;

	cnt = 0;
	x = va_arg(ap, int);
	str = ft_utoa(x);
	cnt = ft_print_str_in_width_nums(str, width, flags);
	//cnt = ft_print_str_in_width(str, width, flags);
	free(str);
	return (cnt);
}

int	dispecifier(va_list	ap, int width, unsigned short flags)
{
	int		cnt;
	int		x;
	char	*str;
	char	*s;

	cnt = 0;
	x = va_arg(ap, int);
	str = ft_itoa(x);
	s = malloc(ft_strlen(str) + 2);
	ft_strlcpy(s+1, str, ft_strlen(str)+1);
	cnt = cnt + ft_strlen(str);
	free(str);
	str = s;
	if ((flags & FLAG_SIGN) != 0)
	{
		if (x >= 0)
			s[0] = '+';
		else s++;
	}
	else if ((flags & FLAG_BLANK) != 0 && x >= 0)
		s[0] = ' ';
	else
		s++;
	
	cnt = ft_print_str_in_width_nums(s, width, flags);

	free(str);
	return (cnt);
}

int	allspecifiers(va_list ap, const char *fmt, unsigned short flags, int width)
{
	int	cnt;

	cnt = 0;
	if (*(fmt) == 's' )
		cnt = cnt + strspecifier(ap, width, flags);
	else if (*(fmt) == 'p')
		cnt = cnt + voidpspec(ap, width, flags);
	else if (*(fmt) == 'd' || *(fmt) == 'i' )
		cnt = cnt + dispecifier(ap, width, flags);
	else if (*(fmt) == 'u')
		cnt = cnt + uspecifier(ap, width, flags);
	else if (*(fmt) == 'x')
		cnt = cnt + hexspecifier(ap, width, flags, 0);
	else if (*(fmt) == 'X')
		cnt = cnt + hexspecifier(ap, width, flags, 1);
		//cnt = cnt + bigxspecifier(ap, width, flags);
	else if (*(fmt) == 'c' )
		cnt = cnt + cspecifier(ap, width, flags);
		//ft_putchar_fd((char)va_arg(ap, int), STDOUT_FILENO);
	else
	{
		ft_putchar_fd(*(fmt), STDOUT_FILENO);
		cnt++;
	}
	return (cnt);
}

int cspecifier(va_list ap, int width, int flags)
{
	char c;
	int	cnt;
	
	cnt = 1;
	c = (char)va_arg(ap, int);
	width--;
	if ((flags & FLAG_LEFT_ALIGN) != 0)
		ft_putchar_fd(c, STDOUT_FILENO);
	while (width > 0)
	{
		ft_putchar_fd(' ', STDOUT_FILENO);
		width--;
		cnt++;
	}
	if ((flags & FLAG_LEFT_ALIGN) == 0)
		ft_putchar_fd(c, STDOUT_FILENO);

	return (cnt);
}
