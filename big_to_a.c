#include "push_swap.h"

void	big_to_a(t_info **a, t_info **b, t_elem **el, int *array)
{
	int		argc;

	int f1 = 0;
	argc = (*el)->argc;
	while ((*a) && (f1 == 0))
	{
		(*a)->flag = (*el)->flag;
		if ((*a)->value == (*el)->min)
		{
			next_elem(array, el, a);
			pa_pb(b, a, 'a', el);
			ra_rb(b, 'a', el);
			(*el)->argc--;
			f1++;
		}
		else if ((*a)->value > (*el)->middle)
		{
			pa_pb(b, a, 'a', el);
			(*el)->argc--;
		}
		else
			ra_rb(a, 'b', el);
		// print(*b, 'a');
		// print(*a, 'b');
		// // printf("%d max \n", (*el)->max);
		// printf("%d argc \n", (*el)->argc);
		// printf("%d mid \n", (*el)->middle);
		// printf("%d min \n", (*el)->min);
		// printf("%d min i \n", (*el)->min_i);
	}
}

void	big_to_a_back(t_info **a, t_info **b, t_elem **el, int *array)
{
	int		argc;

	int f1 = 0;
	argc = (*el)->argc;
	while ((*a) && (f1 == 0))
	{
		(*a)->flag = (*el)->flag;
		if ((*a)->value == (*el)->min)
		{
			next_elem(array, el, a);
			pa_pb(b, a, 'a', el);
			ra_rb(b, 'a', el);
			(*el)->argc--;
			f1++;
		}
		else if ((*a)->value > (*el)->middle)
		{
			pa_pb(b, a, 'a', el);
			(*el)->argc--;
		}
		else
			rra_rrb(a, 'b', el);
		// printf("BACK\n");
		// // printf("%d max \n", (*el)->max);
		// printf("%d mid \n", (*el)->middle);
		// printf("%d min \n", (*el)->min);
		// printf("%d min i \n", (*el)->min_i);
		// print(*b, 'a');
		// print(*a, 'b');
	}
}
