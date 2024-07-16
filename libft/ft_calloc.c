/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aenshin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 20:57:35 by aenshin           #+#    #+#             */
/*   Updated: 2023/08/03 02:32:20 by aenshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>
#include <limits.h>
#include "./libft.h"

void *
	ft_calloc(size_t count, size_t size) {
	void	*res;
	size_t	len;

	if (count != 0 && (SIZE_MAX / count) < size)
		return (NULL);
	len = count * size;
	res = malloc(len);
	if (res == NULL)
		return (res);
	ft_bzero(res, len);
	return (res);
}
