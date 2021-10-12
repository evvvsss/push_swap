#include "push_swap.h"

int	exec_sa_sb(char	*str, t_info **a, t_info **b, t_elem **el)
{
	if (ft_strncmp(str, 'sa', 2) == 0)
		sa_sb(a, 'a', el);
	else
		sa_sb(b, 'b', el);
	return (1);
}

int	exec_ss(char	*str, t_info **a, t_info **b, t_elem **el)
{
	ss(a, b, el);
	return (1);
}

int	exec_pa_pb(char	*str, t_info **a, t_info **b, t_elem **el)
{
	if (ft_strncmp(str, 'pa', 2) == 0)
		pa_pb(a, b, 'a', el);
	else
		pa_pb(b, a, 'b', el);
	return (1);
}

int	exec_ra_rb(char	*str, t_info **a, t_info **b, t_elem **el)
{
	if (ft_strncmp(str, 'ra', 2) == 0)
		ra_rb(a, 'a', el);
	else
		ra_rb(b, 'b', el);
	return (1);
}

int	exec_rr(char	*str, t_info **a, t_info **b, t_elem **el)
{
	rr(a, b, el);
	return (1);
}
