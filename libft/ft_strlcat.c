/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmakida <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 13:52:53 by hmakida           #+#    #+#             */
/*   Updated: 2023/01/26 21:10:19 by hmakida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	ans;
	size_t	i;
	size_t	a;

	if (size == 0)
		return (ft_strlen(src));
	else if (ft_strlen(dst) <= size)
		ans = ft_strlen(dst) + ft_strlen(src);
	else
		ans = size + ft_strlen(src);
	i = 0;
	a = 0;
	while (dst[i] != '\0')
	{
		i ++;
	}
	while (src[a] && i + 2 <= size)
	{
		dst[i] = src[a];
		i ++;
		a ++;
	}
	dst[i] = '\0';
	return (ans);
}
