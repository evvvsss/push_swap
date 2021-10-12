/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_array.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bferny <bferny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 21:28:09 by bferny            #+#    #+#             */
/*   Updated: 2021/10/12 21:28:13 by bferny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"
#include <stdio.h>

void	sort_array(int **array, int start, int end)
{
	int	a;
	int	b;
	int	mid;
	int	c;

	a = start;
	b = end;
	mid = (*array)[(end + start) / 2];
	while (a <= b)
	{
		while ((*array)[a] < mid && a < end)
			a++;
		while ((*array)[b] > mid && b > start)
			b--;
		if (a <= b && a <= end && b >= start)
		{
			c = (*array)[a];
			(*array)[a++] = (*array)[b];
			(*array)[b--] = c;
		}
	}
	if (b > start)
		sort_array(array, start, b);
	if (a < end)
		sort_array(array, a, end);
}
