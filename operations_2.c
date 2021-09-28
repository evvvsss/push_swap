#include "push_swap.h"

void	sa_sb(t_info **a, char name, t_elem **el)
{
	t_info	*c;

	if ((*a) != NULL && (*a)->next != NULL)
	{
		c = *a;
		(*a) = (*a)->next;
		c->next = (*a)->next;
		(*a)->next = c;
	}
	else
		return ;
	if (name == 'a')
		write(1, "sa\n", 3);
	else if (name == 'b')
		write(1, "sb\n", 3);
	(*el)->counter++;
}

void	ss(t_info **a, t_info **b, t_elem **el)
{
	sa_sb(a, 'c', el);
	sa_sb(b, 'c', el);
	write(1, "ss\n", 3);
	(*el)->counter++;
}
