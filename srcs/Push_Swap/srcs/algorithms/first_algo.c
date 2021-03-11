/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_algo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akerdeka <akerdeka@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 08:55:48 by akerdeka          #+#    #+#             */
/*   Updated: 2021/03/11 11:21:36 by akerdeka         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "../../../Includes/push_swap.h"

int	first_algo(t_push_stack stack, t_instruc *insn, int id)
{
	static int	smallest;
	static int	smallest_index;
	static int nb_insn = 0;
	static int begin = 0;

	nb_insn++;
	if (check_order_stack(stack, STACK_A) == 0)
	{
		insn[PA].func(&stack);
		stack.algo[id]->pushback(stack.algo[id], "pa");
		return (nb_insn);
	}
	if (begin == 0)
	{
		smallest = find_smallest_element_a(stack);
		begin = 1;
	}
	smallest_index = find_smallest_element_index(stack, smallest);
	if (smallest_index == 0)
	{
		insn[PB].func(&stack);
		stack.algo[id]->pushback(stack.algo[id], "pb");
		smallest = find_smallest_element_a(stack);
	}
	else if (stack.stack_a->_size == 3 && smallest_index == 1 && \
	stack.stack_a->_data->value < stack.stack_a->_data->_next->_next->value)
	{
		insn[SA].func(&stack);
		stack.algo[id]->pushback(stack.algo[id], "sa");
	}
	else if (smallest_index <= ((int)stack.stack_a->_size / 2))
	{
		insn[RA].func(&stack);
		stack.algo[id]->pushback(stack.algo[id], "ra");
	}
	else
	{
		insn[RRA].func(&stack);
		stack.algo[id]->pushback(stack.algo[id], "rra");
	}
	return (nb_insn);
}