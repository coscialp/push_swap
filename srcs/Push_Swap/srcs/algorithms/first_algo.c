/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_algo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coscialp <coscialp@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 08:55:48 by akerdeka          #+#    #+#             */
/*   Updated: 2021/04/09 14:48:48 by coscialp         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "../../../Includes/push_swap.h"

static void	second_part(t_push_stack copy, t_push_stack *s, int id, int *small)
{
	small[Index] = find_smallest_element_index(copy, small[Value]);
	if (small[Index] == 0)
	{
		copy.pb(&copy);
		s->algo[id]->pushback(s->algo[id], Pb);
		small[Value] = find_smallest_element(copy, STACK_A);
	}
	else if (copy.stack_a->_size == 3 && small[Index] == 1 && \
	copy.stack_a->_data->value < copy.stack_a->_data->_next->_next->value)
	{
		copy.sa(&copy);
		s->algo[id]->pushback(s->algo[id], Sa);
	}
	else if (small[Index] <= ((int)copy.stack_a->_size / 2))
	{
		copy.ra(&copy);
		s->algo[id]->pushback(s->algo[id], Ra);
	}
	else
	{
		copy.rra(&copy);
		s->algo[id]->pushback(s->algo[id], Rra);
	}
}

int	first_algo(t_push_stack copy, t_push_stack *s, int id)
{
	int			smallest[2];
	static int	begin = 0;

	while (check_stack(copy, PUSH_SWAP))
	{
		if (check_order_stack(copy, STACK_A) == 0)
		{
			copy.pa(&copy);
			s->algo[id]->pushback(s->algo[id], Pa);
			continue ;
		}
		if (begin == 0)
		{
			smallest[Value] = find_smallest_element(copy, STACK_A);
			begin = 1;
		}
		second_part(copy, s, id, smallest);
	}
	change_by_pattern(s, id);
	ft_free_stack(&copy);
	return (s->algo[id]->size);
}
