/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aenshin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 22:42:05 by aenshin           #+#    #+#             */
/*   Updated: 2023/08/02 22:28:08 by aenshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

char *
	ft_strnstr(const char *haystack, const char *needle, size_t len) {
	size_t		i;
	size_t		j;
	const char	*res;
	const char	*tmp;

	if (ft_strlen(needle) == 0)
		return ((char *)haystack);
	i = 1;
	while (i <= len && *haystack != '\0')
	{
		tmp = needle;
		res = haystack;
		j = i;
		while (*haystack == *tmp && *tmp != '\0' && j <= len)
		{
			j++;
			haystack++;
			tmp++;
		}
		if (*tmp == '\0')
			return ((char *)res);
		haystack = ++res;
		i++;
	}
	return (NULL);
}
