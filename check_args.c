/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bferny <bferny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 21:26:55 by bferny            #+#    #+#             */
/*   Updated: 2021/10/12 21:26:56 by bferny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

int	*add_array(t_info *a, t_elem *el)
{
	int	i;
	int	sort;
	int	*b;

	i = 0;
	sort = 0;
	b = malloc(el->argc * sizeof(int));
	if (!b)
		return (NULL);
	while (a)
	{
		b[i] = a->value;
		if (a->next != NULL && (a->value > a->next->value))
			sort++;
		a = a->next;
		i++;
	}
	if (sort != 0)
		return (b);
	else
	{
		ft_clear(&a, &el);
		return (NULL);
	}
}

void	ft_clear(t_info **a, t_elem **el)
{
	ft_lstclear(a);
	a = NULL;
	free(*el);
	(*el) = NULL;
}
