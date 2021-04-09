/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coscialp <coscialp@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 14:46:14 by coscialp          #+#    #+#             */
/*   Updated: 2021/04/09 14:49:14 by coscialp         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free_stack(t_push_stack *stack)
{
	while (stack->stack_a->_size)
		stack->stack_a->pop(stack->stack_a);
	free(stack->stack_a);
	while (stack->stack_b->_size)
		stack->stack_b->pop(stack->stack_b);
	free(stack->stack_b);
	free(stack->algo[0]->ins);
	free(stack->algo[0]);
	free(stack->algo[1]->ins);
	free(stack->algo[1]);
}
