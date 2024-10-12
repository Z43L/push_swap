#include "pushswap.h"

// init_stack.c
int	init_stack(pushswap *ps, int argc, char **argv)
{
	int		i;
	long	value;
	t_node	*new_node;

	ps->stacka = NULL;
	ps->stackb = NULL;
	ps->size_a = 0;
	ps->size_b = 0;
	i = argc - 1;
	while (i >= 1)
	{
		if (!is_number(argv[i]))
		{
			ft_putstr_fd("Error\n", 2);
			return (0);
		}
		value = ft_atol(argv[i]);
		if (value < INT_MIN || value > INT_MAX)
		{
			ft_putstr_fd("Error\n", 2);
			return (0);
		}
		new_node = create_node((int)value);
		if (!new_node)
			return (0);
		new_node->next = ps->stacka;
		ps->stacka = new_node;
		ps->size_a++;
		i--;
	}
	if (has_duplicates(argc, argv))
	{
		ft_putstr_fd("Error\n", 2);
		return (0);
	}
	return (1);
}

// free_stack.c
void	free_stack(t_node *stack)
{
	t_node	*tmp;

	while (stack)
	{
		tmp = stack;
		stack = stack->next;
		free(tmp);
	}
}

// is_sorted.c
int	is_sorted(t_node *stack)
{
	while (stack && stack->next)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	pushswap	ps;

	if (argc < 2)
		return (0);
	if (!init_stack(&ps, argc, argv))
		return (1);
	if (is_sorted(ps.stacka))
	{
		free_stack(ps.stacka);
		return (0);
	}
	push_swap(&ps);
	free_stack(ps.stacka);
	free_stack(ps.stackb);
	return (0);
}
