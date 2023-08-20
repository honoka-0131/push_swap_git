/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   six.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmakida <hmakida@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 17:08:13 by hmakida           #+#    #+#             */
/*   Updated: 2023/08/20 16:14:03 by hmakida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"push_swap.h"
#include	"libft/libft.h"
#include	"printf/ft_printf.h"

void	print_stack(t_list **stack)
{
	t_list	*list;

	list = *stack;
	while (list != NULL)
	{
		printf("%d ", list->comp);
		list = list->next;
	}
	puts("");
}

void	print_ps(t_list **stack_a, t_list **stack_b)
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
	while (!(first_num < second_num && second_num < (**list)->comp))
	{
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
	}
	while ((**list)->prev != NULL)
		**list = (**list)->prev;
}

void	sort_under_seven(t_list **stack_a, t_list **stack_b)
{
	int	target;

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
	}
	sort_stack_a(&stack_a);
	while (listsize(*stack_b) > 1)
	{
		action_p(stack_b, stack_a);
		ft_printf("pa\n");
	}
	ft_printf("pa\n");
	return ;
}
