/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmakida <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 18:53:32 by hmakida           #+#    #+#             */
/*   Updated: 2023/07/29 14:27:23 by hmakida          ###   ########.fr       */
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
//	tmp = tmp->next;
//	printf("check %d\n", tmp->data);
	return (tmp);
}
