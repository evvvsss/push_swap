#include "push_swap.h"
#include "libft/libft.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	t_info	*a;
	t_info	*b;
	t_elem	*el;
	int		i;
	int		*array;

	i = 1;
	if (argc < 2)
		return (0);
	elem_init_0(&a, &b, &el, argc);
	while (argc > i)
	{
		if (check_args(argv[i], &a, &el) == 1)
		{	
			write(2, "Error\n", 6);
			ft_clear(&a, &el);
			return (0);
		}
		i++;
	}
	array = add_array(a, el);
	if (!array)
		return (0);
	main_part(&array, &a, &b, &el);
	return (0);
}
