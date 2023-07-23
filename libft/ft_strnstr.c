/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmakida <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 12:51:19 by hmakida           #+#    #+#             */
/*   Updated: 2023/02/01 11:06:58 by hmakida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

static size_t	check(const char *big_forcheck, const char *lit_forcheck)
{
	size_t	a;

	a = 0;
	while (lit_forcheck[a])
	{
		if (big_forcheck[a] != lit_forcheck[a])
			return (0);
		a ++;
	}
	return (a);
}

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	len_little;
	char	*ans;

	i = 0;
	j = 0;
	len_little = ft_strlen(little);
	ans = (char *)big;
	if (little[i] == '\0')
		return (ans);
	if (len == 0)
		return (NULL);
	while (big[i] && i + len_little <= len)
	{
		if (big[i] == little[j])
		{
			if (check(&big[i], &little[j]) != 0)
				return (&ans[i]);
		}
		i ++;
	}
	return (NULL);
}
