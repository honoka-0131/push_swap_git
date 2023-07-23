/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmakida <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 16:07:59 by hmakida           #+#    #+#             */
/*   Updated: 2023/02/01 11:19:33 by hmakida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t count)
{
	size_t	i;	

	i = count;
	if (dest <= src)
		return (ft_memcpy(dest, src, count));
	while (0 < i)
	{
		i --;
		*((char *)dest + i) = *((char *)src + i);
	}
	return (dest);
}
