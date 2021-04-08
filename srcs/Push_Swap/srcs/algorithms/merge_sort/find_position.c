#include "push_swap.h"

void	find_position(t_stack s, int value, int *first, int *second)
{
	t_node_stack	*tmp;
	int				*stack;
	size_t			i;

	i = -1;
	stack = ft_xmalloc(sizeof(int) * (s._size + 1));
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