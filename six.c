/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   six.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmakida <hmakida@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 17:08:13 by hmakida           #+#    #+#             */
/*   Updated: 2023/08/20 13:33:22 by hmakida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"push_swap.h"
#include	"libft/libft.h"
#include	"printf/ft_printf.h"

void print_stack(t_list **stack)
{
	t_list *list;

	list = *stack;
	while (list != NULL)
	{
		printf("%d ", list->comp);
		list = list->next;
	}
	puts("");
}

void print_ps(t_list **stack_a, t_list **stack_b)
{
	printf("A: ");
	print_stack(stack_a);
	printf("B: ");
	print_stack(stack_b);
}

void	sort_stack_a(t_list ***list)
{
	int	first_num;
	int	second_num;

	first_num = (**list)->comp;
	second_num = (**list)->next->comp;
	**list = (**list)->next->next;
//	ft_printf("check fir %d sec %d trd %d\n", first_num, second_num, (**list)->comp);
	while (!(first_num < second_num && second_num < (**list)->comp))
	{
		//ft_printf("check fir %d sec %d trd %d\n", first_num, second_num, (**list)->comp);
		if (second_num > first_num && second_num > (**list)->comp)
		{
			**list = listfront(**list);
			action_rr(*list);
			ft_printf("rra\n");
		}
		else if (second_num < first_num && first_num > (**list)->comp)
		{
			**list = listfront(**list);
			action_r(*list);
			ft_printf("ra\n");
		}
		else if (first_num > second_num && first_num < (**list)->comp)
		{
			**list = listfront(**list);
			action_s(*list);
			ft_printf("sa\n");
		}
		first_num = (**list)->comp;
		**list = (**list)->next;
		second_num = (**list)->comp;
		**list = (**list)->next;
//		ft_printf("check fir %d sec %d trd %d\n", first_num, second_num, (**list)->comp);
	}
	while ((**list)->prev != NULL)
		**list = (**list)->prev;
}

void	sort_under_seven(t_list **stack_a, t_list **stack_b, size_t s_list)
{
	(void)s_list;
	int target;
	   
	target = 0;
	while (listsize(*stack_a) > 3)
	{
		if ((*stack_a)->comp == target)
		{
			action_p(stack_a, stack_b);
			ft_printf("pb\n");
			target ++;
		}
		else
		{
			action_r(stack_a);
			ft_printf("ra\n");
		}
//		print_ps(stack_a, stack_b);
	}
	sort_stack_a(&stack_a);
	while (listsize(*stack_b) > 1)
	{
		action_p(stack_b, stack_a);
		ft_printf("pa\n");
//		print_ps(stack_a, stack_b);
	}
	ft_printf("pa\n");
	return ;
// 	size_t	i;
	
// 	i = 1;
// //	printf("check stack_a->comp %d\n", (*stack_a)->comp);
// 	while ((*stack_a)->comp != 0)
// 	{
// 		action_r(stack_a);
// 		ft_printf("ra\n");
// //		printf("check 0\n");
// 	}
// //	printf("check01\n");
// 	action_p(stack_a, stack_b);
// 	ft_printf("pb\n");
// //	printf("check02\n");	
// //	printf("check 1\n");
// 	if (listsize != 4)
// 	{
// //		printf("check03\n");
// 		while (i <= 2)
// 		{
// 			while ((*stack_a)->comp != (int)i)
// 			{
// 				action_r(stack_a);
// 				ft_printf("ra\n");
// 			}
// 			action_p(stack_a, stack_b);
// 			ft_printf("pb\n");
// //			printf("a %d b %d\n", (*stack_a)->comp, (*stack_b)->comp);
// 			i ++;
// 		}
// 	}
// //	printf("%d %d %d\n", (*stack_a)->comp, (*stack_a)->next->comp, (*stack_a)->next->next->comp);//６つの時ここまでOK
// 	if (listsize == 4 || listsize == 6)
// 		sort_three_data(stack_a);
// 	else
// 	{
// //		printf("check 5sort 1\n");
// 		if ((*stack_a)->comp > (*stack_a)->next->comp)
// 		{
// 			action_swap_two(stack_a);
// 			ft_printf("sa\n");
// 		}
// 	}
// 	if (listsize == 4)
// 		ft_printf("pa\n");
// 	else
// 		ft_printf("pa\npa\npa\n");
// 	return ;
}
