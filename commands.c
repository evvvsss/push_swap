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

void	next_elem(int *array, t_elem **el, t_info **a)
{
	int	i;

	i = 0;
	while ((*el)->min != array[i])
		i++;
	(*el)->min = array[++i];
	(*a)->index = i;
	//find_index((*el)->min, *a, el);
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

int	find_index(int val, t_info *a, t_elem *el)
{
	int	i;

	i = 1;
	while (a && i < el->argc)
	{
		if (a->value == val)
			return (i);
		a = a->next;
		i++;
	}
	return (0);
}

int	find_elem(int index, t_info *a)
{
	int	i;

	i = 1;
	while (a)
	{
		if (a->index == index)
			return (i);
		a = a->next;
		i++;
	}
	return (0);
}

void index_to_lists(int *array, t_info **a)
{
	int		i;
	t_info	*tmp;

	i = 0;
	tmp = *a;
	while (tmp)
	{
		while (tmp->value != array[i])
			i++;
		tmp->index = i;
		tmp = tmp->next;
		i = 0;
	}
}

int max_index(t_info *a)
{
	int	max;

	max = 0;
	if (a)
	{
		max = a->index;
		while (a)
		{
			if (max < a->index)
				max = a->index;
			a = a->next;
		}
	}
	return (max);
}
