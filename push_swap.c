#include "push_swap.h"
#include "libft/libft.h"
#include <stdio.h>

void	print(t_info *a, char n)
{
	if (n == 'a')
		printf("\n%s", "Стек А ");
	if (n == 'b')
		printf("\n%s", "Стек B ");
	if (!a)
	{
		printf("%s\n", "is empty :(");
		return ;
	}
	while (a)
	{
		printf(" %d ", a->value);
		printf("%d ", a->flag);
		printf("%d ", a->index);
		a = a->next;
	}
	printf("\n");
}

int	*add_array( t_info *a, t_elem *el)
{
	int	i;
	int	sort;
	int	*b;

	i = 0;
	sort = 0;
	b = malloc(el->argc * sizeof(int));
	if (!b)
		return (NULL);
	while (a)
	{
		b[i] = a->value;
		if (a->next != NULL && (a->value > a->next->value))
			sort++;
		a = a->next;
		i++;
	}
	if (sort != 0)
		return (b);
	else
		return (NULL);
}

int	check_args(char *argv, t_info **a, t_elem **el)
{
	int		j;
	int		space;
	char	**b;

	j = 0;
	space = 0;
	b = NULL;
	while (argv[j] != '\0')
	{
		if (!(argv[j] >= '0' && argv[j] <= '9'))
		{
			if (argv[j] == ' ')
				space++;
			else if ((argv[j] == '+' || argv[j] == '-'))
			{
				if (!(argv[j + 1] >= '0' && argv[j + 1] <= '9'))
					return (1);
			}
			else
				return (1);
		}
		j++;
	}
	j = 0;
	if (space != 0)
	{
		b = ft_split(argv, ' ');
		while (b[j] != NULL)
		{
			if ((check_repeats(*a, ft_atoi(b[j], el)) == 1) || (*el)->flag == -5)
				return (1);
			ft_lstadd_back(a, ft_lstnew(ft_atoi(b[j], el)));
			((*el)->argc)++;
			j++;
		}
	}
	else
	{
		if ((check_repeats(*a, ft_atoi(argv, el)) == 1 ) || (*el)->flag == -5)
			return (1);
		ft_lstadd_back(a, ft_lstnew(ft_atoi(argv, el)));
		(*el)->argc++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_info	*a;
	t_info	*b;
	t_elem	*el;
	int		i;
	int		*array;

	i = 1;
	a = NULL;
	b = NULL;
	elem_init_0(&el);
	while (argc > i)
	{
		if (check_args(argv[i], &a, &el) == 1)
		{	
			write(1, "error\n", 6);
			return (0);
		}
		i++;
	}
	array = add_array(a, el);
	if (!array)
	{
		printf("Массивчик отсортирован\nВСЕГО ОПЕРАЦИЙ: %d \n", el->counter);
		return (0);
	}
	sort(&array, 0, el->argc - 1);
	print(a, 'a');
	print(b, 'b');
	elem_init_1(&el, array);
	printf("%d Argc \n", el->argc);
	small_to_b(&a, &b, &el, el->argc);
	el->max = el->middle;
	//el->flag++;
	find_mid(&el, b, array);
	printf("%d min_next in \n", el->min_next_i);
	while (b)
	{
		if ((el->argc / 2 ) < el->min_i)
			big_to_a(&b, &a, &el, array);
		else
			big_to_a_back(&b, &a, &el, array);
		//el->min_i = el->min_next_i;
		find_mid(&el, b, array);
	}
	el->flag++;
	el->max = a->value;
	el->min = a->value;
	el->argc = 0;
	while (a->index < 0)
	{
		move_to_b(&a, &b, &el, array);
		printf("%d Argc \n", el->argc);
		print(a, 'a');
		print(b, 'b');
	}
	printf("%d min_next \n", el->min_next);
	printf("%d max \n", el->max);
	printf("%d mid \n", el->middle);
	printf("%d min \n", el->min);
	printf("%d min i \n", el->min_i);
	printf("%d min next i \n",el->min_next_i);
	print(a, 'a');
	print(b, 'b');
	printf("ВСЕГО ОПЕРАЦИЙ: %d \n", el->counter);
	return (0);
}
