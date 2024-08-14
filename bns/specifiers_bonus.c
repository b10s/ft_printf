/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specifiers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aenshin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 17:26:00 by aenshin           #+#    #+#             */
/*   Updated: 2024/08/13 20:57:52 by aenshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdlib.h>
#include "./libft/libft.h"
#include "./ft_printf_bonus.h"
#include <unistd.h>
#include <stdio.h>

int	voidpspec(va_list ap)
{
	short			ptr_size;
	void			**ptr_in_mem;
	int				cnt;

	ptr_size = sizeof(void *);
	ptr_in_mem = malloc(ptr_size);
	if (ptr_in_mem == NULL)
		return (0);
	ft_bzero(ptr_in_mem, ptr_size);
	*ptr_in_mem = va_arg(ap, void *);
	ft_putchar_fd('0', STDOUT_FILENO);
	ft_putchar_fd('x', STDOUT_FILENO);
	cnt = 2;
	if (*ptr_in_mem == 0)
	{
		ft_putchar_fd('0', STDOUT_FILENO);
		cnt++;
	}
	else
		cnt = cnt + print_in_hex((char *)ptr_in_mem, ptr_size);
	free(ptr_in_mem);
	return (cnt);
}

int	ft_print_toupper_str(char *str)
{
	char			*bigs;
	char			*tmp;
	int				cnt;

	cnt = 0;
	bigs = malloc(ft_strlen(str) + 1);
	if (bigs == NULL)
		return (0);
	ft_strlcpy(bigs, str, ft_strlen(str) + 1);
	tmp = bigs;
	while (*tmp)
	{
		*tmp = ft_toupper(*tmp);
		tmp++;
	}
	if (*bigs == '0')
	{
		ft_putstr_fd(bigs + 1, STDOUT_FILENO);
		cnt = -1;
	}
	else
		ft_putstr_fd(bigs, STDOUT_FILENO);
	free(bigs);
	return (cnt);
}

int	bigxspecifier(va_list ap, unsigned short flags)
{
	unsigned int	xx;
	char			*str;
	int				cnt;

	cnt = 0;
	xx = va_arg(ap, int);
	str = ft_utoax(xx);
	if (str == NULL)
		return (0);
	cnt = ft_strlen(str);
	if (xx != 0)
	{
		if ((flags & FLAG_ALT) != 0)
		{
			ft_putstr_fd("0X", STDOUT_FILENO);
			cnt = cnt + 2;
		}
	}
	cnt = cnt + ft_print_toupper_str(str);
	free(str);
	return (cnt);
}

int	hexspecifier(va_list ap, unsigned short flags)
{
	unsigned int	xx;
	char			*str;
	int				cnt;

	cnt = 0;
	xx = va_arg(ap, int);
	str = ft_utoax(xx);
	if (str == NULL)
		return (0);
	cnt = ft_strlen(str);
	if (xx != 0 && (flags & FLAG_ALT) != 0)
	{
		ft_putstr_fd("0x", STDOUT_FILENO);
		cnt = cnt + 2;
	}
	if (*str == '0')
	{
		ft_putstr_fd(str + 1, STDOUT_FILENO);
		cnt--;
	}
	else
		ft_putstr_fd(str, STDOUT_FILENO);
	free(str);
	return (cnt);
}

int	strspecifier(va_list	ap, int width)
{
	char	*str;
	int		cnt;

	cnt = 0;
	str = va_arg(ap, char *);
	if (str == NULL)
		str = "(null)";
	cnt = cnt + ft_print_str_in_width(str, width);
	return (cnt);
}

// TODO: add to %p (nil)

// TODO: after or before (minus flag)
// 0 for interegers or so
int ft_print_str_in_width(char *str, int width)
{
	int delta;
	int len;

	len = ft_strlen(str);
	//printf("len [%d], w: [%d]\n", len, width);

	if (len > width)
	{
		ft_putstr_fd(str, STDOUT_FILENO);
		return (len);
	}
	else
	{
		delta = width - len;
		while (delta >= 0)
		{
			ft_putchar_fd(' ', STDOUT_FILENO);
			delta--;
		}
		ft_putstr_fd(str, STDOUT_FILENO);
		return (width);
	}
}
