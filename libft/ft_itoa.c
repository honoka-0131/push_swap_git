/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmakida <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 17:51:47 by hmakida           #+#    #+#             */
/*   Updated: 2023/01/26 19:55:39 by hmakida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

size_t	check_digit(long num)
{
	size_t	digit;

	digit = 1;
	if (num < 0)
	{
		digit ++;
		num *= -1;
	}
	while (9 < num)
	{
		digit ++;
		num = num / 10;
	}
	return (digit);
}

char	*ft_itoa(int n)
{
	long	num;
	size_t	digit;
	int		i;
	char	*ans;

	num = (long)n;
	digit = check_digit(num);
	i = digit;
	ans = malloc((digit + 1) * sizeof (char));
	if (ans == NULL)
		return (NULL);
	if (num < 0)
	{
		ans[0] = '-';
		num *= -1;
	}
	while (9 < num)
	{
		ans[i - 1] = '0' + num % 10;
		i --;
		num = num / 10;
	}
	ans[i - 1] = '0' + num;
	ans[digit] = '\0';
	return (ans);
}

//int	main(void)
//{
//	printf("%s", ft_itoa(-2147483648));
//	return (0);
//}
