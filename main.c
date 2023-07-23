/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmakida <hmakida@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 11:01:51 by hmakida           #+#    #+#             */
/*   Updated: 2023/07/23 18:04:36 by hmakida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft/libft.h"
#include	"printf/ft_printf.h"
#include	"push_swap.h"
#include	<stdlib.h>

int	main(int argc, char *argv[])
{
	t_list	*stack_a;
//	t_list	*stack_b;使ってないって怒られるから一旦消す

	if (argc == 1)
		return (0);
	
	stack_a = make_stack_a(argv);
	if (stack_a == NULL)
		return (0);
	// ここで数字のダブりチェック、マロックエラーのやつと座標圧縮までやる。引っかかった時点でNULLで弾く、物によってはエラー書いてね
}
