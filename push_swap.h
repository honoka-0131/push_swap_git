/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmakida <hmakida@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 16:41:21 by hmakida           #+#    #+#             */
/*   Updated: 2023/07/23 19:03:40 by hmakida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include	<stdlib.h>

typedef struct	s_list
{
	struct s_list	*next;
	struct s_list	*prev;
	int				data;
	int				comp;
}				t_list;

t_list	*make_stack_a(char **argv);
t_list	*compression(t_list **list);
void	add_list_back(t_list **list, int data);
size_t	listsize(t_list *list);
#endif
