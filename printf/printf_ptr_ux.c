/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_ptr_ux.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmakida <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 12:16:23 by hmakida           #+#    #+#             */
/*   Updated: 2023/02/15 21:04:42 by hmakida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_printf.h"

static void	print_ptr(const char *fmt, uintptr_t ptr, int *ret)
{
	long	i;
	char	print;

	i = ptr % 16;
	ptr = ptr / 16;
	if (ptr > 0)
		print_ptr(fmt, ptr, ret);
	if (0 <= i && i <= 9)
	{
		print = i + '0';
		write(1, &print, 1);
		*ret += 1;
	}
	else if (9 < i)
	{
		print = 'a' + i - 10;
		write(1, &print, 1);
		*ret += 1;
	}
}

size_t	alpha_p(const char *fmt, uintptr_t ptr, int *ret)
{
	int	tmp;

	tmp = *ret;
	write(1, "0x", 2);
	*ret += 2;
	print_ptr(fmt, ptr, ret);
	return (2);
}

static void	print_hex(unsigned int arg, int *ret, char alpha)
{
	char	print;
	int		i;

	i = arg % 16;
	arg = arg / 16;
	if (arg > 0)
		print_hex(arg, ret, alpha);
	if (0 <= i && i <= 9)
	{
		print = i + '0';
		write(1, &print, 1);
		*ret += 1;
	}
	else if (9 < i)
	{
		if (alpha == 'x')
			print = 'a' + i - 10;
		else if (alpha == 'X')
			print = 'A' + i - 10;
		write(1, &print, 1);
		*ret += 1;
	}
}

static void	write_number(unsigned int num, int *ret)
{
	char	num_for_print;

	if (num > 9)
		write_number(num / 10, ret);
	num_for_print = num % 10 + '0';
	write(1, &num_for_print, 1);
	*ret += 1;
}

size_t	alpha_ux(const char *fmt, unsigned int arg, int *ret)
{
	if (fmt[1] == 'u')
		write_number(arg, ret);
	if (fmt[1] == 'x' || fmt[1] == 'X')
		print_hex(arg, ret, (char)fmt[1]);
	return (2);
}
