#include "push_swap.h"

void	sort_a(t_info **a, t_info **b, t_elem **el)
{
	int	i;

	i = 0;
	while (*a)
	{
		if (i > 1 && (*a)->index <= i)
		{
			pa_pb(b, a, 'b', el);
			ra_rb(b, 'b', el);
			i++;
		}
		else if ((*a)->index <= i + 15)
		{
			pa_pb(b, a, 'b', el);
			i++;
		}
		else if ((*a)->index >= i && ft_lstsize(*a) > 1)
		{
			ra_rb(a, 'a', el);
		}
	}
}

void	sort_b(t_info **a, t_info **b, t_elem **el, int max)
{
	while (*b)
	{
		max = max_index(*b);
		if ((*b)->index != max && (find_elem(max_index(*b), *b) <= (ft_lstsize(*b) / 2)))
		{
			while ((*b)->index != max)
				ra_rb(b, 'b', el);
			pa_pb(a, b, 'a', el);
			(*el)->argc--;
		}
		else if ((*b)->index != max && (find_elem(max_index(*b), *b) > (ft_lstsize(*b) / 2)))
		{
			while ((*b)->index != max)
				rra_rrb(b, 'b', el);
			pa_pb(a, b, 'a', el);
			(*el)->argc--;
		}
		else if ((*b)->index == max)
		{	
			pa_pb(a, b, 'a', el);
			(*el)->argc--;
		}
	}
}
