/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akerdeka <akerdeka@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 08:51:54 by akerdeka          #+#    #+#             */
/*   Updated: 2021/04/07 16:26:10 by akerdeka         ###   ########lyon.fr   */
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

void	find_position(t_stack s, int value, int *first, int *second)
{
	t_node_stack	*tmp;
	int				*stack;
	size_t			i;

	i = -1;
	stack = ft_xmalloc(sizeof(int) * (s._size + 1));
	tmp = s._data;
	while (++i < s._size)
	{
		stack[i] = tmp->value;
		tmp = tmp->_next;
	}
	stack[i] = value;
	i = -1;
	while (++i < s._size)
	{
		if (stack[i] < stack[i + 1])
		{
			ft_intswap(&stack[i], &stack[i + 1]);
			i -= !!i;
			i -= !!i;
		}
	}
	i = -1;
	while (++i < s._size)
	{
		if (stack[i] == value)
		{
			*first = stack[i + 1];
			*second = stack[i - 1];
			free(stack);
			return ;
		}
	}
	free(stack);
}


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
			// dprintf(2, "HERE\n");
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
	// dprintf(2, "5\n");
	element[Value] = find_greatest_element(*cpy, STACK_B);
	// dprintf(2, "6\n");
	element[Index] = find_smallest_element_index_b(*cpy, element[Value]);
	// dprintf(2, "7\n");
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
	// dprintf(2, "HF[%d] = %d\nHL[%d] = %d\n", hold_first[Index], hold_first[Value], hold_last[Index], hold_last[Value]);
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
				// dprintf(2, "%d:before[%d] = %d\n%d:after[%d] = %d\n", hold_first[Value], before[Index], before[Value], hold_first[Value], after[Index], after[Value]);
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
	int				nb_chunk;			//
	size_t			nb_element;			// Modifiable
	size_t			range_per_chunk;	//

	t_push_stack	s_copy;

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
	while (check_stack(cpy, PUSH_SWAP))
	{
		// stack_state(cpy, st_max(cpy.stack_a->_size, cpy.stack_b->_size), 0);
		merge_algo(&cpy, stack, range_per_chunk, id);
	}
	change_by_pattern(stack, id);
	return (stack->algo[id]->size);
}
