/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmakida <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 12:48:17 by hmakida           #+#    #+#             */
/*   Updated: 2023/02/02 20:11:11 by hmakida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*new_s1;
	unsigned char	*new_s2;	

	i = 0;
	new_s1 = (unsigned char *)s1;
	new_s2 = (unsigned char *)s2;
	while (i < n && (new_s1[i] != '\0' || new_s2[i] != '\0'))
	{
		if (new_s1[i] != new_s2[i])
			return (new_s1[i] - new_s2[i]);
		i ++;
	}
	return (0);
}
