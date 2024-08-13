/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aenshin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 22:34:41 by aenshin           #+#    #+#             */
/*   Updated: 2024/08/13 00:55:24 by aenshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_printf.h"

int	ft_printf(const char *fmt, ...)
{
	va_list			ap;
	int				cnt;

	cnt = 0;
	va_start(ap, fmt);
	while (*fmt != 0)
	{
		if (*fmt == '%')
		{
			cnt = cnt + allspecifiers(ap, fmt);
			fmt++;
		}
		else
		{
			ft_putchar_fd(*fmt, STDOUT_FILENO);
			cnt++;
		}
		fmt++;
	}
	va_end(ap);
	return (cnt);
}
