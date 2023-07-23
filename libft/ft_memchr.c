/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmakida <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 12:43:11 by hmakida           #+#    #+#             */
/*   Updated: 2023/01/17 19:04:05 by hmakida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

void	*ft_memchr(const void *buf, int ch, size_t n)
{
	size_t	i;
	char	*new_buf;

	new_buf = (char *)buf;
	i = 0;
	while (i < n)
	{
		if (new_buf[i] == (char)ch)
			return (new_buf + i);
		i ++;
	}
	return (0);
}
