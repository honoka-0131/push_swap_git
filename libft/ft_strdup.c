/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmakida <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 11:02:18 by hmakida           #+#    #+#             */
/*   Updated: 2023/01/26 21:16:53 by hmakida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

char	*ft_strdup(const char *s)
{
	char	*ans;

	ans = malloc((ft_strlen(s) + 1) * sizeof (char));
	if (ans == NULL)
		return (NULL);
	ft_memmove(ans, s, ft_strlen(s) + 1);
	return (ans);
}
