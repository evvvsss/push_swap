#include "push_swap.h"

void	elem_init_1(t_elem **el, int *array)
{
	(*el)->counter = 0;
	(*el)->min = array[0];
	(*el)->flag = 1;
	(*el)->max = array[(*el)->argc / 2];
	(*el)->middle = array[(*el)->argc / 2];
}

void	find_mid(t_elem **el, t_info *a, int *array)
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
		(*el)->middle = a->value;
		(*el)->min = a->value;
		return ;
	}
	else if (a->next->next == NULL)
	{
		if (a->value < a->next->value)
			(*el)->middle = a->value;
		else
			(*el)->middle = a->next->value;
		return ;
	}
	while ((*el)->min != array[i])
		i++;
	min = i;
	i = 0;
	while ((*el)->max != array[i])
		i++;
	max = i;
	(*el)->middle = array[(max - min) / 2 + min];
	// printf("%d fm_max \n", (*el)->max);
	// printf("%d fm_mid \n", (*el)->middle);
	// printf("%d fm_min ", (*el)->min);
	// printf("%d fm_min i \n", (*el)->min_i);
	// printf("%d fm_argc \n", (*el)->argc);
	//(*el)->flag++; // ГДЕТО ФЛАГ МЕНЯЕТСЯ ЧАСТО И ОНИ ДАЛЕКО
}

void	small_to_b(t_info **a, t_info **b, t_elem **el, int argc)
{
	int	i;

	i = 0;
	// printf("%d ToBmax \n", (*el)->max);
	//  printf("%d toBmid \n", (*el)->middle);
	//  printf("%d ToBmin \n", (*el)->min);
	(*el)->argc = 0;
	while ((*a) && i <= argc)
	{	
		// if ((*a)->value == (*el)->min)
		// 	(*el)->min_i = (*el)->argc + 1;
		if ((*a)->value < (*el)->middle)
		{
			// (*a)->index++;
			pa_pb(b, a, 'b', el);
			(*el)->argc++;
		}
		else
			ra_rb(a, 'a', el);
		i++;
	}
	// printf("%d min_INDEX \n", (*el)->min_i);
	// print(*a, 'a');
	// print(*b, 'b');
}

void	next_elem(int *array, t_elem **el, t_info **a)
{
	int	i;

	i = 0;
	while ((*el)->min != array[i])
		i++;
	(*el)->min = array[++i];
	(*a)->index = i;
	find_index((*el)->min, *a, el);
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
	find_index((*el)->min, *b, el);
	find_mid(el, *b, array);
	while (*b)
	{
		if (((*el)->argc / 2 ) < (*el)->min_i)
			big_to_a(b, a, el, array);
		 else
		 	big_to_a_back(b, a, el, array);
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
	(*el)->min_i = -1;
	(*el)->middle = 0;
}

int		check_repeats(t_info *a, int digit)
{
	while (a)
	{
		if (a->value == digit)
			return (1);
		a = a->next;
	}
	return (0);
}

void	find_index(int min, t_info *a, t_elem **el)
{
	int	i;
	int	flag;

	i = 0;
	flag = 0;
	while (a && i < (*el)->argc)
	{
		if (a->value == min)
		{	
			(*el)->min_i = (*el)->argc - i;
			flag++;
		}
		a = a->next;
		i++;
	}
	if (flag == 0)
		(*el)->min_i = -1;
}
