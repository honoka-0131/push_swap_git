/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmakida <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 20:20:25 by hmakida           #+#    #+#             */
/*   Updated: 2023/01/26 21:07:48 by hmakida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t n)
{
	size_t	i;
	size_t	ret;

	i = 0;
	ret = 0;
	while (src[ret])
	{
		ret ++;
	}
	if (n == 0)
		return (ret);
	while (src[i] && i + 1 < n)
	{
		dest[i] = src[i];
		i ++;
	}
	dest[i] = '\0';
	return (ret);
}
