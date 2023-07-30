/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmakida <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 16:35:45 by hmakida           #+#    #+#             */
/*   Updated: 2023/07/30 17:00:12 by hmakida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"push_swap.h"
#include	"libft/libft.h"
#include	"printf/ft_printf.h"

void	action_rr(t_list **list)
{
	t_list	*tmp;

	while ((*list)->next != NULL)
		*list = (*list)->next;
	tmp = *list;
	*list = (*list)->prev;
	(*list)->next = NULL;
	while ((*list)->prev != NULL)
		*list = (*list)->prev;
	add_list_front(list, tmp->comp);
	while ((*list)->prev != NULL)
		*list = (*list)->prev;
	return ;
}

void	action_r(t_list **list)
{
	t_list	*tmp;

	//printf("list->comp %d\n", (*list)->comp);
	tmp = *list;
	printf("tmp->comp %d\n", tmp->comp);
	printf("list->comp %d ,next->comp %d nenecomp %d\n", (*list)->comp, (*list)->next->comp, (*list)->next->next->comp);
	*list = (*list)->next;
	free((*list)->prev);
	(*list)->prev = NULL;
	while ((*list)->next != NULL)
		*list = (*list)->next;
	add_list_back(list, tmp->comp);
	while ((*list)->prev != NULL)
		*list = (*list)->prev;
	return ;
}

void	action_s(t_list **list)
{
	int	tmp_one;
	int	tmp_two;

	tmp_one = (*list)->comp;
	*list = (*list)->next;
	tmp_two = (*list)->comp;
	*list = (*list)->next;
	while ((*list)->prev != NULL)
		*list = (*list)->prev;
	(*list)->comp = tmp_two;
	*list = (*list)->next;
	(*list)->comp = tmp_one;
	while ((*list)->prev != NULL)
		*list = (*list)->prev;
	return ;
}
