/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aenshin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 19:03:08 by aenshin           #+#    #+#             */
/*   Updated: 2023/07/03 19:14:12 by aenshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char *
	ft_strrchr(const char *s, int c) {
	char	*ptr;

	ptr = (char *)s;
	while (*ptr != '\0')
		ptr++;
	while (ptr != s)
	{
		if (*ptr == (char)c)
			return (ptr);
		ptr--;
	}
	if (*ptr == (char)c)
		return (ptr);
	return ((void *)0);
}
