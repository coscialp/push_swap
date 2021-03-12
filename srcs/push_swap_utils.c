/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akerdeka <akerdeka@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 09:24:52 by akerdeka          #+#    #+#             */
/*   Updated: 2021/03/12 14:17:48 by akerdeka         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_push_stack	push_stack_copy(t_push_stack s)
{
	t_push_stack	copy;

	copy = new_push_stack();
	copy.stack_a = stack_copy(s.stack_a);
	copy.stack_b = new_stack();
	return (copy);
}

void	add_sort_value(t_push_stack *stack)
{
	size_t	sort_value;

	sort_value = 0;
	while (stack->stack_a->_data)
	{
		if (!stack->stack_a->_data)
			break ;
		stack->stack_a->_data->sort_value = sort_value;
		sort_value++;
		stack->stack_a->_data = stack->stack_a->_data->_next;
	}
}

void	change_sort_value(t_push_stack *real, t_push_stack copy)
{
	t_node_stack	*tmp;

	tmp = copy.stack_a->_data;
	while (real->stack_a->_data)
	{
		if (!real->stack_a->_data)
			break ;
		while (copy.stack_a->_data)
		{
			if (copy.stack_a->_data->value == real->stack_a->_data->value)
				real->stack_a->_data->sort_value = copy.stack_a->_data->sort_value;
			copy.stack_a->_data = copy.stack_a->_data->_next;
		}
		copy.stack_a->_data = tmp;
		real->stack_a->_data = real->stack_a->_data->_next;
	}
}

t_push_stack	bubble_sort_stack(t_push_stack s)
{
	t_node_stack	*tmp;

	tmp = s.stack_a->_data;
	while (tmp)
	{
		if (!tmp->_next)
			break ;
		dprintf(2, "val= %d\tnext_val=%d\n", tmp->value, tmp->_next->value);
		if (tmp->value > tmp->_next->value)
		{
			ft_intswap(&tmp->value, &tmp->_next->value);
			tmp = s.stack_a->_data;
			continue ;
		}
		tmp = tmp->_next;
	}
	return (s);
}

int	ft_log(size_t value)
{
	size_t	e;
	int		ret;

	e = 1;
	ret = 0;
	while (value > e)
	{
		e *= 2;
		ret++;
	}
	return (ret);
}

static int	find_smallest_element_a(t_push_stack stack)
{
	int				smallest;
	t_node_stack	*tmp;

	smallest = INT_MAX;
	tmp = stack.stack_a->_data;
	while (tmp)
	{
		if (tmp->value < smallest)
			smallest = tmp->value;
		tmp = tmp->_next;
	}
	return (smallest);
}

static int	find_smallest_element_b(t_push_stack stack)
{
	int				smallest;
	t_node_stack	*tmp;

	smallest = INT_MAX;
	tmp = stack.stack_b->_data;
	while (tmp)
	{
		if (tmp->value < smallest)
			smallest = tmp->value;
		tmp = tmp->_next;
	}
	return (smallest);
}

int	find_smallest_element(t_push_stack stack, int id_stack)
{
	if (id_stack == STACK_A)
		return (find_smallest_element_a(stack));
	else if (id_stack == STACK_B)
		return (find_smallest_element_b(stack));
	return (0);
}

int	find_smallest_element_index(t_push_stack stack, int smallest)
{
	t_node_stack	*tmp;
	int				i;

	tmp = stack.stack_a->_data;
	i = 0;
	while (tmp)
	{
		if (tmp->value == smallest)
			break ;
		tmp = tmp->_next;
		i++;
	}
	return (i);
}
