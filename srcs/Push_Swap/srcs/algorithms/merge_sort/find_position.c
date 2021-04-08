#include "push_swap.h"

static void	cpy_and_swap(t_stack s, int *stack, int value)
{
	size_t			i;
	t_node_stack	*tmp;

	i = -1;
	tmp = s._data;
	while (++i < s._size)
	{
		stack[i] = tmp->value;
		tmp = tmp->_next;
	}
	stack[i] = value;
	i = -1;
	while (++i < s._size)
	{
		if (stack[i] < stack[i + 1])
		{
			ft_intswap(&stack[i], &stack[i + 1]);
			i -= !!i;
			i -= !!i;
		}
	}
}

void	find_position(t_stack s, int value, int *first, int *second)
{
	int				*stack;
	size_t			i;

	stack = ft_xmalloc(sizeof(int) * (s._size + 1));
	cpy_and_swap(s, stack, value);
	i = -1;
	while (++i < s._size)
	{
		if (stack[i] == value)
		{
			*first = stack[i + 1];
			*second = stack[i - 1];
			free(stack);
			return ;
		}
	}
	free(stack);
}
