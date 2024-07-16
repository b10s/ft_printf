/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aenshin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 19:31:42 by aenshin           #+#    #+#             */
/*   Updated: 2023/07/24 22:14:57 by aenshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "./libft.h"

void
	ft_putendl_fd(char *s, int fd) {
	if (s == NULL)
		return ;
	ft_putstr_fd(s, fd);
	write(fd, (const void *)"\n", 1);
}
