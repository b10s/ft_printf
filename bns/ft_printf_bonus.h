/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aenshin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 18:21:01 by aenshin           #+#    #+#             */
/*   Updated: 2024/08/19 01:43:22 by aenshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include "../libft/libft.h"
# define FLAG_ALT   				0b00000001
# define FLAG_BLANK 				0b00000010
# define FLAG_SIGN  				0b00000100
# define FLAG_LEFT_ALIGN  	0b00001000
# define FLAG_LEADING_ZERO  0b00010000
# define FLAG_PRECISION_ARG	0b00100000

typedef struct wp
{
	int	width;
	int	prec;
}	t_wp;

int				ft_printf(const char *fmt, ...);
unsigned short	parse_flags(const char *fmt);
char			*ft_utoax(unsigned int n);
char			*ft_utoa(unsigned int n);
int				voidpspec(va_list ap, int width, int flags);
char			*sprint_in_hex(char *p, short sz);
int				bigxspecifier(va_list ap, unsigned short flags);
int				hexspecifier(va_list ap, int width, unsigned short flags,
					int prec);
int				bhexspecifier(va_list ap, int width, unsigned short flags,
					int prec);
int				print_hx(unsigned char c, int first);
int				strspecifier(va_list	ap, int width, int flags, int prec);
int				uspecifier(va_list ap, int width, int flags, int prec);
int				dispecifier(va_list	ap, int width, unsigned short flags,
					int prec);
int				ft_print_str_in_width(char *str, int width, int flags,
					int prec);
int				allspecifiers(va_list ap, const char *fmt, unsigned short flags,
					t_wp wp);
int				cspecifier(va_list ap, int width, int flags);
int				ft_print_str_in_width_nums(char *str, int width, int flags,
					int prec);
void			flg(const char **fmt, unsigned short *flags, int *width,
					int *prec);
size_t			count_flags(const char *fmt);
void			ft_toupper_str(char *str);
void			movestr(char **str);
int				ft_ishexdigit(int c);

#endif
