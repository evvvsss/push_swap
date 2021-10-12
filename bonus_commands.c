/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_commands.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bferny <bferny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 21:26:43 by bferny            #+#    #+#             */
/*   Updated: 2021/10/12 21:26:47 by bferny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	exec_rra_rrb(char	*str, t_info **a, t_info **b, t_elem **el)
{
	if (ft_strncmp(str, "rra", 3) == 0)
		rra_rrb(a, 'c', el);
	else
		rra_rrb(b, 'c', el);
	return (1);
}

int	exec_rrr(t_info **a, t_info **b, t_elem **el)
{
	rra_rrb(a, 'c', el);
	rra_rrb(b, 'c', el);
	return (1);
}

int	read_cmd(char	*str, t_info **a, t_info **b, t_elem **el)
{
	if (ft_strncmp(str, "sa\0", 3) == 0 || ft_strncmp(str, "sb\0", 3) == 0)
		return (exec_sa_sb(str, a, b, el));
	else if (ft_strncmp(str, "ss\0", 3) == 0)
		return (exec_ss(a, b, el));
	else if (ft_strncmp(str, "pa\0", 3) == 0 || ft_strncmp(str, "pb\0", 3) == 0)
		return (exec_pa_pb(str, a, b, el));
	else if (ft_strncmp(str, "ra\0", 3) == 0 || ft_strncmp(str, "rb\0", 3) == 0)
		return (exec_ra_rb(str, a, b, el));
	else if (ft_strncmp(str, "rra\0", 4) == 0 || ft_strncmp(str, "rrb\0", 4) == 0)
		return (exec_rra_rrb(str, a, b, el));
	else if (ft_strncmp(str, "rrr\0", 4) == 0)
		return (exec_rrr(a, b, el));
	else if (ft_strncmp(str, "rr\0", 3) == 0)
		return (exec_rr(a, b, el));
	else
	{
		write(2, "KO\n", 3);
		return (-1);
	}
}

void	check_stacks(t_info *a, t_info *b)
{
	int	flag;

	flag = 1;
	if (b != NULL)
		flag = 0;
	while (a && a->next)
	{
		if (a->value > a->next->value)
			flag = 0;
		a = a->next;
	}
	if (flag == 0)
		write(2, "1KO\n", 3);
	else
		write(2, "OK\n", 3);
}
