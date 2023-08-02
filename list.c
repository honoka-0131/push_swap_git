/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmakida <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 18:53:32 by hmakida           #+#    #+#             */
/*   Updated: 2023/07/30 17:05:00 by hmakida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"push_swap.h"
#include	"libft/libft.h"
#include	"printf/ft_printf.h"

t_list	*listfront(t_list *list)
{
	t_list	*tmp;

	tmp = list;
	while (tmp->prev != NULL)
	{
		tmp = tmp->prev;
	}
	return (tmp);
}



void	add_list_front(t_list **list, int comp)
{
	t_list	*new;
	t_list	*tmp;

	tmp = *list;
	while (tmp->prev != NULL)
		tmp = tmp->prev;
	new = malloc(sizeof(t_list));
	new->comp = comp;
	new->next = tmp;
	tmp->prev = new;
	new->prev = NULL;
	return ;
}
