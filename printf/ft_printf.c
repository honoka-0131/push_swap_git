/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmakida <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 11:57:32 by hmakida           #+#    #+#             */
/*   Updated: 2023/03/01 12:09:46 by hmakida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_printf.h"

size_t	if_not_per(const char *fmt, int *ret)
{
	size_t	i;

	i = 0;
	if (fmt[0] == '%' && fmt[1] == '%')
	{
		write(1, "%", 1);
		*ret += 1;
		return (2);
	}
	while (fmt[i] != '%' && fmt[i] != '\0')
	{
		write(1, &fmt[i], 1);
		i ++;
		*ret += 1;
	}
	return (i);
}

size_t	alpha_cdi(const char *fmt, int arg, int *ret)
{
	size_t	i;
	char	*str;

	i = 0;
	if (fmt[1] == 'c')
	{
		write(1, &arg, 1);
		*ret += 1;
		return (2);
	}
	str = ft_itoa(arg);
	if (str == NULL)
		return (2);
	while (str[i])
	{
		write(1, &str[i], 1);
		i ++;
		*ret += 1;
	}
	free(str);
	return (2);
}

size_t	alpha_s(char *arg, int *ret)
{
	size_t	i;

	if (arg == NULL)
	{
		write(1, "(null)", 6);
		*ret += 6;
		return (2);
	}
	i = 0;
	while (arg[i])
	{
		write(1, &arg[i], 1);
		i ++;
		*ret += 1;
	}
	return (2);
}

int	ft_printf(const char *fmt, ...)
{
	size_t	i;
	va_list	ap;
	int		ret;

	i = 0;
	ret = 0;
	va_start(ap, fmt);
	while (fmt[i])
	{
		if (fmt[i] == '%' && (fmt[i + 1] == 'c'
				|| fmt[i + 1] == 'd' || fmt[i + 1] == 'i'))
			i += alpha_cdi(&fmt[i], va_arg(ap, int), &ret);
		if (fmt[i] == '%' && fmt[i + 1] == 's')
			i += alpha_s(va_arg(ap, char *), &ret);
		if (fmt[i] == '%' && (fmt[i + 1] == 'u'
				|| fmt[i + 1] == 'x' || fmt[i + 1] == 'X'))
			i += alpha_ux(&fmt[i], va_arg(ap, unsigned int), &ret);
		if (fmt[i] == '%' && fmt[i + 1] == 'p')
			i += alpha_p(&fmt[i + 1], va_arg(ap, uintptr_t), &ret);
		else
			i += if_not_per(&fmt[i], &ret);
	}
	va_end(ap);
	return (ret);
}
