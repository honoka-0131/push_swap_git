/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   three.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmakida <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 15:04:41 by hmakida           #+#    #+#             */
/*   Updated: 2023/08/20 13:29:17 by hmakida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"push_swap.h"
#include	"libft/libft.h"
#include	"printf/ft_printf.h"

void	sort_two_data(t_list ***list)
{
	int	tmp;

	if ((**list)->comp > (**list)->next->comp)
	{
		tmp = (**list)->comp;
		(**list)->comp = (**list)->next->comp;
		(**list)->next->comp = tmp;
		ft_printf("sa\n");
	}
}

void	sort_three_data(t_list **list)
{
	int	first_num;
	int	second_num;

	if (listsize(*list) == 2)
	{
		sort_two_data(&list);
		return ;
	}
	first_num = (*list)->comp;
	second_num = (*list)->next->comp;
	*list = (*list)->next->next;
//	printf("3sort check firnum %d\n", first_num);
	while (!(first_num < second_num && second_num < (*list)->comp))
	{
		if (second_num > first_num && second_num > (*list)->comp)
		{
			*list = listfront(*list);
			action_rr(list);
			ft_printf("rra\n");
		}
		else if (second_num < first_num && first_num > (*list)->comp)
		{
			*list = listfront(*list);
			action_r(list);
			ft_printf("ra\n");
		}
		else if (first_num > second_num && first_num < (*list)->comp)
		{
			*list = listfront(*list);
			action_s(list);
			ft_printf("sa\n");
		}
		first_num = (*list)->comp;
		*list = (*list)->next;
		second_num = (*list)->comp;
		*list = (*list)->next;		
//		printf("fir %d sec %d (*list)comp %d\n", first_num, second_num, (*list)->comp);
	}
	while ((*list)->prev != NULL)
		*list = (*list)->prev;
}
