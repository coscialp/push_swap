/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coscialp <coscialp@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 10:47:20 by akerdeka          #+#    #+#             */
/*   Updated: 2021/03/05 12:00:23 by coscialp         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void	rotate_a(t_push_stack *stack)
{
	t_node_stack	*tmp;

	if (stack->stack_a->_size < 2)
		return ;
	tmp = stack->stack_a->_data;
	while (tmp->_next)
		tmp = tmp->_next;
	stack->stack_a->_data = stack->stack_a->_data->_next;
	stack->stack_a->_data->_prev->_prev = tmp;
	tmp->_next = stack->stack_a->_data->_prev;
	stack->stack_a->_data->_prev->_next = NULL;
	stack->stack_a->_data->_prev = NULL;
}

void	rotate_b(t_push_stack *stack)
{
	t_node_stack	*tmp;

	if (stack->stack_b->_size < 2)
		return ;
	tmp = stack->stack_b->_data;
	while (tmp->_next)
		tmp = tmp->_next;
	stack->stack_b->_data = stack->stack_b->_data->_next;
	stack->stack_b->_data->_prev->_prev = tmp;
	tmp->_next = stack->stack_b->_data->_prev;
	stack->stack_b->_data->_prev->_next = NULL;
	stack->stack_b->_data->_prev = NULL;
}

void	rotate_r(t_push_stack *stack)
{
	rotate_a(stack);
	rotate_b(stack);
}
