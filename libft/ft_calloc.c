/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmakida <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 10:58:51 by hmakida           #+#    #+#             */
/*   Updated: 2023/01/22 21:10:10 by hmakida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

void	*ft_calloc(size_t n, size_t size)
{
	void	*ans;

	if (n == 0 || size == 0)
		return (ft_calloc(1, 1));
	if (SIZE_MAX / size < n)
		return (NULL);
	ans = malloc(n * size);
	if (ans == NULL)
		return (NULL);
	ft_bzero(ans, n * size);
	return (ans);
}
