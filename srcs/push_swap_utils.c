/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coscialp <coscialp@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 09:24:52 by akerdeka          #+#    #+#             */
/*   Updated: 2021/03/13 16:11:24 by akerdeka         ###   ########lyon.fr   */
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
	size_t			sort_value;
	t_node_stack	*tmp;

	sort_value = 0;
	tmp = stack->stack_a->_data;
	while (tmp)
	{
		tmp->sort_value = sort_value;
		sort_value++;
		tmp = tmp->_next;
	}
}

void	change_sort_value(t_push_stack *real, t_push_stack copy)
{
	t_node_stack	*tmp;
	t_node_stack	*tmp_real;

	tmp = copy.stack_a->_data;
	tmp_real = real->stack_a->_data;
	while (tmp_real)
	{
		while (tmp)
		{
			if (tmp->value == tmp_real->value)
				tmp_real->sort_value = tmp->sort_value;
			tmp = tmp->_next;
		}
		tmp = copy.stack_a->_data;
		tmp_real = tmp_real->_next;
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
