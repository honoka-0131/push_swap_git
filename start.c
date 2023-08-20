/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmakida <hmakida@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 11:18:03 by hmakida           #+#    #+#             */
/*   Updated: 2023/08/20 16:15:48 by hmakida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft/libft.h"
#include	"printf/ft_printf.h"
#include	"push_swap.h"
#include	<stdlib.h>
#include 	<string.h>

int	check_argv_two(char **argv)
{
	size_t	i;
	size_t	j;

	i = 1;
	j = i + 1;
	while (argv[i])
	{
		while (argv[j])
		{
			if (ft_atoi(argv[i]) == ft_atoi(argv[j]))
			{
				ft_printf("Error\n");
				return (-1);
			}
			j ++;
		}
		i ++;
		j = i + 1;
	}
	return (1);
}

int	check_argv_one(char **argv)
{
	size_t	i;
	size_t	j;

	i = 1;
	j = 0;
	while (argv[i][j])
	{
		while (argv[i][j])
		{
			if (ft_isdigit(argv[i][j]) == 0 && argv[i][j] != '-')
			{
				ft_printf("Error\n");
				return (-1);
			}
			j ++;
		}
		j = 0;
		i ++;
		if (argv[i] == NULL)
			break ;
	}
	return (check_argv_two(argv));
}

t_list	*create_list(int data)
{
	t_list	*list;

	list = malloc(sizeof(t_list));
	if (list == NULL)
		return (NULL);
	list->data = data;
	list->prev = NULL;
	list->next = NULL;
	return (list);
}

void	add_list_back(t_list **list, int data, int layer)
{
	t_list	*new;
	t_list	*tmp;

	tmp = *list;
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
	}
	new = create_list(data);
	tmp->next = new;
	new->prev = tmp;
	new->layer = layer;
}

t_list	*make_stack_a(char **argv)
{
	t_list	*stack_a;
	size_t	i;
	size_t	list_size;

	if (check_argv_one(argv) < 0)
		return (NULL);
	stack_a = create_list(ft_atoi(argv[1]));
	i = 2;
	while (argv[i])
	{
		add_list_back(&stack_a, ft_atoi(argv[i]), 0);
		i ++;
	}
	i = 0;
	list_size = listsize(stack_a);
	while (i < list_size)
	{
		i ++;
	}
	return (compression(&stack_a));
}
