/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_push_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akerdeka <akerdeka@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 09:44:21 by akerdeka          #+#    #+#             */
/*   Updated: 2021/03/05 09:50:59 by akerdeka         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_push_stack	new_push_stack(void)
{
	t_push_stack	push_stack;

	push_stack.stack_a = NULL;
	push_stack.stack_b = NULL;
	push_stack.sa = swap_a;
	push_stack.sb = swap_b;
	push_stack.ss = swap_s;
	push_stack.pa = push_a;
	push_stack.pb = push_b;
	push_stack.ra = rotate_a;
	push_stack.rb = rotate_b;
	push_stack.rr = rotate_r;
	push_stack.rra = r_rotate_a;
	push_stack.rrb = r_rotate_b;
	push_stack.rrr = r_rotate_r;
	return (push_stack);
}
