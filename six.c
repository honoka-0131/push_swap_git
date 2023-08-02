/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   six.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmakida <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 17:08:13 by hmakida           #+#    #+#             */
/*   Updated: 2023/08/02 13:46:48 by hmakida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"push_swap.h"
#include	"libft/libft.h"
#include	"printf/ft_printf.h"

void	sort_under_seven(t_list **stack_a, t_list **stack_b, size_t listsize)
{
	size_t	i;
	
	i = 1;
//	printf("check stack_a->comp %d\n", (*stack_a)->comp);
	while ((*stack_a)->comp != 0)
	{
		action_r(stack_a);
		ft_printf("ra\n");
//		printf("check 0\n");
	}
//	printf("check01\n");
	action_p(stack_a, stack_b);
	ft_printf("pb\n");
//	printf("check02\n");	
//	printf("check 1\n");
	if (listsize != 4)
	{
//		printf("check03\n");
		while (i <= 2)
		{
			while ((*stack_a)->comp != (int)i)
			{
				action_r(stack_a);
				ft_printf("ra\n");
			}
			action_p(stack_a, stack_b);
			ft_printf("pb\n");
//			printf("a %d b %d\n", (*stack_a)->comp, (*stack_b)->comp);
			i ++;
		}
	}
//	printf("%d %d %d\n", (*stack_a)->comp, (*stack_a)->next->comp, (*stack_a)->next->next->comp);//６つの時ここまでOK
	if (listsize == 4 || listsize == 6)
		sort_three_data(stack_a);
	else
	{
//		printf("check 5sort 1\n");
		if ((*stack_a)->comp > (*stack_a)->next->comp)
		{
			action_swap_two(stack_a);
			ft_printf("sa\n");
		}
	}
	if (listsize == 4)
		ft_printf("pa\n");
	else
		ft_printf("pa\npa\npa\n");
	return ;
}
