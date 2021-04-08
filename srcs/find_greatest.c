/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_greatest.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akerdeka <akerdeka@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 13:08:41 by akerdeka          #+#    #+#             */
/*   Updated: 2021/04/08 13:10:02 by akerdeka         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_greatest_element_a(t_push_stack stack)
{
	int				greatest;
	t_node_stack	*tmp;

	greatest = INT_MIN;
	tmp = stack.stack_a->_data;
	while (tmp)
	{
		if (tmp->value > greatest)
			greatest = tmp->value;
		tmp = tmp->_next;
	}
	return (greatest);
}

static int	find_greatest_element_b(t_push_stack stack)
{
	int				greatest;
	t_node_stack	*tmp;

	greatest = INT_MIN;
	tmp = stack.stack_b->_data;
	while (tmp)
	{
		if (tmp->value > greatest)
			greatest = tmp->value;
		tmp = tmp->_next;
	}
	return (greatest);
}

int	find_greatest_element(t_push_stack stack, int id_stack)
{
	if (id_stack == STACK_A)
		return (find_greatest_element_a(stack));
	else if (id_stack == STACK_B)
		return (find_greatest_element_b(stack));
	return (0);
}
