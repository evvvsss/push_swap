/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_2345.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bferny <bferny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 21:28:07 by bferny            #+#    #+#             */
/*   Updated: 2021/10/12 21:28:08 by bferny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_2(t_info **a, t_elem **el)
{
	if ((*a)->value > (*a)->next->value)
		sa_sb(a, 'a', el);
}

void	sort_3(t_info **a, t_elem **el)
{
	int	max;

	max = max_index(*a);
	if ((*a)->index == max)
	{	
		ra_rb(a, 'a', el);
		if ((*a)->index == max - 1)
			sa_sb(a, 'a', el);
	}
	else if ((*a)->index == max - 1)
	{	
		if ((*a)->next->index == max)
			rra_rrb(a, 'a', el);
		else
			sa_sb(a, 'a', el);
	}
	else if ((*a)->index == max - 2 && (*a)->next->index == max)
	{
		rra_rrb(a, 'a', el);
		sa_sb(a, 'a', el);
	}
}

void	sort_4(t_info **a, t_info **b, t_elem **el)
{
	int	max;

	max = max_index(*a) - 3;
	while ((*a)->index != max)
		ra_rb(a, 'a', el);
	pa_pb(b, a, 'b', el);
	max = max_index(*a);
	sort_3(a, el);
	pa_pb(a, b, 'a', el);
}

void	sort_5(t_info **a, t_info **b, t_elem **el)
{
	while (ft_lstsize(*a) > 3)
	{
		while (find_elem(0, *a) == 5 || find_elem(1, *a) == 5)
			rra_rrb(a, 'a', el);
		while ((*a)->index > 1)
			ra_rb(a, 'a', el);
		pa_pb(b, a, 'b', el);
	}
	if ((*b)->value < (*b)->next->value)
		sa_sb(b, 'b', el);
	sort_3(a, el);
	pa_pb(a, b, 'a', el);
	pa_pb(a, b, 'a', el);
}
