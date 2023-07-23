/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmakida <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 12:44:22 by hmakida           #+#    #+#             */
/*   Updated: 2023/01/26 20:56:43 by hmakida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t size)
{
	size_t			i;
	unsigned char	*ss1;
	unsigned char	*ss2;

	i = 0;
	ss1 = (unsigned char *)s1;
	ss2 = (unsigned char *)s2;
	if (size == 0)
		return (0);
	while (i < size - 1)
	{
		if (ss1[i] != ss2[i])
			break ;
		i ++;
	}
	if (ss1[i] != ss2[i])
		return (ss1[i] - ss2[i]);
	return (0);
}
