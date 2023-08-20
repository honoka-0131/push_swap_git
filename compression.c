/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compression.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmakida <hmakida@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 14:01:22 by hmakida           #+#    #+#             */
/*   Updated: 2023/08/19 17:44:44 by hmakida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"push_swap.h"
#include	"libft/libft.h"
#include	"printf/ft_printf.h"

size_t	listsize(t_list *list)
{
	size_t	i;

	if (list == NULL)
		return (0);
	i = 1;
	while (list->next != NULL)
	{
		i ++;
		list = list->next;
	}
	return (i);
}

int	search_min(int *array, size_t size)
{
	int		min;
	size_t	i;

	min = array[0];
	i = 0;
	while (i < size)
	{
		if (min > array[i])
			min = array[i];
		i ++;
	}
	return (min);
}

int	*make_sort(int *array, size_t size)
{
	int		tmp;
	size_t	i;
	size_t	j;

	tmp = array[0];
	i = 0;
	j = 1;
	while (i < size)
	{
		while (j < size)
		{
			if (array[j] < array[i])
			{
				tmp = array[i];
				array[i] = array[j];
				array[j] = tmp;
			}
			j ++;
		}
		i ++;
		j = i + 1;
	}
	return (array);
}

void	put_comp(t_list **list, int	*sort, size_t size)
{
	size_t	i;

	i = 0;
	*list = listfront(*list);
	while (i < size)
	{
		while (i < size)
		{
			if (sort[i] == (*list)->data)
			{
				(*list)->comp = i;
				i ++;
				break ;
			}
			*list = (*list)->next;
		}
		*list = listfront(*list);
	}
}

t_list	*compression(t_list **list)
{
	int		*array;
	int		*sort;
	size_t	i;
	size_t list_size;

	i = 0;
	list_size = listsize(*list);
	array = malloc(sizeof(int) * list_size);
	// tmp = malloc(sizeof(t_list));
	// if (array == NULL || tmp == NULL)
	// 	return (NULL);
	
	// tmp->data = (*list)->data;
	// tmp->prev = NULL;
	// tmp->next = NULL;

	// while ( i < list_size)
	// {
	// 	add_list_back(&tmp, (*list)->data);
	// 	(*list) = (*list)->next;
	// 	tmp = tmp->next;
	// 	i++;
	// }
	// while ( i > 0)
	// {
	// 	tmp = tmp->prev;
	// 	i--;
	// }
	i = 0;
	while (i < list_size)
	{
		array[i] = (*list)->data;
		i ++;
		if ((*list)->next != NULL)
			(*list) = (*list)->next;
	}
//	ft_printf("array %d %d %d %d %d\n", array[0], array[1], array[2], array[3], array[4]);
	*list = listfront(*list);
	sort = make_sort(array, listsize(*list));
//	ft_printf("sort %d %d %d %d %d\n", sort[0], sort[1], sort[2], sort[3], sort[4]);
	put_comp(list, sort, listsize(*list));
//	ft_printf("check comp %d %d %d\n", (*list)->comp, (*list)->next->comp, (*list)->next->next->comp);
	return (*list);
}
