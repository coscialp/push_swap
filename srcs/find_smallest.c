/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_smallest.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akerdeka <akerdeka@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 13:54:31 by coscialp          #+#    #+#             */
/*   Updated: 2021/04/08 13:09:11 by akerdeka         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int	find_smallest_element_index_b(t_push_stack stack, int smallest)
{
	t_node_stack	*tmp;
	int				i;

	tmp = stack.stack_b->_data;
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
