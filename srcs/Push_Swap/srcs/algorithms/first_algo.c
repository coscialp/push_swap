/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_algo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coscialp <coscialp@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 08:55:48 by akerdeka          #+#    #+#             */
/*   Updated: 2021/03/11 11:40:59 by coscialp         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "../../../Includes/push_swap.h"

int	first_algo(t_push_stack stack, int id)
{
	static int	smallest;
	static int	smallest_index;
	static int nb_insn = 0;
	static int begin = 0;

	nb_insn++;
	if (check_order_stack(stack, STACK_A) == 0)
	{
		stack.pa(&stack);
		stack.algo[id]->pushback(stack.algo[id], PA);
		return (nb_insn);
	}
	if (begin == 0)
	{
		smallest = find_smallest_element(stack, STACK_A);
		begin = 1;
	}
	smallest_index = find_smallest_element_index(stack, smallest);
	if (smallest_index == 0)
	{
		stack.pb(&stack);
		stack.algo[id]->pushback(stack.algo[id], PB);
		smallest = find_smallest_element(stack, STACK_A);
	}
	else if (stack.stack_a->_size == 3 && smallest_index == 1 && \
	stack.stack_a->_data->value < stack.stack_a->_data->_next->_next->value)
	{
		stack.sa(&stack);
		stack.algo[id]->pushback(stack.algo[id], SA);
	}
	else if (smallest_index <= ((int)stack.stack_a->_size / 2))
	{
		stack.ra(&stack);
		stack.algo[id]->pushback(stack.algo[id], RA);
	}
	else
	{
		stack.rra(&stack);
		stack.algo[id]->pushback(stack.algo[id], RRA);
	}
	return (nb_insn);
}