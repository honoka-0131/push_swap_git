/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compression.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmakida <hmakida@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 14:01:22 by hmakida           #+#    #+#             */
/*   Updated: 2023/07/23 20:06:07 by hmakida          ###   ########.fr       */
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

t_list	*compression(t_list **list)
{
	int		*array;
	int		*sort;
	t_list	*tmp;
	size_t	i;

	printf("fuga\n");
	i = 0;
//	ft_printf("check1\n");
	printf("listsize(*list) = %zu\n", listsize(*list));
	array = malloc(sizeof(int) * listsize(*list));
	tmp = malloc(sizeof(t_list));
	if (array == NULL || tmp == NULL)
		return (NULL);
	
	// tmp->data = (*list)->data;
	tmp->prev = NULL;
	tmp->next = NULL;

	printf("fugafuga\n");
	printf("%zu\n",listsize(*list));
	// while (i < listsize(*list))
	// {
	// 	printf("list[%zu] = %d\n", i, (*list)->data);
	// 	i++;
	// }
	size_t list_size = listsize(*list);
	while ( i < list_size)
	{
		printf("%zu : list = %d\n", i, (*list)->data);
		printf("%zu : tmp = %d\n", i, tmp->data);
		add_list_back(&tmp, (*list)->data);
		printf("tmp add\n");
		(*list) = (*list)->next;
		tmp = tmp->next;
		i++;
	}
	while ( i > 0)
	{
		tmp = tmp->prev;
		i--;
	}

	printf("hoge\n");
	i = 0;
	while (i < list_size)
	{
		printf("tmp->data = %d\n", tmp->next->data);
		array[i] = tmp->next->data;
		i++;
		tmp = tmp->next;
	}

	ft_printf("array %d %d %d %d %d\n", array[0], array[1], array[2], array[3], array[4]);
	sort = make_sort(array, listsize(*list));
	ft_printf("sort %d %d %d %d %d\n", sort[0], sort[1], sort[2], sort[3], sort[4]);
	return (NULL);
}
