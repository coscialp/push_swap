/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coscialp <coscialp@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 09:41:35 by akerdeka          #+#    #+#             */
/*   Updated: 2021/03/05 11:50:35 by coscialp         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void	swap_a(t_push_stack *stack)
{
	int	tmp;

	if (stack->stack_a && stack->stack_a->_data->_next)
	{
		tmp = stack->stack_a->_data->value;
		stack->stack_a->_data->value = stack->stack_a->_data->_next->value;
		stack->stack_a->_data->value = tmp;
	}
}

void	swap_b(t_push_stack *stack)
{
	int	tmp;

	if (stack->stack_b && stack->stack_b->_data->_next)
	{
		tmp = stack->stack_b->_data->value;
		stack->stack_b->_data->value = stack->stack_b->_data->_next->value;
		stack->stack_b->_data->value = tmp;
	}
}

void	swap_s(t_push_stack *stack)
{
	swap_a(stack);
	swap_b(stack);
}
