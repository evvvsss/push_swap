#include "push_swap.h"

int	check_string(char *argv, int space)
{
	int	j;

	j = 0;
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
	return (0);
}

int	str_with_spaces(char *argv, t_info **a, t_elem **el)
{
	char	**b;
	int		j;

	j = 0;
	b = NULL;
	b = ft_split(argv, ' ');
	while (b[j] != NULL)
	{
		if (check_repeats(*a, ft_atoi(b[j], el)) == 1 || (*el)->cnt == -5)
			return (1);
		ft_lstadd_back(a, ft_lstnew(ft_atoi(b[j], el)));
		((*el)->argc)++;
		j++;
	}
	free(b);
	return (0);
}

int	check_args(char *argv, t_info **a, t_elem **el)
{
	int		space;

	space = 0;
	if (check_string(argv, space) == 1)
		return (1);
	if (space != 0)
	{
		if (str_with_spaces(argv, a, el) == 1)
			return (1);
	}
	else
	{
		if (check_repeats(*a, ft_atoi(argv, el)) == 1 || (*el)->cnt == -5)
			return (1);
		ft_lstadd_back(a, ft_lstnew(ft_atoi(argv, el)));
		(*el)->argc++;
	}
	return (0);
}
