/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmakida <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 19:18:52 by hmakida           #+#    #+#             */
/*   Updated: 2023/01/26 21:22:41 by hmakida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

size_t	check_malloc_size(size_t strlen_s, unsigned int start, size_t len)
{
	if (start + len <= strlen_s)
		return (len + 1);
	return (strlen_s - start + 1);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*ans;
	size_t			malloc_size;

	if (s == NULL)
		return (NULL);
	if (ft_strlen(s) < (size_t)start || len == 0)
	{
		ans = malloc(1);
		if (ans == NULL)
			return (NULL);
		*ans = '\0';
		return (ans);
	}
	malloc_size = check_malloc_size(ft_strlen(s), start, len);
	ans = malloc(malloc_size * sizeof(char));
	if (ans == NULL)
		return (NULL);
	ft_strlcpy(ans, &s[start], malloc_size);
	return (ans);
}
