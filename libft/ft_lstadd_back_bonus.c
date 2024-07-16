/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aenshin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 22:02:52 by aenshin           #+#    #+#             */
/*   Updated: 2023/07/18 22:52:00 by aenshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

void
	ft_lstadd_back(t_list **lst, t_list *new) {
	t_list	*l;

	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	l = *lst;
	while (l->next != NULL)
		l = l->next;
	l->next = new;
}
