/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coscialp <coscialp@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 10:40:27 by akerdeka          #+#    #+#             */
/*   Updated: 2021/03/05 12:16:40 by coscialp         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void	push_a(t_push_stack *stack)
{
	if (stack->stack_b->_data)
	{
		stack->stack_a->push(stack->stack_a, stack->stack_b->_data->value);
		stack->stack_b->pop(stack->stack_b);
	}
}

void	push_b(t_push_stack *stack)
{
	if (stack->stack_a->_data)
	{
		stack->stack_b->push(stack->stack_b, stack->stack_a->_data->value);
		stack->stack_a->pop(stack->stack_a);
	}
}
