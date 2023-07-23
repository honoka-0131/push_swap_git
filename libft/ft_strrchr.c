/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmakida <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 12:54:15 by hmakida           #+#    #+#             */
/*   Updated: 2023/01/26 21:01:04 by hmakida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;

	i = ft_strlen(s);
	if (s == NULL)
		return (NULL);
	while (1)
	{
		if ((s[i] == (char)c) || (s[i] == '\0' && (char)c == '\0'))
			return ((char *)&s[i]);
		if (i == 0)
			break ;
		i --;
	}
	return (NULL);
}
