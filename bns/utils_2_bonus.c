/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aenshin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 00:10:44 by aenshin           #+#    #+#             */
/*   Updated: 2024/08/19 00:13:53 by aenshin          ###   ########.fr       */
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
	if (str == NULL)
		return (0);
	buf = malloc(ft_strlen(str)+3);
	if (buf == NULL)
		return (0);
	tmp = buf;
	buf[0] = '0';
	buf[1] = '0';
	ft_strlcpy(buf+2, str, ft_strlen(str) + 1);
	while (*(buf + 1) == '0')
	{
		buf[0] = '0';
		buf[1] = 'x';
		buf++;
	}
	buf--;

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
