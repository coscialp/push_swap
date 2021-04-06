/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akerdeka <akerdeka@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 08:51:54 by akerdeka          #+#    #+#             */
/*   Updated: 2021/04/06 15:54:56 by akerdeka         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

static int	get_hold_first(t_push_stack s, size_t range, size_t chunk)
{
	t_node_stack	*tmp;

	tmp = s.stack_a->_data;
	while (tmp)
	{
		if (tmp->sort_value < (range * chunk))
			return (tmp->value);
		tmp = tmp->_next;
	}
	return (-1);
}

static int	get_hold_last(t_push_stack s, size_t range, size_t chunk)
{
	t_node_stack	*tmp;

	if (!s.stack_a)
		return (0);
	tmp = s.stack_a->last(s.stack_a);
	while (tmp)
	{
		if (tmp->sort_value < (range * chunk))
			return (tmp->value);
		tmp = tmp->_prev;
	}
	return (0);
}

typedef enum e_value_index
{
	Value,
	Index,
}           t_val_idx;

static void	sort_stack_b(t_push_stack *cpy, t_push_stack *s, int id)
{
	int	element[2];

	if (cpy->stack_a->_data && (element[Value] = find_greatest_element(*cpy, STACK_B)) < cpy->stack_a->_data->value)
	{
		element[Index] = find_smallest_element_index_b(*cpy, element[Value]);
		while (element[Index] != 0)
		{
			if (element[Index] <= (int)cpy->stack_b->_size / 2)
			{
				cpy->rb(cpy);
				s->algo[id]->pushback(s->algo[id], Rb);
			}
			else
			{
				cpy->rrb(cpy);
				s->algo[id]->pushback(s->algo[id], Rrb);
			}
			element[Index] = find_smallest_element_index_b(*cpy, element[Value]);
		}
		cpy->pb(cpy);
		s->algo[id]->pushback(s->algo[id], Pb);
	}
	else if (cpy->stack_a->_data && find_smallest_element(*cpy, STACK_B) > cpy->stack_a->_data->value)
	{
		element[Value] = find_greatest_element(*cpy, STACK_B);
		element[Index] = find_smallest_element_index_b(*cpy, element[Value]);
		while (element[Index] != 0)
		{
			if (element[Index] <= (int)cpy->stack_b->_size / 2)
			{
				cpy->rb(cpy);
				s->algo[id]->pushback(s->algo[id], Rb);
			}
			else
			{
				cpy->rrb(cpy);
				s->algo[id]->pushback(s->algo[id], Rrb);
			}
			element[Index] = find_smallest_element_index_b(*cpy, element[Value]);
		}
		cpy->pb(cpy);
		s->algo[id]->pushback(s->algo[id], Pb);
		cpy->rb(cpy);
		s->algo[id]->pushback(s->algo[id], Rb);
	}
	else
	{
		int med_b = find_median(cpy->stack_b);
		while (cpy->stack_a->_data && cpy->stack_b->_size >= 2 && (cpy->stack_b->_data->value > cpy->stack_a->_data->value || cpy->stack_b->last(cpy->stack_b)->value < cpy->stack_a->_data->value))
		{
			if (cpy->stack_a->_data->value < med_b)
			{
				cpy->rrb(cpy);
				s->algo[id]->pushback(s->algo[id], Rrb);
			}
			else
			{
				cpy->rb(cpy);
				s->algo[id]->pushback(s->algo[id], Rb);
			}
		}
		cpy->pb(cpy);
		s->algo[id]->pushback(s->algo[id], Pb);
	}
	element[Value] = find_greatest_element(*cpy, STACK_B);
	element[Index] = find_smallest_element_index_b(*cpy, element[Value]);
	while (element[Index] != 0)
	{
		if (element[Index] <= (int)cpy->stack_b->_size / 2)
		{
			cpy->rb(cpy);
			s->algo[id]->pushback(s->algo[id], Rb);
		}
		else
		{
			cpy->rrb(cpy);
			s->algo[id]->pushback(s->algo[id], Rrb);
		}
		element[Index] = find_smallest_element_index_b(*cpy, element[Value]);
	}
}

static void	merge_algo(t_push_stack *cpy, t_push_stack *s, size_t range, int id)
{
	static size_t	chunk = 1;
	static size_t	nb_pb = 0;
	int				hold_first[2];
	int				hold_last[2];

	hold_first[Value] = get_hold_first(*cpy, range, chunk);
	hold_last[Value] = get_hold_last(*cpy, range, chunk);
	hold_first[Index] = find_smallest_element_index(*cpy, hold_first[Value]);
	hold_last[Index] = find_smallest_element_index(*cpy, hold_last[Value]);
	// dprintf(2, "HF[%d] = %d\nHL[%d] = %d\n", hold_first[Index], hold_first[Value], hold_last[Index], hold_last[Value]);
	if (hold_first[Index] == 0 || hold_last[Index] == 0)
	{
		nb_pb++;
		if (nb_pb >= range)
		{
			chunk++;
			nb_pb = 0;
			while (check_order_stack(*cpy, STACK_A) == 0)
			{
				cpy->pa(cpy);
				s->algo[id]->pushback(s->algo[id], Pa);
				if (cpy->stack_b->_size == 0)
					return ;
			}
		}
		sort_stack_b(cpy, s, id);
	}
	else if (hold_first[Index] <= ((int)cpy->stack_a->_size) - hold_last[Index])
	{
		// dprintf(2, "BUG\n");
		cpy->ra(cpy);
		s->algo[id]->pushback(s->algo[id], Ra);
	}
	else
	{
		cpy->rra(cpy);
		s->algo[id]->pushback(s->algo[id], Rra);
	}
}

int	merge_sort(t_push_stack cpy, t_push_stack *stack, int id)
{
	int				nb_chunk;			//
	size_t			nb_element;			// Modifiable
	size_t			range_per_chunk;	//

	t_push_stack	s_copy;
	t_node_stack	*tmp;

	nb_chunk = ft_log(stack->stack_a->_size);	//
	nb_chunk *= cpy.stack_a->_size >= 15 && cpy.stack_a->_size <= 100 ? 2 : 1;
	nb_chunk *= cpy.stack_a->_size > 100 ? 2.5 : 1;
	nb_element = cpy.stack_a->_size;			// TODO : Peut etre simplifié
	range_per_chunk = nb_element / nb_chunk;	//
	// dprintf(2, "chunk = %d\telement = %zu\t range = %zu\n", nb_chunk, nb_element, range_per_chunk);

	s_copy = push_stack_copy(cpy);
	s_copy = bubble_sort_stack(s_copy);
	add_sort_value(&s_copy);
	change_sort_value(&cpy, s_copy);
	tmp = cpy.stack_a->_data;
	while (check_stack(cpy, PUSH_SWAP))
	{
		// stack_state(cpy, st_max(cpy.stack_a->_size, cpy.stack_b->_size), 0);
		merge_algo(&cpy, stack, range_per_chunk, id);
	}
	if (nb_element <= 100)
		change_by_pattern(stack, id);
	return (stack->algo[id]->size);
}
