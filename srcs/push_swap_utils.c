/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akerdeka <akerdeka@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 09:24:52 by akerdeka          #+#    #+#             */
/*   Updated: 2021/03/09 09:44:35 by akerdeka         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_smallest_element(t_push_stack stack)
{
	int	smallest;
	t_node_stack	*tmp;

	smallest = INT_MAX;
	tmp = stack.stack_a->_data;
	while (tmp->_next)
	{
		if (tmp->value < smallest)
			smallest = tmp->value;
		tmp = tmp->_next;
	}
	return (smallest);
}