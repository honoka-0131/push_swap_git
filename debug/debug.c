#include "../push_swap.h"
#include <stdio.h>

int	show_stack(t_list *stack)
{
	t_list	*p;

	p = stack;
	while (p->next != stack)
	{
		printf("(%d)\n", p->comp);
		// if (p->next != NULL)
		p = p->next;
	}
	return (0);
}
