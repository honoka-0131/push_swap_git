/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compression.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmakida <hmakida@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 14:01:22 by hmakida           #+#    #+#             */
/*   Updated: 2023/08/20 16:04:40 by hmakida          ###   ########.fr       */
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
	size_t	list_size;

	i = 0;
	list_size = listsize(*list);
	array = malloc(sizeof(int) * list_size);
	i = 0;
	while (i < list_size)
	{
		array[i] = (*list)->data;
		i ++;
		if ((*list)->next != NULL)
			(*list) = (*list)->next;
	}
	*list = listfront(*list);
	sort = make_sort(array, listsize(*list));
	put_comp(list, sort, listsize(*list));
	return (*list);
}
