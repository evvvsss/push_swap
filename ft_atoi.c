#include "push_swap.h"

static size_t	check(const char *str)
{	
	size_t	i;

	i = 0;
	while (str[i] == ' ' || str[i] == '	' || str[i] == '\f' || str[i] == '\n'
		|| str[i] == '\r' || str[i] == '\t' || str[i] == '\v')
		i++;
	return (i);
}

static int	ft_sign(const char *str, size_t *i, int *sign)
{
	while (!(str[*i] >= 48 && str[*i] <= 57) && *sign == 0)
	{
		if (str[*i] == '-')
			*sign = -1;
		else if (str[*i] == '+')
			*sign = 1;
		else
			return (0);
		(*i)++;
	}
	return (1);
}

static int	ft_digit(const char *str, size_t *i, int *sign)
{
	size_t	k;
	size_t	c;

	k = 0;
	c = 0;
	while (str[*i] >= 48 && str[*i] <= 57 && str[*i] !='\0')
	{
		if (k++ > 17 && ((str[*i] - 48 > 7 && c == MAX) || c > MAX))
		{
			if (*sign == -1)
				return (-10);
			else
				return (-1);
		}
		c = c * 10 + str[*i] - 48;
		(*i)++;
	}
	return (c);
}

long long	ft_atoi(const char *str, t_elem	**el)
{
	size_t		i;
	int			f;
	int			sign;

	sign = 0;
	i = check(str);
	if (ft_sign(str, &i, &sign) == 0)
		return (0); // не тот символ
	f = ft_digit(str, &i, &sign);
	if (f < 0)
		(*el)->flag= -5;
	if (f == -1)
		return (-1); // границы инт
	else if (f == -10)
		return (0);
	else
	{
		if (sign == -1)
			return (-f);
		else
			return (f);
	}
}
