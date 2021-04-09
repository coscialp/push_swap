/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_b_algo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akerdeka <akerdeka@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 15:19:22 by akerdeka          #+#    #+#             */
/*   Updated: 2021/04/09 10:37:55 by akerdeka         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	no_greatest(t_push_stack *cpy, t_push_stack *s, int id)
{
	int				elem[2];

	elem[Value] = find_greatest_element(*cpy, STACK_B);
	elem[Index] = find_smallest_element_index_b(*cpy, elem[Value]);
	while (elem[Index] != 0)
	{
		if (elem[Index] <= (int)cpy->stack_b->_size / 2)
		{
			cpy->rb(cpy);
			s->algo[id]->pushback(s->algo[id], Rb);
		}
		else
		{
			cpy->rrb(cpy);
			s->algo[id]->pushback(s->algo[id], Rrb);
		}
		elem[Index] = find_smallest_element_index_b(*cpy, elem[Value]);
	}
}

void	insert_in_b(t_push_stack *cp, t_push_stack *s, int val, int id)
{
	int	before[2];
	int	after[2];

	if (cp->stack_b->_size >= 2)
	{
		find_position(*(cp->stack_b), val, \
		&before[Value], &after[Value]);
		before[Index] = find_smallest_element_index_b(*cp, before[Value]);
		after[Index] = find_smallest_element_index_b(*cp, after[Value]);
		while ((cp->stack_b->_data->value > val || \
		cp->stack_b->last(cp->stack_b)->value < val))
		{
			if (before[Index] <= ((int)cp->stack_b->_size) - after[Index])
			{
				cp->rb(cp);
				s->algo[id]->pushback(s->algo[id], Rb);
			}
			else
			{
				cp->rrb(cp);
				s->algo[id]->pushback(s->algo[id], Rrb);
			}
		}
	}
}

void	ins_sort_b(t_push_stack *cp, t_push_stack *s, int val, int id)
{
	int	before[2];
	int	after[2];

	find_position(*(cp->stack_b), val, \
	&before[Value], &after[Value]);
	before[Index] = find_smallest_element_index_b(*cp, before[Value]);
	after[Index] = find_smallest_element_index_b(*cp, after[Value]);
	while ((cp->stack_b->_data->value > val || \
	cp->stack_b->last(cp->stack_b)->value < val))
	{
		if (before[Index] <= ((int)cp->stack_b->_size) - after[Index])
		{
			cp->rb(cp);
			s->algo[id]->pushback(s->algo[id], Rb);
		}
		else
		{
			cp->rrb(cp);
			s->algo[id]->pushback(s->algo[id], Rrb);
		}
	}
	cp->pb(cp);
	s->algo[id]->pushback(s->algo[id], Pb);
}
