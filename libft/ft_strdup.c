/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aenshin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 19:45:17 by aenshin           #+#    #+#             */
/*   Updated: 2023/07/10 19:53:51 by aenshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"
#include <stdlib.h>

char *
	ft_strdup(const char *s1) {
	size_t	len;
	char	*res;

	len = ft_strlen(s1) + 1;
	res = malloc(len);
	if (res == NULL)
		return (res);
	ft_strlcpy(res, s1, len + 1);
	return (res);
}
