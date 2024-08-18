/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specifiers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aenshin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 17:26:00 by aenshin           #+#    #+#             */
/*   Updated: 2024/08/19 00:57:27 by aenshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdlib.h>
#include "./libft/libft.h"
#include "./ft_printf_bonus.h"
#include <unistd.h>
#include <stdio.h>

void	movestr(char **str)
{
	while (*((*str) + 1) == '0')
	{
		*((*str)) = '0';
		*((*str) + 1) = 'x';
		(*str)++;
	}
	(*str)--;
}

int	voidpspec(va_list ap, int width, int flags)
{
	short			ptr_size;
	void			**ptr_in_mem;
	int				cnt;
	char			*str;
	char			*tmp;

	ptr_size = sizeof(void *);
	ptr_in_mem = malloc(ptr_size);
	ft_bzero(ptr_in_mem, ptr_size);
	*ptr_in_mem = va_arg(ap, void *);
	tmp = NULL;
	if (*ptr_in_mem == NULL)
		str = "(nil)";
	else
	{
		str = sprint_in_hex((char *)ptr_in_mem, ptr_size);
		tmp = str;
		movestr(&str);
	}
	cnt = ft_print_str_in_width(str, width, flags, 0);
	free(tmp);
	free(ptr_in_mem);
	return (cnt);
}

// modifies in place the same string
// TODO: can be used in to_hex to replce base?
void	ft_toupper_str(char *str)
{
	while (*str)
	{
		*str = ft_toupper(*str);
		str++;
	}
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
