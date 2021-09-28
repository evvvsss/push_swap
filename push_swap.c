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
		// printf("%d ", a->flag);
		// printf("%d ", a->index);
		a = a->next;
	}
	printf("\n");
}

int	*add_array( t_info *a, t_elem *el)
{
	int	i;
	int	*b;

	i = 0;
	b = malloc(el->argc * sizeof(int));
	while (a)
	{
		b[i] = a->value;
		a = a->next;
		i++;
	}
	return (b);
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
			ft_lstadd_back(a, ft_lstnew(ft_atoi(b[j])));
			((*el)->argc)++;
			j++;
		}
	}
	else
	{
		ft_lstadd_back(a, ft_lstnew(ft_atoi(argv)));
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
		if (check_args(argv[i], &a, &el) == 1) // проверить на повторения
		{	
			write(1, "error\n", 6);
			return (0);
		}
		i++;
	}
	array = add_array(a, el);
	sort(&array, 0, el->argc - 1);
	// i = 0;
	// while (i < el->argc)
	// 	printf("%d ", array[i++]);
	print(a, 'a');
	print(b, 'b');
	elem_init_1(&el, array);
	printf("%d Argc \n", el->argc);
	small_to_b(&a, &b, &el, el->argc);
	el->max = el->middle;
	elem_init_2(&el, b, array);
	while (b)
	{	
		big_to_a(&b, &a, &el, array);
		elem_init_2(&el, b, array);
	}
	big_to_a(&b, &a, &el, array);
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
	print(a, 'a');
	print(b, 'b');
	printf("ВСЕГО ОПЕРАЦИЙ: %d \n", el->counter);
	return (0);
}
