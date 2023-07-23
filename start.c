/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmakida <hmakida@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 11:18:03 by hmakida           #+#    #+#             */
/*   Updated: 2023/07/23 20:02:59 by hmakida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft/libft.h"
#include	"printf/ft_printf.h"
#include	"push_swap.h"
#include	<stdlib.h>
#include 	<string.h>

int	check_argv_two(char **argv)
{
// こっちでーー１ーとか重複弾く
// まず重複だけ考えよう
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
// 弾くもの　数字とマイナス以外
// 弾けないもの　ーー１ーとか、重複（１　２　２　ー　４２ー）とか無理
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

void	add_list_back(t_list **list, int data)
{
	t_list	*new;
	t_list	*tmp;

//	ft_printf("check!!!!\n");
	tmp = *list;
//	ft_printf("tmp->data = %d\n", tmp->data);
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
	}
	new = malloc(sizeof(t_list));
	if (!new)
		return;
	// printf("data = %d\n", data);
	new->data = data;
	new->next = NULL;
	tmp->next = new;
	new->prev = tmp;
}

t_list	*make_stack_a(char **argv)
{
	t_list	*stack_a;
	t_list	*tmp;
	size_t	i;

	if (check_argv_one(argv) < 0)
		return (NULL);
	stack_a = malloc(sizeof(t_list));
	tmp = malloc(sizeof(t_list));
	if (stack_a == NULL)
		return (NULL);
	stack_a->data = ft_atoi(argv[1]);
	stack_a->prev = NULL;
	stack_a->next = NULL;
	tmp->data = ft_atoi(argv[1]);
	tmp->prev = NULL;
	tmp->next = NULL;
	i = 2;
//	ft_printf("argv[0] %s [1] %s [2]%s\n", argv[0], argv[1], argv[2]);//ここはOK
//	ft_printf("stack_a %d\n", stack_a->data);
	while (argv[i])
	{
		add_list_back(&stack_a, ft_atoi(argv[i]));
		add_list_back(&tmp, ft_atoi(argv[i]));
		i++;
	}
	i = 0;
	size_t	list_size = listsize(stack_a);
//	return (NULL); //一旦確認のやつ
	printf("listsize = %zu\n", listsize(stack_a));
	while (i < list_size)
	{
		printf("stack_a %zu = %d\n",i, tmp->data);
		tmp = tmp->next;
		i++;
	}
	printf("fuga\n");
	return (compression(&stack_a));
}
