/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_algo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coscialp <coscialp@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 08:55:48 by akerdeka          #+#    #+#             */
/*   Updated: 2021/03/10 10:35:35 by coscialp         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "../../../Includes/push_swap.h"

static bool	check_stack_a(t_push_stack s)
{
	t_node_stack	*a;

	a = s.stack_a->_data;
	while (a->_next)
	{
		if (a->value > a->_next->value)
			return (1);
		a = a->_next;
	}
	return (0);
}

int	first_algo(t_push_stack stack, t_instruc *insn, int id)
{
	static int	smallest;
	static int	smallest_index;
	static int nb_insn = 0;
	static int begin = 0;

	nb_insn++;
	if (check_stack_a(stack) == 0)
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