/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aenshin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 20:43:12 by aenshin           #+#    #+#             */
/*   Updated: 2024/08/13 20:43:30 by aenshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "./ft_printf.h"

void	print_big_hx(unsigned char c, int first)
{
	char	*base;
	int		x;
	int		y;

	x = c / 16;
	y = c % 16;
	base = "0123456789ABCDEF";
	if (first == 1 && c < 16)
	{
		ft_putchar_fd(base[y], 1);
	}
	else
	{
		ft_putchar_fd(base[x], 1);
		ft_putchar_fd(base[y], 1);
	}
}

int	print_in_hex(char *p, short sz)
{
	int		started;
	int		first;
	short	i;
	int		cnt;

	started = 0;
	cnt = 0;
	first = 0;
	i = sz - 1;
	while (i >= 0)
	{
		if (p[i] != 0 && started == 0)
		{
			started = 1;
			first = 1;
		}
		if (started == 1)
		{
			cnt = cnt + print_hx(p[i], first);
		}
		first = 0;
		i--;
	}
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
