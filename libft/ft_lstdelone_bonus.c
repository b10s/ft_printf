/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aenshin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 22:58:16 by aenshin           #+#    #+#             */
/*   Updated: 2023/07/24 22:14:23 by aenshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"
#include <stdlib.h>

void
	ft_lstdelone(t_list *lst, void (*del)(void *)) {
	if (lst == NULL || del == NULL)
		return ;
	del(lst->content);
	free(lst);
	return ;
}
