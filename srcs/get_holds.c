#include "push_swap.h"

int	get_hold_first(t_push_stack s, size_t range, size_t chunk)
{
	t_node_stack	*tmp;

	tmp = s.stack_a->_data;
	while (tmp)
	{
		if (tmp->sort_value < (range * chunk))
			return (tmp->value);
		tmp = tmp->_next;
	}
	return (-1);
}

int	get_hold_last(t_push_stack s, size_t range, size_t chunk)
{
	t_node_stack	*tmp;

	if (!s.stack_a)
		return (0);
	tmp = s.stack_a->last(s.stack_a);
	while (tmp)
	{
		if (tmp->sort_value < (range * chunk))
			return (tmp->value);
		tmp = tmp->_prev;
	}
	return (0);
}
