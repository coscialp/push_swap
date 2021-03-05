/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akerdeka <akerdeka@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 10:40:27 by akerdeka          #+#    #+#             */
/*   Updated: 2021/03/05 10:47:04 by akerdeka         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void	push_a(t_push_stack *stack)
{
	t_stack	*tmp;

	tmp->push(stack->stack_a, stack->stack_b->_data->value);
	tmp->pop(stack->stack_b);
}

void	push_b(t_push_stack *stack)
{
	t_stack	*tmp;

	tmp->push(stack->stack_b, stack->stack_a->_data->value);
	tmp->pop(stack->stack_a);
}
