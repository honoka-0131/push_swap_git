/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmakida <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 12:34:52 by hmakida           #+#    #+#             */
/*   Updated: 2023/01/25 20:21:29 by hmakida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

static int	check_overflow(long ans, const char c, int nega)
{
	long	ov_div;
	long	ov_mod;

	ov_div = LONG_MAX / 10;
	ov_mod = LONG_MAX % 10;
	if (nega == -1)
		ov_mod ++;
	if (ans > ov_div)
		return (1);
	else if (ans == ov_div && (long)c - '0' > ov_mod)
		return (1);
	return (0);
}

int	while_num(int nega, const char *nptr)
{
	long	ans;
	size_t	i;

	ans = 0;
	i = 0;
	while ('0' <= nptr[i] && nptr[i] <= '9')
	{
		if (check_overflow(ans, nptr[i], nega) && nega == 1)
			return ((int)LONG_MAX);
		else if (check_overflow(ans, nptr[i], nega) && nega == -1)
			return ((int)LONG_MIN);
		ans = ans * 10 + nptr[i] - '0';
		i ++;
	}
	ans *= nega;
	return (ans);
}

int	ft_atoi(const char *nptr)
{
	size_t	i;
	int		nega;

	i = 0;
	nega = 1;
	while (nptr[i] == ' ' || nptr[i] == '\t' || nptr[i] == '\n'
		|| nptr[i] == '\v' || nptr[i] == '\f' || nptr[i] == '\r')
		i ++;
	while (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			nega *= -1;
		if (nptr[i] == '+' || nptr[i] == '-')
			i ++;
		if (nptr[i] == '+' || nptr[i] == '-')
			return (0);
	}
	return (while_num(nega, &nptr[i]));
}
