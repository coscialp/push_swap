/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akerdeka <akerdeka@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 08:51:54 by akerdeka          #+#    #+#             */
/*   Updated: 2021/04/08 11:01:58 by akerdeka         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

static void	sort_stack_b(t_push_stack *cpy, t_push_stack *s, int id)
{
	int	element[2];

	if (cpy->stack_a->_data && (element[Value] = find_greatest_element(*cpy, STACK_B)) < cpy->stack_a->_data->value)
	{
		element[Index] = find_smallest_element_index_b(*cpy, element[Value]);
		while (element[Index] != 0)
		{
			if (element[Index] < (int)cpy->stack_b->_size / 2)
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
	}
	else
	{
		int before[2];
		int after[2];
		if (cpy->stack_a->_data && cpy->stack_b->_size >= 2)
		{
			find_position(*(cpy->stack_b), cpy->stack_a->_data->value, &before[Value], &after[Value]);
			before[Index] = find_smallest_element_index_b(*cpy, before[Value]);
			after[Index] = find_smallest_element_index_b(*cpy, after[Value]);
			while ((cpy->stack_b->_data->value > cpy->stack_a->_data->value || cpy->stack_b->last(cpy->stack_b)->value < cpy->stack_a->_data->value))
			{
				if (before[Index] <= ((int)cpy->stack_b->_size) - after[Index])
				{
					cpy->rb(cpy);
					s->algo[id]->pushback(s->algo[id], Rb);
				}
				else
				{
					cpy->rrb(cpy);
					s->algo[id]->pushback(s->algo[id], Rrb);
				}
			}
			cpy->pb(cpy);
			s->algo[id]->pushback(s->algo[id], Pb);
		}
	}
	element[Value] = find_greatest_element(*cpy, STACK_B);
	element[Index] = find_smallest_element_index_b(*cpy, element[Value]);
	if (check_order_stack(*cpy, STACK_A) == 0)
	{
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
	if (hold_first[Index] == 0 || hold_last[Index] == 0)
	{
		nb_pb++;
		if (nb_pb >= range)
		{
			chunk++;
			nb_pb = 0;
			if (cpy->stack_a->_size == 0)
			{
				while (check_order_stack(*cpy, STACK_A) == 0)
				{
					cpy->pa(cpy);
					s->algo[id]->pushback(s->algo[id], Pa);
					if (cpy->stack_b->_size == 0)
						return ;
				}
			}
		}
		sort_stack_b(cpy, s, id);
	}
	else if (hold_first[Index] <= ((int)cpy->stack_a->_size) - hold_last[Index])
	{
		cpy->ra(cpy);
		s->algo[id]->pushback(s->algo[id], Ra);
		int	element[2];
		if ((element[Value] = find_greatest_element(*cpy, STACK_B)) < hold_first[Value])
		{
			element[Index] = find_smallest_element_index_b(*cpy, element[Value]);
			if (element[Index] != 0)
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
		else if (find_smallest_element(*cpy, STACK_B) > hold_first[Value])
		{
			element[Value] = find_greatest_element(*cpy, STACK_B);
			element[Index] = find_smallest_element_index_b(*cpy, element[Value]);
			if (element[Index] != 0)
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
		else
		{
			int before[2];
			int after[2];
			if (cpy->stack_b->_size >= 2)
			{
				find_position(*(cpy->stack_b), hold_first[Value], &before[Value], &after[Value]);
				before[Index] = find_smallest_element_index_b(*cpy, before[Value]);
				after[Index] = find_smallest_element_index_b(*cpy, after[Value]);
				if ((cpy->stack_b->_data->value > hold_first[Value] || cpy->stack_b->last(cpy->stack_b)->value < hold_first[Value]))
				{
					if (before[Index] <= ((int)cpy->stack_b->_size) - after[Index])
					{
						cpy->rb(cpy);
						s->algo[id]->pushback(s->algo[id], Rb);
					}
					else
					{
						cpy->rrb(cpy);
						s->algo[id]->pushback(s->algo[id], Rrb);
					}
				}
			}
		}
	}
	else
	{
		cpy->rra(cpy);
		s->algo[id]->pushback(s->algo[id], Rra);
		int	element[2];
		if ((element[Value] = find_greatest_element(*cpy, STACK_B)) < hold_last[Value])
		{
			element[Index] = find_smallest_element_index_b(*cpy, element[Value]);
			if (element[Index] != 0)
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
		else if (find_smallest_element(*cpy, STACK_B) > hold_last[Value])
		{
			element[Value] = find_greatest_element(*cpy, STACK_B);
			element[Index] = find_smallest_element_index_b(*cpy, element[Value]);
			if (element[Index] != 0)
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
		else
		{
			int before[2];
			int after[2];
			if (cpy->stack_b->_size >= 2)
			{
				find_position(*(cpy->stack_b), hold_last[Value], &before[Value], &after[Value]);
				before[Index] = find_smallest_element_index_b(*cpy, before[Value]);
				after[Index] = find_smallest_element_index_b(*cpy, after[Value]);
				if ((cpy->stack_b->_data->value > hold_last[Value] || cpy->stack_b->last(cpy->stack_b)->value < hold_last[Value]))
				{
					if (before[Index] <= ((int)cpy->stack_b->_size) - after[Index])
					{
						cpy->rb(cpy);
						s->algo[id]->pushback(s->algo[id], Rb);
					}
					else
					{
						cpy->rrb(cpy);
						s->algo[id]->pushback(s->algo[id], Rrb);
					}
				}
			}
		}
	}
}

int	merge_sort(t_push_stack cpy, t_push_stack *stack, int id)
{
	int				nb_chunk;
	size_t			nb_element;
	size_t			range_per_chunk;
	t_push_stack	s_copy;

	nb_element = cpy.stack_a->_size;
	nb_chunk = ft_sqrt(nb_element);
	range_per_chunk = nb_element / nb_chunk;
	s_copy = push_stack_copy(cpy);
	s_copy = bubble_sort_stack(s_copy);
	add_sort_value(&s_copy);
	change_sort_value(&cpy, s_copy);
	while (check_stack(cpy, PUSH_SWAP))
		merge_algo(&cpy, stack, range_per_chunk, id);
	change_by_pattern(stack, id);
	return (stack->algo[id]->size);
}
