/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aenshin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 22:51:07 by aenshin           #+#    #+#             */
/*   Updated: 2023/07/18 22:54:02 by aenshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

int
	ft_lstsize(t_list *lst) {
	int	res;

	if (lst == NULL)
		return (0);
	res = 1;
	while (lst->next != NULL)
	{
		res++;
		lst = lst->next;
	}
	return (res);
}
