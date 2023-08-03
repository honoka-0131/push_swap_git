/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmakida <hmakida@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 11:01:51 by hmakida           #+#    #+#             */
/*   Updated: 2023/08/02 17:02:26 by hmakida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft/libft.h"
#include	"printf/ft_printf.h"
#include	"push_swap.h"
#include	<stdlib.h>

int	main(int argc, char *argv[])
{
	t_list	*stack_a;
	t_list	*stack_b;

	if (argc == 1)
		return (0);	
	stack_a = make_stack_a(argv);
	if (stack_a == NULL)
		return (0);
	if (listsize(stack_a) <= 3)
	{
		sort_three_data(&stack_a);
		return (0);
	}
	else if (listsize(stack_a) <= 6)
	{
		sort_under_seven(&stack_a, &stack_b, listsize(stack_a));
		return (0);
	}
	else
		sort_over_seven(&stack_a, &stack_b, listsize(stack_a));
}
