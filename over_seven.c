/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   over_seven.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmakida <hmakida@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 16:37:23 by hmakida           #+#    #+#             */
/*   Updated: 2023/08/20 15:51:56 by hmakida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"push_swap.h"
#include	"libft/libft.h"
#include	"printf/ft_printf.h"

void print_stack_2(t_list **stack)
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

void print_ps_2(t_list **stack_a, t_list **stack_b)
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

void	check_and_push_first(t_list **stack_a, t_list **stack_b, int num, int layer)
{
	//この中でbに入れる時に半分こするまだできてない
	size_t	i;
	size_t	list_size;
	int		num_half;

	i = 0;
	num_half = num / 2;
//	printf("num = %d half = %d\n", num, num_half);
//	printf("a = %d %d %d\n", (*stack_a)->comp, (*stack_a)->next->comp, (*stack_a)->next->next->comp);
	list_size = listsize(*stack_a);
	while (i < list_size)
	{
		if ((*stack_a)->comp <= num)
		{
			action_p(stack_a, stack_b);
			ft_printf("pb\n");
			(*stack_b)->layer = layer;
	//		print_ps_2(stack_a, stack_b);
			if ((*stack_b)->comp <= num_half)
			{
				if ((*stack_b)->next != NULL)
				{
					(*stack_b)->layer = (*stack_b)->layer - 1;
					action_r(stack_b);
					ft_printf("rb\n");
		//			print_ps_2(stack_a, stack_b);
				}
				else	
					(*stack_b)->layer = (*stack_b)->layer - 1;
			}
		}
		else
		{
			action_r(stack_a);
			ft_printf("ra\n");
		//	print_ps_2(stack_a, stack_b);
		}
		i ++;
//		print_ps_2(stack_a, stack_b);
//		printf("今のstack_a %d\n", (*stack_a)->comp);
	}
	return ;
}

void	stack_b_rr(t_list **stack_b, int rr_layer)
{
//	printf("rr_layer = %d (*stack_b)->comp %d\n", rr_layer, (*stack_b)->comp);
	while (1)
	{
		*stack_b = listback(*stack_b);
//		printf("(*stack_b)->layer %d\n", (*stack_b)->layer);
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
	//この中でbに入れる時に半分こするまだできてない
	size_t	i;
	size_t	list_size;
	int		num_half;

	i = 0;
	num_half = (num + find_max(stack_b)) / 2;
//	printf("num = %d half = %d  listsize = %zu\n", num, num_half, listsize(*stack_a));
//	printf("a = %d %d %d\n", (*stack_a)->comp, (*stack_a)->next->comp, (*stack_a)->next->next->comp);
	list_size = listsize(*stack_a);
//	printf("ここのかくにん\n");
	while (i < list_size)
	{
//		printf("stack_a %d   b %d\n", (*stack_a)->comp, (*stack_b)->comp);
		if ((*stack_a)->comp <= num)
		{
			action_p(stack_a, stack_b);
			ft_printf("pb\n");
			(*stack_b)->layer = layer - 1;
	//		print_ps_2(stack_a, stack_b);
			if ((*stack_b)->comp >= num_half && (*stack_b)->next != NULL)
			{
				(*stack_b)->layer = layer;
				action_r(stack_b);
				ft_printf("rb\n");
	//			print_ps_2(stack_a, stack_b);
			}
		}
		else
		{
			action_r(stack_a);
			ft_printf("ra\n");
	//		print_ps_2(stack_a, stack_b);
		}
//		if (listsize(*stack_a) <= 3)//あかんパターンtimesの理由ここ
//			break ;
//		print_ps_2(stack_a, stack_b);
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
//	printf("check! min = %d (*stack_b)->comp = %d\n", min, (*stack_b)->comp);
	while (layer != 0)
	{
//		printf("check! min = %d layer %d\n", min, layer);
//		printf("b: %d %d %d\n", (*stack_b)->layer, (*stack_b)->next->layer, (*stack_b)->next->next->layer);
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
	//		print_ps_2(stack_a, stack_b);
		}
		min --;
		while (listback(*stack_b)->layer == layer)
		{
			*stack_b = listfront(*stack_b);
			action_rr(stack_b);
//			printf("min = %d layer %d\n", min, layer);
			ft_printf("rrb\n");
			if ((*stack_b)->comp == min)
			{
				action_p(stack_b, stack_a);
				ft_printf("pa\n");
				min --;
			}
//			print_ps_2(stack_a, stack_b);
		}
		layer = next_layer(stack_b);
	}
//		printf("[check]\na %d %d %d %d %d %d %d\n", (*stack_a)->comp, (*stack_a)->next->comp, (*stack_a)->next->next->comp, (*stack_a)->next->next->next->comp, (*stack_a)->next->next->next->next->comp, (*stack_a)->next->next->next->next->next->comp, (*stack_a)->next->next->next->next->next->next->comp);
//		printf("b %d %d\n", (*stack_b)->comp, (*stack_b)->next->comp);
	while (listsize(*stack_b) > 1)
	{
//		printf("!check!\n layer = %d min = %d\n", layer, min);
		if ((*stack_b)->comp == min)
		{
			action_p(stack_b, stack_a);
			ft_printf("pa\n");
//			print_ps_2(stack_a, stack_b);
			min --;
		}
		else
		{
			action_r(stack_b);
			ft_printf("rb\n");
//			print_ps_2(stack_a, stack_b);
		}
	}
	ft_printf("pa\n");
}

void	sort_over_seven(t_list **stack_a, t_list **stack_b)
{
	int	max;
	int	min;
	int	layer;//はんぶんこした時のどの層か。aに上下代わりばんこに戻す時使う

	layer = 1;
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
//	printf("特に意味もなくlistsize%zu\n", listsize);
//	printf("a %d %d\n", (*stack_a)->comp, (*stack_a)->next->comp);
//	printf("b %d %d %d %d %d %d %d %d\n", (*stack_b)->layer, (*stack_b)->next->layer, (*stack_b)->next->next->layer, (*stack_b)->next->next->next->layer, (*stack_b)->next->next->next->next->layer, (*stack_b)->next->next->next->next->next->layer, (*stack_b)->next->next->next->next->next->next->layer, (*stack_b)->next->next->next->next->next->next->next->layer);
	sort_three_data(stack_a);
//	print_ps_2(stack_a, stack_b);
//	printf("ここのチェック\n");
//	printf("a %d\n", (*stack_a)->next->comp);
	push_layer(stack_a, stack_b, layer, (*stack_a)->comp - 1);
	return ;
}
