/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aenshin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 00:10:44 by aenshin           #+#    #+#             */
/*   Updated: 2024/08/19 00:10:45 by aenshin          ###   ########.fr       */
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
