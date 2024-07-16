/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aenshin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 23:01:49 by aenshin           #+#    #+#             */
/*   Updated: 2023/07/24 22:13:49 by aenshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"
#include <stdlib.h>

void
	ft_lstclear(t_list **lst, void (*del)(void *)) {
	t_list	*l;
	t_list	*tmp;

	if (lst == NULL || *lst == NULL || del == NULL)
		return ;
	l = *lst;
	while (l->next != NULL)
	{
		del(l->content);
		tmp = l;
		l = l->next;
		free(tmp);
	}
	del(l->content);
	free(l);
	*lst = NULL;
	return ;
}
