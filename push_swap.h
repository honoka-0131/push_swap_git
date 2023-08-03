/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmakida <hmakida@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 16:41:21 by hmakida           #+#    #+#             */
/*   Updated: 2023/08/03 20:53:59 by hmakida          ###   ########.fr       */
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
	int				layer;
}				t_list;

t_list	*make_stack_a(char **argv);
t_list	*compression(t_list **list);
t_list	*listfront(t_list *list);
void	add_list_back(t_list **list, int comp);
void	add_list_front(t_list **list, int comp);
void	sort_three_data(t_list **list);
void	sort_under_seven(t_list **stack_a, t_list **stack_b, size_t listsize);
void	sort_over_seven(t_list **stack_a, t_list **stack_b, size_t listsize);
void	action_rr(t_list **list);
void	action_r(t_list **list);
void	action_s(t_list **list);
void	action_p(t_list **list_one, t_list **list_two);
void	action_swap_two(t_list **list);
size_t	listsize(t_list *list);
#endif
