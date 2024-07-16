/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aenshin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 22:00:54 by aenshin           #+#    #+#             */
/*   Updated: 2023/07/06 22:07:17 by aenshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int
	ft_memcmp(const void *s1, const void *s2, size_t n) {
	size_t	i;

	i = 1;
	while (i <= n)
	{
		if (*(unsigned char *)s1 != *(unsigned char *)s2)
			return ((int)(*(unsigned char *)s1 - *(unsigned char *)s2));
		s1++;
		s2++;
		i++;
	}
	return (0);
}
