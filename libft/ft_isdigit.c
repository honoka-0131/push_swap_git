/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmakida <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 20:08:56 by hmakida           #+#    #+#             */
/*   Updated: 2023/01/14 12:36:36 by hmakida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	if ('0' <= c && c <= '9')
		return (1);
	return (0);
}

//int	main(void)
//{
//	printf("ft_isdigit 'a' -> %d\n", ft_isdigit('a'));
//	printf("ft_isdigit '4' -> %d\n", ft_isdigit('4'));
//	printf("ft_isdigit 'NULL' -> %d\n", ft_isdigit('\0'));
//	printf("isdigit 'a' -> %d\n", isdigit('a'));
//	printf("isdigit '4' -> %d\n", isdigit('4'));
//	printf("isdigit 'NULL' -> %d\n", isdigit('\0'));
//	return (0);
//}
