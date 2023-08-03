/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   over_seven.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmakida <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 16:37:23 by hmakida           #+#    #+#             */
/*   Updated: 2023/08/03 21:14:02 by hmakida          ###   ########.fr       */
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

void	check_and_push_first(t_list **stack_a, t_list **stack_b, int num, int layer)
{
	//この中でbに入れる時に半分こするまだできてない
	size_t	i;
	size_t	list_size;
	int		num_half;

	i = 0;
	num_half = num / 2;
	printf("num = %d half = %d\n", num, num_half);
//	printf("a = %d %d %d\n", (*stack_a)->comp, (*stack_a)->next->comp, (*stack_a)->next->next->comp);
	list_size = listsize(*stack_a);
	while (i < list_size)
	{
		if ((*stack_a)->comp <= num)
		{
			action_p(stack_a, stack_b);
			ft_printf("pb\n");
			(*stack_b)->layer = layer + 1;
			if ((*stack_b)->comp <= num_half && (*stack_b)->next != NULL)
			{
				(*stack_b)->layer = (*stack_b)->layer - 1;
				action_r(stack_b);
				ft_printf("rb\n");
			}
		}
		else
		{
			action_r(stack_a);
			ft_printf("ra\n");
		}
		i ++;
	//	*stack_a = (*stack_a)->next;
//		printf("今のstack_a %d\n", (*stack_a)->comp);
	}
	return ;
}

void	check_and_push(t_list **stack_a, t_list **stack_b, int num, int layer)
{
	//この中でbに入れる時に半分こするまだできてない
	size_t	i;
	size_t	list_size;
	int		num_half;

	i = 0;
	num_half = (num + find_max(stack_b)) / 2;
	printf("num = %d half = %d\n", num, num_half);
//	printf("a = %d %d %d\n", (*stack_a)->comp, (*stack_a)->next->comp, (*stack_a)->next->next->comp);
	list_size = listsize(*stack_a);
	while (i < list_size)
	{
		printf("stack_a %d   b %d\n", (*stack_a)->comp, (*stack_b)->comp);
		if ((*stack_a)->comp <= num)
		{
			action_p(stack_a, stack_b);
			ft_printf("pb\n");
			(*stack_b)->layer = layer;
			if ((*stack_b)->comp >= num_half && (*stack_b)->next != NULL)
			{
				(*stack_b)->layer = (*stack_b)->layer + 1;
				action_r(stack_b);
				ft_printf("rb\n");
			}
		}
		else
		{
			action_r(stack_a);
			ft_printf("ra\n");
		}
		if (listsize(*stack_a) <= 3)
			break ;
		i ++;
	}
	
	return ;
}

void	sort_over_seven(t_list **stack_a, t_list **stack_b, size_t listsize)
{
	int	max;
	int	min;
	int	layer;//はんぶんこした時のどの層か。aに上下代わりばんこに戻す時使う

	layer = 0;
//	printf("listsize = %zu 割る20 = %f\n", listsize, (int)listsize * 0.2);
//	printf("check00\n");
	max = find_max(stack_a); //スタック全部チェックしてでかいの
//	printf("check01\n");
	min = find_min(stack_a); //上の小さいの
//	printf("check max = %d min = %d\n", max, min);
	check_and_push_first(stack_a, stack_b, (max + min) / 2, layer); //半分こ
	max = find_max(stack_a);
	min = find_min(stack_a);
	layer += 2;
	check_and_push(stack_a, stack_b, (max + min) / 2, layer);
//	printf("stack_a %d %d %d\n", (*stack_a)->comp, (*stack_a)->next->comp, (*stack_a)->next->next->comp);
//	printf("stack_b %d %d\n", (*stack_b)->comp, (*stack_b)->next->comp);
	printf("特に意味もなくlistsize%zu\n", listsize);
	printf("a %d %d %d\n", (*stack_a)->layer, (*stack_a)->next->layer, (*stack_a)->next->next->layer);
	printf("b %d %d %d %d %d %d %d\n", (*stack_b)->layer, (*stack_b)->next->layer, (*stack_b)->next->next->layer, (*stack_b)->next->next->next->layer, (*stack_b)->next->next->next->next->layer, (*stack_b)->next->next->next->next->next->layer, (*stack_b)->next->next->next->next->next->next->layer);

	return ;
}
