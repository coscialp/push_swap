/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coscialp <coscialp@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 08:51:54 by akerdeka          #+#    #+#             */
/*   Updated: 2021/04/09 14:48:37 by coscialp         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

static void	sort_stack_b(t_push_stack *cpy, t_push_stack *s, int id)
{
	if (cpy->stack_a->_data && \
	find_greatest_element(*cpy, STACK_B) < cpy->stack_a->_data->value)
	{
		no_greatest(cpy, s, id);
		cpy->pb(cpy);
		s->algo[id]->pushback(s->algo[id], Pb);
	}
	else if (cpy->stack_a->_data && \
	find_smallest_element(*cpy, STACK_B) > cpy->stack_a->_data->value)
	{
		no_greatest(cpy, s, id);
		cpy->pb(cpy);
		s->algo[id]->pushback(s->algo[id], Pb);
	}
	else if (cpy->stack_a->_data && cpy->stack_b->_size >= 2)
		ins_sort_b(cpy, s, cpy->stack_a->_data->value, id);
	if (check_order_stack(*cpy, STACK_A) == 0)
		no_greatest(cpy, s, id);
}

static void	push_a_at_end(t_push_stack *cpy, t_push_stack *s, int id)
{
	while (check_order_stack(*cpy, STACK_A) == 0)
	{
		cpy->pa(cpy);
		s->algo[id]->pushback(s->algo[id], Pa);
		if (cpy->stack_b->_size == 0)
			return ;
	}
}

static void	ra_or_rra(t_push_stack *cp, t_push_stack *s, int id, int hold[2][2])
{
	if (hold[first][Index] <= ((int)cp->stack_a->_size) - hold[last][Index])
	{
		cp->ra(cp);
		s->algo[id]->pushback(s->algo[id], Ra);
		if (find_greatest_element(*cp, STACK_B) < hold[first][Value])
			no_greatest(cp, s, id);
		else if (find_smallest_element(*cp, STACK_B) > hold[first][Value])
			no_greatest(cp, s, id);
		else
			insert_in_b(cp, s, hold[first][Value], id);
	}
	else
	{
		cp->rra(cp);
		s->algo[id]->pushback(s->algo[id], Rra);
		if (find_greatest_element(*cp, STACK_B) < hold[last][Value])
			no_greatest(cp, s, id);
		else if (find_smallest_element(*cp, STACK_B) > hold[last][Value])
			no_greatest(cp, s, id);
		else
			insert_in_b(cp, s, hold[last][Value], id);
	}
}

static void	merge_algo(t_push_stack *cpy, t_push_stack *s, size_t range, int id)
{
	static size_t	chunk = 1;
	static size_t	nb_pb = 0;
	int				hold[2][2];

	hold[first][Value] = get_hold_first(*cpy, range, chunk);
	hold[last][Value] = get_hold_last(*cpy, range, chunk);
	hold[first][Index] = find_smallest_element_index(*cpy, hold[first][Value]);
	hold[last][Index] = find_smallest_element_index(*cpy, hold[last][Value]);
	if (hold[first][Index] == 0 || hold[last][Index] == 0)
	{
		if (++nb_pb >= range && ft_memset(&nb_pb, 0, sizeof(int)))
		{
			chunk++;
			if (cpy->stack_a->_size == 0)
			{
				push_a_at_end(cpy, s, id);
				return ;
			}
		}
		sort_stack_b(cpy, s, id);
	}
	else
		ra_or_rra(cpy, s, id, hold);
}

int	merge_sort(t_push_stack copy, t_push_stack *stack, int id)
{
	int				nb_chunk;
	size_t			nb_element;
	size_t			range_per_chunk;
	t_push_stack	s_copy;

	nb_element = copy.stack_a->_size;
	nb_chunk = ft_sqrt(nb_element);
	range_per_chunk = nb_element / nb_chunk;
	s_copy = push_stack_copy(copy);
	s_copy = bubble_sort_stack(s_copy);
	add_sort_value(&s_copy);
	change_sort_value(&copy, s_copy);
	while (check_stack(copy, PUSH_SWAP))
		merge_algo(&copy, stack, range_per_chunk, id);
	change_by_pattern(stack, id);
	ft_free_stack(&copy);
	ft_free_stack(&s_copy);
	return (stack->algo[id]->size);
}
