/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aenshin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 20:33:14 by aenshin           #+#    #+#             */
/*   Updated: 2023/07/24 22:18:36 by aenshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"
#include <stdlib.h>

char *
	ft_strjoin(char const *s1, char const *s2) {
	size_t	len;
	char	*res;

	if (s1 == NULL || s1 == NULL)
		return (NULL);
	len = ft_strlen(s1);
	len = len + ft_strlen(s2);
	res = malloc(len + 1);
	if (res == NULL)
		return (NULL);
	ft_strlcpy(res, s1, len + 1);
	ft_strlcat(res, s2, len + 1);
	return (res);
}
