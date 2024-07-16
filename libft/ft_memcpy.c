/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aenshin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 23:26:58 by aenshin           #+#    #+#             */
/*   Updated: 2023/08/02 20:44:40 by aenshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

// C ISO/IEC 9899:TC3
// 7.1.12 (1): null pointer leads to UB
// 7.21.1 (2): do nothing with zero size
void *
	ft_memcpy(void *dst, const void *src, size_t n) {
	void	*tmp;

	if (n == 0)
	{
		return (dst);
	}
	if (dst == NULL && src == NULL)
		return (NULL);
	tmp = dst;
	while (n > 0)
	{
		*(char *)dst = *(char *)src;
		dst++;
		src++;
		n--;
	}
	return (tmp);
}
