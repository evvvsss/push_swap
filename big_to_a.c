#include "push_swap.h"

void	big_to_a(t_info **a, t_info **b, t_elem **el, int *array)
{
	// int		f;
	int		i;
	int		argc;

	// f = 0;
	i = 0;
	int f1 = 0;
	argc = (*el)->argc;
	//(*el)->min_next_i = argc;
	while ((*a) && (i <= argc / 2) && (f1 == 0))
	{
		// f = 0;
		(*a)->flag = (*el)->flag;
		// if ((*a)->value != (*el)->min_next && (*a)->value != (*el)->min)
		// 	(*el)->min_next_i++;
		if ((*a)->value == (*el)->min_next)
			(*el)->min_next_i = 0;
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
			i++;
		}
		else
		{
			ra_rb(a, 'b', el);
			(*el)->min_next_i++;
		}
		print(*b, 'a');
		print(*a, 'b');
		printf("%d min_next \n", (*el)->min_next);
		// printf("%d max \n", (*el)->max);
		printf("%d argc \n", (*el)->argc);
		// printf("%d mid \n", (*el)->middle);
		printf("%d min \n", (*el)->min);
		printf("%d min i \n", (*el)->min_i);
		printf("%d min next i \n", (*el)->min_next_i);
	}
}

void	big_to_a_back(t_info **a, t_info **b, t_elem **el, int *array)
{
	int		i;
	int		argc;

	i = 0;
	int f1 = 0;
	argc = (*el)->argc;
	while ((*a) && (i <= argc / 2) && (f1 == 0))
	{
		(*a)->flag = (*el)->flag;
		// if ((*a)->value != (*el)->min_next)
		// 	(*el)->min_next_i--;
		if ((*a)->value == (*el)->min_next)
			(*el)->min_next_i = (*el)->argc;
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
			i++;
		}
		else
		{	
			rra_rrb(a, 'b', el);
			(*el)->min_next_i--;
		}
		printf("BACK\n");
		printf("%d min_next \n", (*el)->min_next);
		// printf("%d max \n", (*el)->max);
		// printf("%d mid \n", (*el)->middle);
		printf("%d min \n", (*el)->min);
		printf("%d min i \n", (*el)->min_i);
		printf("%d min next i \n", (*el)->min_next_i);
		print(*b, 'a');
		print(*a, 'b');
	}
}
