/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmakida <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 10:53:04 by hmakida           #+#    #+#             */
/*   Updated: 2023/01/26 21:18:54 by hmakida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *buf1, const void *buf2, size_t n)
{
	size_t			i;
	unsigned char	*tmp_buf1;
	unsigned char	*tmp_buf2;

	tmp_buf1 = (unsigned char *)buf1;
	tmp_buf2 = (unsigned char *)buf2;
	i = 0;
	if (buf1 == buf2)
		return (buf1);
	if (buf1 == NULL && buf2 == NULL)
		return (NULL);
	while (i < n)
	{
		tmp_buf1[i] = tmp_buf2[i];
		i ++;
	}
	return (tmp_buf1);
}
