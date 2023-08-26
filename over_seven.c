/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   over_seven.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akihito <akihito@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 16:37:23 by hmakida           #+#    #+#             */
/*   Updated: 2023/08/26 23:13:09 by akihito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"push_swap.h"
#include	"libft/libft.h"
#include	"printf/ft_printf.h"

void	print_stack_2(t_list **stack)
{
	t_list	*list;

	list = *stack;
	while (list != NULL)
	{
		printf("%d -", list->comp);
		printf("%d \n", list->data);
		list = list->next;
	}
	puts("");
}

void	print_ps_2(t_list **stack_a, t_list **stack_b)
{
	printf("A: ");
	print_stack_2(stack_a);
	printf("B: ");
	print_stack_2(stack_b);
}

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

void	push_first(t_list **stack_a, t_list **stack_b, int num, int layer)
{
	size_t	i;
	size_t	list_size;
	int		num_half;

	i = 0;
	num_half = num / 2;
	list_size = listsize(*stack_a);
	while (i < list_size)
	{
		if ((*stack_a)->comp <= num)
		{
			action_p(stack_a, stack_b);
			ft_printf("pb\n");
			(*stack_b)->layer = layer;
			if ((*stack_b)->comp <= num_half)
			{
				if ((*stack_b)->next != NULL)
				{
					(*stack_b)->layer = (*stack_b)->layer - 1;
					action_r(stack_b);
					ft_printf("rb\n");
				}
				else
					(*stack_b)->layer = (*stack_b)->layer - 1;
			}
		}
		else
		{
			action_r(stack_a);
			ft_printf("ra\n");
		}
		i ++;
	}
	return ;
}

void	stack_b_rr(t_list **stack_b, int rr_layer)
{
	while (1)
	{
		*stack_b = listback(*stack_b);
		if ((*stack_b)->layer != rr_layer)
			break ;
		action_rr(stack_b);
		ft_printf("rrb\n");
	}
	*stack_b = listfront(*stack_b);
	return ;
}

void	check_and_push(t_list **stack_a, t_list **stack_b, int num, int layer)
{
	size_t	i;
	size_t	list_size;
	int		num_half;

	i = 0;
	num_half = (num + find_max(stack_b)) / 2;
	list_size = listsize(*stack_a);
	while (i < list_size)
	{
		if ((*stack_a)->comp <= num)
		{
			action_p(stack_a, stack_b);
			ft_printf("pb\n");
			(*stack_b)->layer = layer - 1;
			if ((*stack_b)->comp >= num_half && (*stack_b)->next != NULL)
			{
				(*stack_b)->layer = layer;
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
	}
	stack_b_rr(stack_b, layer);
	return ;
}

int	next_layer(t_list **stack_b)
{
	int	ret;

	ret = (*stack_b)->layer;
	while ((*stack_b)->next != NULL)
	{
		if ((*stack_b)->layer > ret)
			ret = (*stack_b)->layer;
		*stack_b = (*stack_b)->next;
	}
	*stack_b = listfront(*stack_b);
	return (ret);
}

void	push_layer(t_list **stack_a, t_list **stack_b, int layer, int min)
{
	while (layer != 0)
	{
		while ((*stack_b)->layer == layer)
		{
			if ((*stack_b)->comp == min)
			{
				action_p(stack_b, stack_a);
				ft_printf("pa\n");
			}
			else
			{	
				action_r(stack_b);
				ft_printf("rb\n");
			}
		}
		min --;
		while (listback(*stack_b)->layer == layer)
		{
			*stack_b = listfront(*stack_b);
			action_rr(stack_b);
			ft_printf("rrb\n");
			if ((*stack_b)->comp == min)
			{
				action_p(stack_b, stack_a);
				ft_printf("pa\n");
				min --;
			}
		}
		layer = next_layer(stack_b);
	}
	while (listsize(*stack_b) > 1)
	{
		if ((*stack_b)->comp == min)
		{
			action_p(stack_b, stack_a);
			ft_printf("pa\n");
			min --;
		}
		else
		{
			action_r(stack_b);
			ft_printf("rb\n");
		}
	}
	ft_printf("pa\n");
}

void	sort_over_seven(t_list **stack_a, t_list **stack_b)
{
	int	max;
	int	min;
	int	layer;

	layer = 1;
	max = find_max(stack_a);
	min = find_min(stack_a);
	push_first(stack_a, stack_b, (max + min) / 2, layer);
	max = find_max(stack_a);
	min = find_min(stack_a);
	layer += 2;
	check_and_push(stack_a, stack_b, (max + min) / 2, layer);
	sort_three_data(stack_a);
	push_layer(stack_a, stack_b, layer, (*stack_a)->comp - 1);
	return ;
}
