/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   over_seven.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmakida <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 16:37:23 by hmakida           #+#    #+#             */
/*   Updated: 2023/08/03 19:00:10 by hmakida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"push_swap.h"
#include	"libft/libft.h"
#include	"printf/ft_printf.h"

int	find_max(t_list **stack_a)
{
	int	max;
	
	max = (*stack_a)->comp;
	*stack_a = (*stack_a)->next;
	while ((*stack_a)->next != NULL)
	{
		if ((*stack_a)->comp > max)
			max = (*stack_a)->comp;
		*stack_a = (*stack_a)->next;
	}
	if ((*stack_a)->comp > max)
		max = (*stack_a)->comp;
	*stack_a = listfront(*stack_a);
	return (max);
}

int	find_min(t_list **stack_a)
{
	int	min;

	min = (*stack_a)->comp;
	*stack_a = (*stack_a)->next;
	while ((*stack_a)->next != NULL)
	{
		if ((*stack_a)->comp < min)
			min = (*stack_a)->comp;
		*stack_a = (*stack_a)->next;
	}
	if ((*stack_a)->comp < min)
		min = (*stack_a)->comp;
	*stack_a = listfront(*stack_a);
	return (min);
}

void	check_and_push(t_list **stack_a, t_list **stack_b, int num)
{
	while ((*stack_a)->next != NULL)
	{
		if ((*stack_a)->comp < num)
			action_p(stack_a, stack_b);
		else
			action_r(stack_a);
		*stack_a = (*stack_a)->next;
	}
	return ;
}

void	sort_over_seven(t_list **stack_a, t_list **stack_b, size_t listsize)
{
	int	max;
	int	min;

//	printf("listsize = %zu 割る20 = %f\n", listsize, (int)listsize * 0.2);
	printf("check00\n");
	max = find_max(stack_a); //スタック全部チェックしてでかいの
	printf("check01\n");
	min = find_min(stack_a); //上の小さいの
	printf("check max = %d min = %d\n", max, min);
	check_and_push(stack_a, stack_b, (max + min) / 2); //半分こ
//	printf("stack_a %d %d %d\n", (*stack_a)->comp, (*stack_a)->next->comp, (*stack_a)->next->next->comp);
//	printf("stack_b %d %d\n", (*stack_b)->comp, (*stack_b)->next->comp);
	printf("使ってないって怒られるから出力しとけ%zu\n", listsize);
	return ;
}
