/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmakida <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 12:10:40 by hmakida           #+#    #+#             */
/*   Updated: 2023/02/05 13:52:14 by hmakida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*ans;
	size_t	i;

	i = 0;
	if (s == NULL)
		return (NULL);
	if (f == NULL)
		return (ft_strdup(s));
	ans = malloc((ft_strlen(s) + 1) * sizeof (char));
	if (ans == NULL)
		return (NULL);
	while (s[i])
	{
		ans[i] = f(i, s[i]);
		i ++;
	}
	ans[i] = '\0';
	return (ans);
}
