#include "push_swap.h"

void	elem_init_1(t_elem **el, int *array)
{
	(*el)->counter = 0;
	(*el)->min = array[0];
	(*el)->flag = 1;
	(*el)->max = array[(*el)->argc / 2];
	(*el)->middle = array[(*el)->argc / 2];
	// printf("%d firstmax \n", (*el)->max);
	// printf("%d firstmid \n", (*el)->middle);
	// printf("%d firstmin \n", (*el)->min);
}

void	elem_init_2(t_elem **el, t_info *a, int *array)
{
	int	i;
	int	min;
	int	max;

	i = 0;
	min = 0;
	max = 0;
	if (!a)
		return ;
	else if (a->next == NULL)
	{
		(*el)->middle = (*el)->max;
		return ;
	}
	printf("%d argc \n", (*el)->argc);
	while ((*el)->min != array[i])
		i++;
	min = i;
	i = 0;
	while ((*el)->max != array[i])
		i++;
	max = i;
	(*el)->middle = array[(max - min) / 2 + min];
	// printf("%d max \n", (*el)->max);
	// printf("%d mid \n", (*el)->middle);
	// printf("%d min \n", (*el)->min);
	(*el)->flag++;
}

void	small_to_b(t_info **a, t_info **b, t_elem **el, int argc)
{
	int	i;

	i = 0;
	(*el)->argc = 0;
	while ((*a) && i <= argc)
	{	
		if ((*a)->value <= (*el)->middle)
		{	
			pa_pb(b, a, 'b', el);
			(*el)->argc++;
		}
		else
			ra_rb(a, 'a', el);
		i++;
	}
}

void	next_elem(int *array, t_elem **el, t_info **a)
{
	int	i;

	i = 0;
	while ((*el)->min != array[i])
		i++;
	(*a)->index = i;
	(*el)->min = array[++i];
}

void	big_to_a(t_info **a, t_info **b, t_elem  **el, int *array)
{
	int		i;
	int		argc;

	i = 0;
	argc = (*el)->argc;
	// printf("%d flag \n", (*el)->flag);
	// printf("%d max \n", (*el)->max);
	// printf("%d mid \n", (*el)->middle);
	// printf("%d min \n", (*el)->min);
	while ((*a) && i <= argc)
	{
		(*a)->flag = (*el)->flag;
		if ((*a)->value == (*el)->min)
		{
			next_elem(array, el, a);
			pa_pb(b, a, 'a', el);
			ra_rb(b, 'a', el);
			(*el)->argc--;
		}
		else if ((*a)->value > (*el)->middle)
		{
			pa_pb(b, a, 'a', el);
			(*el)->argc--;
		}
		else
			ra_rb(a, 'b', el);
		i++;
		printf("%d argc \n", (*el)->argc);
		// print(*b, 'a');
		// print(*a, 'b');
	}
}

void	move_to_b(t_info **a, t_info **b, t_elem **el, int *array)
{
	int	i;

	i = 0;
	while (((*a)->flag == (*a)->next->flag) && ((*a)->next != NULL))
	{
		pa_pb(b, a, 'b', el);
		(*el)->argc++;
		if ((*b)->value >= (*el)->max)
			(*el)->max = (*b)->value;
		if ((*b)->value <= (*el)->min)
			(*el)->min = (*b)->value;
	}
	pa_pb(b, a, 'b', el);
	(*el)->argc++;
	if ((*b)->value >= (*el)->max)
		(*el)->max = (*b)->value;
	if ((*b)->value <= (*el)->min)
		(*el)->min = (*b)->value;
	elem_init_2(el, *b, array);
	while (*b)
	{
		big_to_a(b, a, el, array);
		elem_init_2(el, *b, array);
	}
}

void	elem_init_0(t_elem **el)
{
	(*el) = (t_elem *)malloc(sizeof(t_elem));
	(*el)->argc = 0;
	(*el)->counter = 0;
	(*el)->min = 0;
	(*el)->flag = 0;
	(*el)->max = 0;
	(*el)->middle = 0;
}
