/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmakida <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 11:34:26 by hmakida           #+#    #+#             */
/*   Updated: 2023/02/01 01:07:23 by hmakida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

static void	number(long num, int fd)
{
	char	num_for_print;

	if (num > 9)
		number(num / 10, fd);
	num_for_print = num % 10 + 48;
	write(fd, &num_for_print, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	long	num;

	num = n;
	if (num < 0)
	{
		write(fd, "-", 1);
		num *= -1;
	}
	number (num, fd);
}
