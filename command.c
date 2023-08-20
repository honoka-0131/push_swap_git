/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmakida <hmakida@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 16:35:45 by hmakida           #+#    #+#             */
/*   Updated: 2023/08/20 16:02:06 by hmakida          ###   ########.fr       */
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
	add_list_front(list, tmp->comp, tmp->layer);
	while ((*list)->prev != NULL)
		*list = (*list)->prev;
	return ;
}

void	action_r(t_list **list)
{
	t_list	*tmp;

	tmp = *list;
	*list = (*list)->next;
	free((*list)->prev);
	(*list)->prev = NULL;
	while ((*list)->next != NULL)
		*list = (*list)->next;
	add_list_back(list, tmp->comp, tmp->layer);
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

void	action_p(t_list **list_one, t_list **list_two)
{
	t_list	*tmp;

	tmp = *list_one;
	*list_one = (*list_one)->next;
	(*list_one)->prev = NULL;
	if (*list_two == NULL)
	{
		*list_two = tmp;
		(*list_two)->next = NULL;
		return ;
	}
	tmp->next = *list_two;
	(*list_two)->prev = tmp;
	*list_two = (*list_two)->prev;
	return ;
}

void	action_swap_two(t_list **list)
{
	t_list	*tmp;

	tmp = *list;
	*list = (*list)->next;
	(*list)->next = tmp;
	(*list)->prev = NULL;
	tmp->prev = *list;
	tmp->next = NULL;
	return ;
}
