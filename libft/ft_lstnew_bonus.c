/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aenshin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 21:57:03 by aenshin           #+#    #+#             */
/*   Updated: 2023/07/18 22:01:23 by aenshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "./libft.h"

t_list *
	ft_lstnew(void *content) {
	t_list	*res;

	res = malloc(sizeof(t_list));
	if (res == NULL)
		return (NULL);
	res->next = NULL;
	res->content = content;
	return (res);
}
