/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aenshin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 22:59:55 by aenshin           #+#    #+#             */
/*   Updated: 2023/07/01 16:21:09 by aenshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stddef.h>
#include "./libft.h"

size_t
	ft_strlcpy(char *dst, const char *src, size_t dstsize) {
	size_t	i;
	size_t	res;

	res = ft_strlen(src);
	if (dstsize == 0)
	{
		return (res);
	}
	i = 0;
	while (i++ < dstsize - 1 && *src != '\0')
	{
		*dst++ = *src++;
	}
	*dst = 0;
	return (res);
}
