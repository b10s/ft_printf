/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aenshin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 18:46:29 by aenshin           #+#    #+#             */
/*   Updated: 2023/08/03 04:09:17 by aenshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"
#include <stdlib.h>

static	size_t	get_arr_len(char const *s, char c);
static	char		**init_arr(size_t alen);
static	void		free_arr(char **a);
static	char		**ft__split(char const *s, size_t alen, char c, char **res);

char **
	ft_split(char const *s, char c) {
	char	**res;
	size_t	alen;

	if (s == NULL)
		return (NULL);
	alen = get_arr_len(s, c);
	res = init_arr(alen);
	res = ft__split(s, alen, c, res);
	if (res == NULL)
		return (NULL);
	return (res);
}

static char **
	ft__split(char const *s, size_t alen, char c, char **res) {
	size_t	i;
	char	*ptr;

	i = 0;
	while (i < alen && *s != '\0' && s != NULL && res != NULL)
	{
		if (*s == c)
			s++;
		else
		{
			ptr = ft_strchr(s, c);
			if (ptr == NULL)
				res[i] = ft_substr(s, 0, ft_strlen(s));
			else
				res[i] = ft_substr(s, 0, ptr - s);
			if (res[i] == NULL)
			{
				free_arr(res);
				return (NULL);
			}
			s = ptr;
			i++;
		}
	}
	return (res);
}

static void
	free_arr(char **a) {
	size_t	i;

	i = 0;
	while (a[i] != NULL)
	{
		free(a[i]);
		i++;
	}
	free(a);
}

static size_t
	get_arr_len(char const *s, char c) {
	size_t	alen;
	short	w;

	alen = 0;
	w = 0;
	while (*s != '\0')
	{
		if (*s == c)
			w = 0;
		else
		{
			if (w == 0)
				alen++;
			w = 1;
		}
		s++;
	}
	return (alen);
}

// creates array of pointer to future strings of the given legth + 1 NULL ptr
// at the end
static char **
	init_arr(size_t alen) {
	char	**res;
	size_t	i;

	i = 0;
	res = malloc((sizeof(char *) * alen) + 1);
	if (res == NULL)
		return (NULL);
	while (i < (alen + 1))
	{
		res[i] = NULL;
		i++;
	}
	return (res);
}
