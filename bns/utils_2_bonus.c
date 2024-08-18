/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aenshin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 00:10:44 by aenshin           #+#    #+#             */
/*   Updated: 2024/08/19 01:42:37 by aenshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./bns/ft_printf_bonus.h"

void	flg(const char **fmt, unsigned short *flags, int *width, int *prec)
{
	*flags = parse_flags(*fmt);
	*fmt = *fmt + count_flags(*fmt);
	*width = ft_atoi(*fmt);
	while (ft_isdigit(**fmt))
		(*fmt)++;
	if (**fmt == '.')
	{
		*flags = *flags | FLAG_PRECISION_ARG;
		(*fmt)++;
		*prec = ft_atoi(*fmt);
		while (ft_isdigit(**fmt))
			(*fmt)++;
	}
}

void	bmovestr(char **str)
{
	**str = '0';
	*((*str) + 1) = '0';
	while (*((*str) + 1) == '0')
	{
		*((*str)) = '0';
		*((*str) + 1) = 'x';
		(*str)++;
	}
	(*str)--;
}

int	bhexspecifier(va_list ap, int width, unsigned short flags, int prec)
{
	unsigned int	xx;
	char			*str;
	int				cnt;
	char			*buf;
	char			*tmp;

	cnt = 0;
	xx = va_arg(ap, int);
	str = ft_utoax(xx);
	buf = malloc(ft_strlen(str)+3);
	tmp = buf;
	ft_strlcpy(buf + 2, str, ft_strlen(str) + 1);
	bmovestr(&buf);
	ft_toupper_str(buf);
	ft_toupper_str(str);
	if (xx != 0 && (flags & FLAG_ALT) != 0)
		cnt = ft_print_str_in_width_nums(buf, width, flags, prec);
	else if (*str == '0')
		cnt = ft_print_str_in_width_nums(str + 1, width, flags, prec);
	else
		cnt = ft_print_str_in_width_nums(str, width, flags, prec);
	free(tmp);
	free(str);
	return (cnt);
}

int	strspecifier(va_list	ap, int width, int flags, int prec)
{
	char	*str;
	int		cnt;

	cnt = 0;
	str = va_arg(ap, char *);
	if (str == NULL)
		str = "(null)";
	cnt = cnt + ft_print_str_in_width(str, width, flags, prec);
	return (cnt);
}

int
	ft_ishexdigit(int c) {
	if (c >= (int) '0' && c <= (int) '9')
	{
		return (1);
	}
	if (c >= (int) 'a' && c <= (int) 'f')
	{
		return (1);
	}
	if (c >= (int) 'A' && c <= (int) 'F')
	{
		return (1);
	}
	return (0);
}
