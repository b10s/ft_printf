/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aenshin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 16:47:16 by aenshin           #+#    #+#             */
/*   Updated: 2023/07/01 19:08:36 by aenshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "./libft.h"

size_t
	ft_strlcat(char *dst, const char *src, size_t dstsize) {
	size_t	res;
	size_t	i;

	res = ft_strlen(src);
	if (dstsize == 0)
		return (res);
	i = 0;
	while (i < dstsize && dst[i] != '\0')
		i++;
	res = res + i;
	if (i >= dstsize - 1)
		return (res);
	while (i < dstsize - 1 && *src != '\0')
	{
		dst[i] = *src;
		src++;
		i++;
	}
	dst[i] = '\0';
	return (res);
}
