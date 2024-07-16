/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aenshin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 23:35:01 by aenshin           #+#    #+#             */
/*   Updated: 2023/08/02 20:47:37 by aenshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

// C ISO/IEC 9899:TC3
// 7.1.12 (1): null pointer leads to UB
// 7.21.1 (2): do nothing with zero size
void *
	ft_memmove(void *dst, const void *src, size_t len) {
	void	*tmp;

	tmp = dst;
	if (dst == NULL && src == NULL && len != 0)
		return (NULL);
	if (src < dst)
	{
		dst = dst + len - 1;
		src = src + len - 1;
		while (len-- > 0)
			*(char *)dst-- = *(char *)src--;
	}
	else
	{
		while (len-- > 0)
		{
			*(char *)dst = *(char *)src;
			dst++;
			src++;
		}
	}
	return (tmp);
}
