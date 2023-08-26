/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akihito <akihito@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 11:01:51 by hmakida           #+#    #+#             */
/*   Updated: 2023/08/26 23:32:40 by akihito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft/libft.h"
#include	"printf/ft_printf.h"
#include	"push_swap.h"
#include	<stdlib.h>

void	print_stack2(t_list *stack)
{
	t_list	*list;

	list = stack;
	while (list != NULL)
	{
		printf("%d ", list->comp);
		list = list->next;
	}
	puts("");
}

int	main(int argc, char *argv[])
{
	t_list	*stack_a;
	t_list	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	(void)stack_b;
	if (argc == 1)
		return (0);
	stack_a = make_stack_a(argv);
	print_stack2(stack_a);
	if (stack_a == NULL)
		return (0);
	if (listsize(stack_a) <= 3)
	{
		sort_three_data(&stack_a);
		return (0);
	}
	else if (listsize(stack_a) <= 6)
	{
		sort_under_seven(&stack_a, &stack_b);
		return (0);
	}
	else
		sort_over_seven(&stack_a, &stack_b);
}
