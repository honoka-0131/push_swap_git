/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmakida <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 20:10:32 by hmakida           #+#    #+#             */
/*   Updated: 2023/01/14 12:41:20 by hmakida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int c)
{
	if (0 <= c && c <= 127)
		return (1);
	return (0);
}

//int	main(void)
//{
//	printf("ft_isascii 'a' -> %d\n", ft_isascii('a'));
//	printf("ft_isascii '4' -> %d\n", ft_isascii('4'));
//	printf("ft_isascii 'NULL' -> %d\n", ft_isascii('\0'));
//	printf("isascii 'a' -> %d\n", isascii('a'));
//	printf("isascii '4' -> %d\n", isascii('4'));
//	printf("isascii 'NULL' -> %d\n", isascii('\0'));
//	return (0);
//}
