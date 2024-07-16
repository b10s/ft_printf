/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aenshin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 23:11:17 by aenshin           #+#    #+#             */
/*   Updated: 2023/08/03 04:05:39 by aenshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>

static int	check_ovf(unsigned long long n, const char *str, short sign);
static int	check_ovf_hlp(unsigned long long n, const char *str, short sign);

int
	ft_atoi(const char *str) {
	unsigned long long	res;
	short				sign;

	res = 0;
	sign = 0;
	while (*str == ' ' || *str == '\t' || *str == '\v'
		|| *str == '\f' || *str == '\r' || *str == '\n')
		str++;
	if (*str == '-')
		sign = 1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		if (check_ovf(res, str, sign) != 42)
			return (check_ovf(res, str, sign));
		res = res * 10;
		res = res + (int)(*str - '0');
		str++;
	}
	if (sign == 1)
		res = -res;
	return ((int)res);
}

static int
	check_ovf(unsigned long long n, const char *str, short sign) {
	if (check_ovf_hlp(n, str, sign) != 42)
		return (check_ovf_hlp(n, str, sign));
	if (n * 10 > (unsigned long long)LONG_MAX)
	{
		if (sign)
			return ((int)LONG_MIN);
		return ((int)LONG_MAX);
	}
	return (42);
}

static int
	check_ovf_hlp(unsigned long long n, const char *str, short sign) {
	long long	mytail;
	long long	maxtail;
	long long	mintail;

	maxtail = (unsigned int)LONG_MAX;
	mintail = maxtail + 1;
	mytail = (int)(*str - '0');
	mytail = mytail + (unsigned int)n * 10;
	if (LONG_MAX - n * 10 < 10)
	{
		if (sign)
		{
			if (mytail >= mintail)
				return ((int)LONG_MIN);
			return ((int)-mytail);
		}
		else
		{
			if (mytail >= maxtail)
				return ((int)LONG_MAX);
			return ((int)mytail);
		}
	}
	return (42);
}
