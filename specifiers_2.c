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

#include "./ft_printf.h"

int	uspecifier(va_list ap)
{
	int		cnt;
	int		x;
	char	*str;

	cnt = 0;
	x = va_arg(ap, int);
	str = ft_utoa(x);
	if (str == NULL)
		return (0);
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

int	strspecifier(va_list	ap)
{
	char	*str;
	int		cnt;

	cnt = 0;
	str = va_arg(ap, char *);
	if (str == NULL)
	{
		cnt = cnt + 6;
		ft_putstr_fd("(null)", STDOUT_FILENO);
	}
	else
	{
		cnt = cnt + ft_strlen(str);
		ft_putstr_fd(str, STDOUT_FILENO);
	}
	return (cnt);
}
