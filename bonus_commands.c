#include "push_swap.h"

int	exec_rra_rrb(char	*str, t_info **a, t_info **b, t_elem **el)
{
	if (ft_strncmp(str, 'rra', 2) == 0)
		ra_rb(a, 'a', el);
	else
		ra_rb(b, 'b', el);
	return (1);
}

int	exec_rrr(char	*str, t_info **a, t_info **b, t_elem **el)
{
	rrr(a, b, el);
	return (1);
}

int	read_cmd(char	*str, t_info **a, t_info **b, t_elem **el)
{
	if (ft_strncmp(str, 'sa', 2) == 0 || ft_strncmp(str, 'sb', 2) == 0)
		return (exec_sa_sb(str, a, b, el));
	else if (ft_strncmp(str, 'ss', 2) == 0)
		return (exec_ss(str, a, b, el));
	else if (ft_strncmp(str, 'pa', 2) == 0 || ft_strncmp(str, 'pb', 2) == 0)
		return (exec_pa_pb(str, a, b, el));
	else if (ft_strncmp(str, 'ra', 2) == 0 || ft_strncmp(str, 'rb', 2) == 0)
		return (exec_ra_rb(str, a, b, el));
	else if (ft_strncmp(str, 'rr', 2) == 0)
		return (exec_rr(str, a, b, el));
	else if (ft_strncmp(str, 'rra', 3) == 0 || ft_strncmp(str, 'rrb', 3) == 0)
		return (exec_rra_rrb(str, a, b, el));
	else if (ft_strncmp(str, 'rrr', 3) == 0)
		return (exec_rrr(str, a, b, el));
	else
	{
		write(2, "Error\n", 6);
		return (-1);
	}
}

int check_stacks( t_info *a, t_info *b)
{
	if (b != NULL)
		return (0);
	while (a && a->next)
	{
		if (a->value > a->next->value)
			return (0);
		a = a->next;
	}
	return (1);
}
