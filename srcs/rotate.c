/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akerdeka <akerdeka@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 10:47:20 by akerdeka          #+#    #+#             */
/*   Updated: 2021/03/05 11:06:07 by akerdeka         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void	rotate_a(t_push_stack *stack)
{
	t_stack	*tmp;

	stack->stack_a->_data->_prev->_next = NULL;
	
}

void	rotate_b(t_push_stack *stack)
{}

void	rotate_r(t_push_stack *stack)
{}
