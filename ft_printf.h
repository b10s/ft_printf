/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aenshin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 18:21:01 by aenshin           #+#    #+#             */
/*   Updated: 2024/08/13 00:58:38 by aenshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include "./libft/libft.h"
# define FLAG_ALT   0b00000001
# define FLAG_BLANK 0b00000010
# define FLAG_SIGN  0b00000100

int		ft_printf(const char *fmt, ...);
char	*ft_utoax(unsigned int n);
char	*ft_utoa(unsigned int n);
int		voidpspec(va_list ap);
int		print_in_hex(char *p, short sz);
int		bigxspecifier(va_list ap);
int		hexspecifier(va_list ap);
int		print_hx(unsigned char c, int first);
int		strspecifier(va_list	ap);
int		uspecifier(va_list ap);
int		dispecifier(va_list	ap);
int		allspecifiers(va_list ap, const char *fmt);
int		ft_print_toupper_str(char *str);

#endif
