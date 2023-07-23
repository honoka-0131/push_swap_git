/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmakida <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 10:49:50 by hmakida           #+#    #+#             */
/*   Updated: 2023/01/14 12:42:26 by hmakida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	if (32 <= c && c <= 126)
		return (1);
	return (0);
}

//int	main(void)
//{
//	printf("ft_isprint 'a' -> %d\n", ft_isprint('a'));
//	printf("ft_isprint '4' -> %d\n", ft_isprint('4'));
//	printf("ft_isprint 'NULL' -> %d\n", ft_isprint('\0'));
//	printf("isprint 'a' -> %d\n", isprint('a'));
//	printf("isprint '4' -> %d\n", isprint('4'));
//	printf("isprint 'NULL' -> %d\n", isprint('\0'));
//	return (0);
//}
