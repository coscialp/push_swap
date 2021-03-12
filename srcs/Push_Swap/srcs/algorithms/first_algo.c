/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_algo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coscialp <coscialp@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 08:55:48 by akerdeka          #+#    #+#             */
/*   Updated: 2021/03/12 15:08:04 by coscialp         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "../../../Includes/push_swap.h"

int	first_algo(t_push_stack copy, t_push_stack *s, int id)
{
	int	smallest;
	int	smallest_index;
	int begin;

	begin = 0;
	while (check_stack(copy, PUSH_SWAP))
	{
		if (check_order_stack(copy, STACK_A) == 0)
		{
			copy.pa(&copy);
			s->algo[id]->pushback(s->algo[id], PA);
			continue ;
		}
		if (begin == 0)
		{
			smallest = find_smallest_element(copy, STACK_A);
			begin = 1;
		}
		smallest_index = find_smallest_element_index(copy, smallest);
		if (smallest_index == 0)
		{
			copy.pb(&copy);
			s->algo[id]->pushback(s->algo[id], PB);
			smallest = find_smallest_element(copy, STACK_A);
		}
		else if (copy.stack_a->_size == 3 && smallest_index == 1 && \
		copy.stack_a->_data->value < copy.stack_a->_data->_next->_next->value)
		{
			copy.sa(&copy);
			s->algo[id]->pushback(s->algo[id], SA);
		}
		else if (smallest_index <= ((int)copy.stack_a->_size / 2))
		{
			copy.ra(&copy);
			s->algo[id]->pushback(s->algo[id], RA);
		}
		else
		{
			copy.rra(&copy);
			s->algo[id]->pushback(s->algo[id], RRA);
		}
	}
	// print_instruction(s->algo[id]);
	change_by_pattern(s, id);
	return (s->algo[id]->size);
}