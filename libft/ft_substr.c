/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aenshin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 19:55:39 by aenshin           #+#    #+#             */
/*   Updated: 2023/07/24 22:19:12 by aenshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"
#include <stdlib.h>

char *
	ft_substr(char const *s, unsigned int start, size_t len) {
	char	*res;
	char	*start_ptr;
	size_t	i;

	if (s == NULL)
		return (NULL);
	i = 0;
	while (*s != '\0' && i < start)
	{
		s++;
		i++;
	}
	i = 0;
	start_ptr = (char *)s;
	while (*s != '\0' && i < len)
	{
			s++;
			i++;
	}
	res = malloc(i + 1);
	if (res == NULL)
		return (res);
	ft_strlcpy(res, start_ptr, i + 1);
	return (res);
}
