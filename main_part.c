/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_part.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bferny <bferny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 21:27:51 by bferny            #+#    #+#             */
/*   Updated: 2021/10/12 21:27:52 by bferny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	main_part(int **array, t_info **a, t_info **b, t_elem **el)
{
	sort_array(array, 0, (*el)->argc - 1);
	index_to_lists(*array, a);
	if ((*el)->argc == 2)
		sort_2(a, el);
	else if ((*el)->argc == 3)
		sort_3(a, el);
	else if ((*el)->argc == 4)
		sort_4(a, b, el);
	else if ((*el)->argc == 5)
		sort_5(a, b, el);
	else
	{
		sort_a(a, b, el);
		sort_b(a, b, el, 0);
	}
	ft_clear(a, el);
	ft_lstclear(b);
	b = NULL;
	free(*array);
	array = NULL;
}
