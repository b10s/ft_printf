/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aenshin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 18:49:44 by aenshin           #+#    #+#             */
/*   Updated: 2023/07/03 19:13:54 by aenshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char *
	ft_strchr(const char *s, int c) {
	char	*res;

	res = (char *)s;
	while (*res != '\0')
	{
		if (*res == (char)c)
			return (res);
		res++;
	}
	if (*res == (char)c)
		return (res);
	return ((void *)0);
}
