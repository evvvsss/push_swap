/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_oper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bferny <bferny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 21:26:49 by bferny            #+#    #+#             */
/*   Updated: 2021/10/12 21:26:51 by bferny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	exec_sa_sb(char	*str, t_info **a, t_info **b, t_elem **el)
{
	if (ft_strncmp(str, "sa", 2) == 0)
		sa_sb(a, 'c', el);
	else
		sa_sb(b, 'c', el);
	return (1);
}

int	exec_ss(t_info **a, t_info **b, t_elem **el)
{
	sa_sb(a, 'c', el);
	sa_sb(b, 'c', el);
	return (1);
}

int	exec_pa_pb(char	*str, t_info **a, t_info **b, t_elem **el)
{
	if (ft_strncmp(str, "pa", 2) == 0)
		pa_pb(a, b, 'c', el);
	else
		pa_pb(b, a, 'c', el);
	return (1);
}

int	exec_ra_rb(char	*str, t_info **a, t_info **b, t_elem **el)
{
	if (ft_strncmp(str, "ra", 2) == 0)
		ra_rb(a, 'c', el);
	else
		ra_rb(b, 'c', el);
	return (1);
}

int	exec_rr(t_info **a, t_info **b, t_elem **el)
{
	ra_rb(a, 'c', el);
	ra_rb(b, 'c', el);
	return (1);
}
