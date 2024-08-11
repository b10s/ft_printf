#include <stdarg.h>
#include <stdlib.h>
#include "./libft/libft.h"
#include "./ft_printf.h"
#include <unistd.h>

int	voidpspec(va_list ap)
{
	short			ptr_size;
	void			**ptr_in_mem;
	int				fd;
	int				cnt;

	fd = 1;
	ptr_size = sizeof(void *);
	ptr_in_mem = malloc(ptr_size);
	ft_bzero(ptr_in_mem, ptr_size);
	*ptr_in_mem = va_arg(ap, void *);
	ft_putchar_fd('0', fd);
	ft_putchar_fd('x', fd);
	cnt = 2;
	cnt = cnt + print_in_hex((char *)ptr_in_mem, ptr_size);
	return (cnt);
}

int	bigxspecifier(va_list ap, short alt)
{
	char			*tmp;
	char			*bigs;
	unsigned int	xx;
	char			*str;
	unsigned char	c;
	int				fd;
	int				cnt;

	cnt = 0;
	fd = 1;
	xx = va_arg(ap, int);
	str = ft_utoax(xx);
	cnt = ft_strlen(str);
	if (xx != 0)
	{
		if (alt == 1)
		{
			ft_putstr_fd("0X", STDOUT_FILENO);
			cnt = cnt + 2;
		}
	}
	bigs = malloc(ft_strlen(str));
	ft_strlcpy(bigs, str, ft_strlen(str) + 1);
	tmp = bigs;
	while (*tmp)
	{
		c = ft_toupper(*tmp);
		*tmp = c;
		tmp++;
	}
	if (*bigs == '0')
	{
		ft_putstr_fd(bigs + 1, fd);
		cnt--;
	}
	else
	{
		ft_putstr_fd(bigs, fd);
	}
	free(str);
	free(bigs);
	return (cnt);
}

int	hexspecifier(va_list ap, short alt)
{
	unsigned int	xx;
	char			*str;
	int				cnt;

	cnt = 0;
	xx = va_arg(ap, int);
	str = ft_utoax(xx);
	cnt = ft_strlen(str);
	if (xx != 0)
	{
		if (alt == 1)
		{
			ft_putstr_fd("0x", STDOUT_FILENO);
			cnt = cnt + 2;
		}
	}
	if (*str == '0')
	{
		ft_putstr_fd(str + 1, STDOUT_FILENO);
		cnt--;
	}
	else
	{
		ft_putstr_fd(str, STDOUT_FILENO);
	}
	free(str);
	return (cnt);
}
