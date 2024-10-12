#include "pushswap.h"

// is_number.c
int	is_number(const char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

// ft_atol.c
long	ft_atol(const char *str)
{
	int		i;
	long	sign;
	long	result;

	i = 0;
	sign = 1;
	result = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i++] - '0');
	}
	return (result * sign);
}

// has_duplicates.c
int	has_duplicates(int argc, char **argv)
{
	int		i;
	int		j;
	long	val_i;
	long	val_j;

	i = 1;
	while (i < argc)
	{
		val_i = ft_atol(argv[i]);
		j = i + 1;
		while (j < argc)
		{
			val_j = ft_atol(argv[j]);
			if (val_i == val_j)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

// create_node.c
t_node	*create_node(int value)
{
	t_node	*new_node;

	new_node = malloc(sizeof(t_node));
	if (!new_node)
		exit(EXIT_FAILURE);
	new_node->value = value;
	new_node->index = 0;
	new_node->next = NULL;
	return (new_node);
}
