#include "push_swap.h"

void	pa_pb(t_info **first, t_info **second, char name, t_elem **el)
{
	t_info	*tmp;

	if (!(*second))
		return ;
	if (!*first)
	{
		*first = *second;
		*second = (*second)->next;
		(*first)->next = NULL;
	}
	else
	{
		tmp = *second;
		*second = (*second)->next;
		ft_lstadd_front(first, tmp);
	}
	if (name == 'a')
		write(1, "pa\n", 3);
	else if (name == 'b')
		write(1, "pb\n", 3);
	(*el)->cnt++;
}

void	rrr(t_info **a, t_info **b, t_elem **el)
{
	rra_rrb(a, 'a', el);
	rra_rrb(b, 'b', el);
	write(1, "rrr\n", 4);
	(*el)->cnt++;
}

void	rra_rrb(t_info **a, char name, t_elem **el)
{
	t_info	*last;

	if (!*a || !((*a)->next))
		return ;
	last = *a;
	while (last->next->next != NULL)
		last = last->next;
	ft_lstadd_front(a, last->next);
	last->next = NULL;
	if (name == 'a')
		write(1, "rra\n", 4);
	else if (name == 'b')
		write(1, "rrb\n", 4);
	(*el)->cnt++;
}

void	ra_rb(t_info **a, char name, t_elem **el)
{
	t_info	*tmp;

	if ((!*a) || !((*a)->next))
		return ;
	tmp = *a;
	(*a) = (*a)->next;
	ft_lstadd_back(a, tmp);
	if (name == 'a')
		write(1, "ra\n", 3);
	else if (name == 'b')
		write(1, "rb\n", 3);
	(*el)->cnt++;
}

void	rr(t_info **a, t_info **b, t_elem **el)
{
	ra_rb(a, 'a', el);
	ra_rb(b, 'b', el);
	write(1, "rr\n", 3);
	(*el)->cnt++;
}
