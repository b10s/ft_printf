/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aenshin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 18:21:01 by aenshin           #+#    #+#             */
/*   Updated: 2024/08/18 21:53:09 by aenshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H

# include <stdarg.h>
# include "../libft/libft.h"
# define FLAG_ALT   				0b00000001
# define FLAG_BLANK 				0b00000010
# define FLAG_SIGN  				0b00000100
# define FLAG_LEFT_ALIGN  	0b00001000
# define FLAG_LEADING_ZERO  0b00010000
# define FLAG_PRECISION_ARG	0b00100000

int		ft_printf(const char *fmt, ...);
char	*ft_utoax(unsigned int n);
char	*ft_utoa(unsigned int n);
int		voidpspec(va_list ap, int width, int flags);
char	*sprint_in_hex(char *p, short sz);
int		bigxspecifier(va_list ap, unsigned short flags);
int		hexspecifier(va_list ap, int width, unsigned short flags, int big, int prec);
int		print_hx(unsigned char c, int first);
int		strspecifier(va_list	ap, int width, int flags, int prec);
int		uspecifier(va_list ap, int width, int flags, int prec);
int		dispecifier(va_list	ap, int width, unsigned short flags, int prec);
int ft_print_str_in_width(char *str, int width, int flags, int prec);
int		allspecifiers(va_list ap, const char *fmt, unsigned short flags,
			int width, int prec);
int cspecifier(va_list ap, int width, int flags);
int ft_print_str_in_width_nums(char *str, int width, int flags, int prec);

#endif
