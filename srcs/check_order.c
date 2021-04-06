/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_order.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akerdeka <akerdeka@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 10:55:53 by coscialp          #+#    #+#             */
/*   Updated: 2021/04/06 13:41:50 by akerdeka         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static bool	check_order_stack_a(t_push_stack s)
{
	t_node_stack	*a;

	a = s.stack_a->_data;
	if (s.stack_a->_size <= 1)
		return (0);
	while (a->_next)
	{
		if (a->value > a->_next->value)
			return (1);
		a = a->_next;
	}
	return (0);
}

static bool	check_order_stack_b(t_push_stack s)
{
	t_node_stack	*a;

	a = s.stack_b->_data;
	if (s.stack_b->_size <= 1)
		return (0);
	while (a->_next)
	{
		if (a->value < a->_next->value)
			return (1);
		a = a->_next;
	}
	return (0);
}

bool	check_order_stack(t_push_stack s, int id_stack)
{
	if (id_stack == STACK_A)
		return (check_order_stack_a(s));
	else if (id_stack == STACK_B)
		return (check_order_stack_b(s));
	return (1);
}
