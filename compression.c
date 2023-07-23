/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compression.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmakida <hmakida@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 14:01:22 by hmakida           #+#    #+#             */
/*   Updated: 2023/07/23 18:29:28 by hmakida          ###   ########.fr       */
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
	size_t	i;
	size_t	list_size = listsize(*list);
	printf("fuga\n");
	i = 0;
//	ft_printf("check1\n");
	array = malloc(sizeof(int) * listsize(*list));
	if (array == NULL)
		return (NULL);
	while (i < listsize(*list))
	{
		array[i] = (*list)->data;
		i ++;
		*list = (*list)->next;
	}
	printf("list_size = %zu\n", list_size);
	while (i < list_size)
	{
		printf("%d\n", (*list)->data);
		i++;
	}
	// ft_printf("array %d %d %d %d %d\n", );
	sort = make_sort(array, listsize(*list));
	ft_printf("sort %d %d %d %d %d\n", sort[0], sort[1], sort[2], sort[3], sort[4]);
	return (NULL);
}
