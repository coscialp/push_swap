/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coscialp <coscialp@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 09:24:52 by akerdeka          #+#    #+#             */
/*   Updated: 2021/03/11 11:00:43 by coscialp         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_smallest_element_a(t_push_stack stack)
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

int	find_smallest_element_b(t_push_stack stack)
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