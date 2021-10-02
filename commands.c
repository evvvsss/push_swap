#include "push_swap.h"

void	elem_init_1(t_elem **el, int *array)
{
	(*el)->counter = 0;
	(*el)->min = array[0];
	(*el)->min_next = array[1];
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
	printf("%d argc \n", (*el)->argc);
	while ((*el)->min != array[i])
		i++;
	min = i;
	i = 0;
	while ((*el)->max != array[i])
		i++;
	max = i;
	(*el)->middle = array[(max - min) / 2 + min];
	printf("%d max \n", (*el)->max);
	printf("%d mid \n", (*el)->middle);
	printf("%d min ", (*el)->min);
	printf("%d min_next\n", (*el)->min_next);
	printf("%d min i \n", (*el)->min_i);
	printf("%d argc \n", (*el)->argc);
	printf("%d min next i \n", (*el)->min_next_i);
	//(*el)->flag++; // ГДЕТО ФЛАГ МЕНЯЕТСЯ ЧАСТО И ОНИ ДАЛЕКО
}

void	small_to_b(t_info **a, t_info **b, t_elem **el, int argc)
{
	int	i;

	i = 0;
	printf("%d ToBmax \n", (*el)->max);
	 printf("%d toBmid \n", (*el)->middle);
	 printf("%d ToBmin \n", (*el)->min);
	 print(*a, 'a');
	print(*b, 'b');
	(*el)->argc = 0;
	while ((*a) && i <= argc)
	{	
		if ((*a)->value == (*el)->min)
			(*el)->min_i = (*el)->argc + 1;
		if ((*a)->value == (*el)->min_next)
			(*el)->min_next_i = (*el)->argc + 1;
		if ((*a)->value <= (*el)->middle)
		{
			// (*a)->index++;
			pa_pb(b, a, 'b', el);
			(*el)->argc++;
		}
		else
			ra_rb(a, 'a', el);
		i++;
	}
	printf("%d min_INDEX \n", (*el)->min_i);
	print(*a, 'a');
	print(*b, 'b');
}

void	next_elem(int *array, t_elem **el, t_info **a)
{
	int	i;

	i = 0;
	while ((*el)->min != array[i])
		i++;
	find_min_next(array[i + 1], *a, el);
	if ((*el)->min_next_i != -1)
		(*el)->min = array[++i];
	find_min_next(array[i + 1], *a, el);
	if ((*el)->min_next_i != -1)
		(*el)->min_next = array[++i];
	else
		(*el)->min_next	 = -1;
	printf("%d min_next \n", (*el)->min_next);
	(*a)->index = i;
	if ((*el)->min_next_i == -1)
		(*el)->min_i = (*el)->min_next_i;
	find_min_next((*el)->min_next, *a, el);
	//(*el)->min_next_i--;
	printf("%d min_next_I \n", (*el)->min_next_i);
}

void	move_to_b(t_info **a, t_info **b, t_elem **el, int *array)
{
	int	i;

	i = 0;
	while (((*a)->flag == (*a)->next->flag) && ((*a)->next != NULL))
	{	
		print(*a, 'a');
		print(*b, 'b');
		pa_pb(b, a, 'b', el);
		(*el)->argc++;
		if ((*b)->value >= (*el)->max)
			(*el)->max = (*b)->value;
		if ((*b)->value <= (*el)->min)
		{	
			(*el)->min = (*b)->value;
			(*el)->min_i = (*el)->argc;
			printf("%d minIII i \n", (*el)->min_i);
		}
	}
	pa_pb(b, a, 'b', el);
	(*el)->argc++;
	if ((*b)->value >= (*el)->max)
		(*el)->max = (*b)->value;
	if ((*b)->value <= (*el)->min)
	{	
		(*el)->min = (*b)->value;
		(*el)->min_i = (*el)->argc;
	}
	find_mid(el, *b, array);
	while (*b)
	{
		(*el)->min_next_i = 0;
		if (((*el)->argc / 2 ) < (*el)->min_i)
			big_to_a(b, a, el, array);
		else
			big_to_a_back(b, a, el, array);
		(*el)->min_i = (*el)->min_next_i;
		find_mid(el, *b, array);
	}
}

void	elem_init_0(t_elem **el)
{
	(*el) = (t_elem *)malloc(sizeof(t_elem));
	(*el)->argc = 0;
	(*el)->counter = 0;
	(*el)->min = 0;
	(*el)->min_next = 0;
	(*el)->flag = 0;
	(*el)->max = 0;
	(*el)->min_i = -1;
	(*el)->min_next_i = -1;
	(*el)->middle = 0;
}

int		check_repeats(t_info *a, int digit)
{
	while (a)
	{
		if (a->value == digit)
		{
			write(1, "repeat ", 7);
			return (1);
		}
		a = a->next;
	}
	return (0);
}

void	find_min_next(int min_next, t_info *a, t_elem **el)
{
	int	i;
	int	flag;

	i = 0;
	flag = 0;
	while (a && i < (*el)->argc)
	{
		if (a->value == min_next)
		{	
			(*el)->min_next_i = (*el)->argc - i;
			flag++;
		}
		a = a->next;
		i++;
	}
	if (flag == 0)
		(*el)->min_next_i = -1;
	printf("%d MIN_NEXT \n", (*el)->min_next);
	printf("%d MIN_NEXT i \n", (*el)->min_next_i);
}