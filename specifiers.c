/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specifiers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aenshin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 17:26:00 by aenshin           #+#    #+#             */
/*   Updated: 2024/08/13 00:57:52 by aenshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_printf.h"

int	allspecifiers(va_list ap, const char *fmt)
{
	int	cnt;

	cnt = 0;
	if (*(fmt + 1) == 's' )
		cnt = cnt + strspecifier(ap);
	else if (*(fmt + 1) == 'p')
		cnt = cnt + voidpspec(ap);
	else if (*(fmt + 1) == 'd' || *(fmt + 1) == 'i' )
		cnt = cnt + dispecifier(ap);
	else if (*(fmt + 1) == 'u')
		cnt = cnt + uspecifier(ap);
	else if (*(fmt + 1) == 'x')
		cnt = cnt + hexspecifier(ap);
	else if (*(fmt + 1) == 'X')
		cnt = cnt + bigxspecifier(ap);
	else
	{
		if (*(fmt + 1) == 'c' )
			ft_putchar_fd((char)va_arg(ap, int), STDOUT_FILENO);
		else
			ft_putchar_fd(*(fmt + 1), STDOUT_FILENO);
		cnt++;
	}
	return (cnt);
}

int	voidpspec(va_list ap)
{
	short			ptr_size;
	void			**ptr_in_mem;
	int				cnt;

	ptr_size = sizeof(void *);
	ptr_in_mem = malloc(ptr_size);
	ft_bzero(ptr_in_mem, ptr_size);
	*ptr_in_mem = va_arg(ap, void *);
	ft_putchar_fd('0', STDOUT_FILENO);
	ft_putchar_fd('x', STDOUT_FILENO);
	cnt = 2;
	if (*ptr_in_mem == 0)
	{
		ft_putchar_fd('0', STDOUT_FILENO);
		cnt++;
	}
	else
		cnt = cnt + print_in_hex((char *)ptr_in_mem, ptr_size);
	free(ptr_in_mem);
	return (cnt);
}

int	bigxspecifier(va_list ap)
{
	unsigned int	xx;
	char			*str;
	int				cnt;

	cnt = 0;
	xx = va_arg(ap, int);
	str = ft_utoax(xx);
	cnt = ft_strlen(str);
	cnt = cnt + ft_print_toupper_str(str);
	free(str);
	return (cnt);
}

int	hexspecifier(va_list ap)
{
	unsigned int	xx;
	char			*str;
	int				cnt;

	cnt = 0;
	xx = va_arg(ap, int);
	str = ft_utoax(xx);
	cnt = ft_strlen(str);
	if (*str == '0')
	{
		ft_putstr_fd(str + 1, STDOUT_FILENO);
		cnt--;
	}
	else
		ft_putstr_fd(str, STDOUT_FILENO);
	free(str);
	return (cnt);
}
