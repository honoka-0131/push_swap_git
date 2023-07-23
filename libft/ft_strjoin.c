/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmakida <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 12:04:23 by hmakida           #+#    #+#             */
/*   Updated: 2023/02/01 11:25:03 by hmakida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

static char	*for_null(char const *str)
{
	char	*ans;

	ans = malloc((ft_strlen(str) + 1) * sizeof (char));
	if (ans == NULL)
		return (ans);
	ft_strlcpy(ans, str, ft_strlen(str) + 1);
	return (ans);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ans;

	if (s1 == NULL && s2 == NULL)
		return (NULL);
	else if (s1 == NULL)
		return (for_null(s2));
	else if (s2 == NULL)
		return (for_null(s1));
	ans = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (ans == NULL)
		return (NULL);
	ft_memcpy(ans, s1, ft_strlen(s1));
	ft_strlcpy(ans + ft_strlen(s1), s2, ft_strlen(s2) + 1);
	return (ans);
}
