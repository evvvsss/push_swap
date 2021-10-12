/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bferny <bferny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 21:28:00 by bferny            #+#    #+#             */
/*   Updated: 2021/10/12 21:28:01 by bferny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"
#include <stdio.h>

int	gnl(t_info **a, t_info **b, t_elem **el)
{
	char	*buf;

	buf = malloc(sizeof(char) * 4);
	buf = NULL;
	while (get_next_line(0, &buf) > 0)
	{
		if (read_cmd(buf, a, b, el) == -1)
		{
			ft_clear(a, el);
			free(buf);
			return (0);
		}
		buf = NULL;
	}
	free(buf);
	return (1);
}

int	main(int argc, char **argv)
{
	t_info	*a;
	t_info	*b;
	t_elem	*el;
	int		i;

	i = 1;
	if (argc < 2)
		return (0);
	elem_init_0(&a, &b, &el, argc);
	while (argc > i)
	{
		if (check_args(argv[i], &a, &el) == 1)
		{	
			write(2, "KO\n", 3);
			ft_clear(&a, &el);
			return (0);
		}
		i++;
	}
	if (gnl(&a, &b, &el) == 0)
		return (0);
	check_stacks(a, b);
	ft_clear(&a, &el);
	ft_lstclear(&b);
	return (0);
}
