/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_algo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akerdeka <akerdeka@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 08:55:48 by akerdeka          #+#    #+#             */
/*   Updated: 2021/03/09 11:01:49 by akerdeka         ###   ########lyon.fr   */
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

int	first_algo(t_push_stack stack, t_instruc *insn)
{
	(void)insn;
	int		smallest;
	int		smallest_index;

	if (check_stack_a(stack) == 0)
	{
		insn[PA].func(&stack);
		dprintf(STDOUT, "pa\n");
		return (0);
	}
	smallest = find_smallest_element(stack);
	smallest_index = find_smallest_element_index(stack, smallest);
	if (smallest_index == 0)
	{
		insn[PB].func(&stack);
		ft_dprintf(STDOUT, "pb\n");
	}
	else if (smallest_index <= ((int)stack.stack_a->_size / 2))
	{
		insn[RA].func(&stack);
		dprintf(STDOUT, "ra\n");
	}
	else
	{
		insn[RRA].func(&stack);
		dprintf(STDOUT, "rra\n");
	}
	return (0);
}