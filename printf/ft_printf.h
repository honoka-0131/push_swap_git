/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmakida <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 11:39:10 by hmakida           #+#    #+#             */
/*   Updated: 2023/02/15 20:18:01 by hmakida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

char	*ft_itoa(int n);
size_t	ft_strlen(const char *str);
int		ft_printf(const char *fmt, ...);
size_t	alpha_ux(const char *fmt, unsigned int arg, int *ret);
size_t	alpha_p(const char *fmt, uintptr_t ptr, int *ret);

#endif
