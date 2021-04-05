/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akerdeka <akerdeka@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 08:51:54 by akerdeka          #+#    #+#             */
/*   Updated: 2021/04/05 11:45:02 by akerdeka         ###   ########lyon.fr   */
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



static void	merge_algo(t_push_stack s, size_t range, int id)
{
	static size_t	chunk = 1;
	int				hold_first[2];
	int				hold_last[2];

	hold_first[Value] = get_hold_first(s, range, chunk);
	hold_last[Value] = get_hold_last(s, range, chunk);
	hold_first[Index] = find_smallest_element_index(s, hold_first[Value]);
	hold_last[Index] = find_smallest_element_index(s, hold_last[Value]);
	dprintf(2, "Hold first : %d\t Hold last : %d\n", hold_first[Value], hold_last[Value]);
	dprintf(2, "Hold first i : %d\t Hold last i : %d\n", hold_first[Index], hold_last[Index]);
	if (hold_first[Index] == 0 || hold_last[Index] == 0)
	{
		
	}
	if (hold_first[Index] <= (hold_last[Index] - s.stack_a->_size))
	{
		s.ra(&s);
		s.algo[id]->pushback(s.algo[id], RA);
	}
}

int	merge_sort(t_push_stack stack, int id)
{
	(void)id;
	int				nb_chunk;			//
	size_t			nb_element;			// Modifiable
	size_t			range_per_chunk;	//

	t_push_stack	s_copy;
	t_node_stack	*tmp;

	nb_chunk = 2;//ft_log(stack.stack_a->_size);	//
	nb_element = stack.stack_a->_size;			// TODO : Peut etre simplifié
	range_per_chunk = nb_element / nb_chunk;	//
	dprintf(2, "chunk = %d\telement = %zu\t range = %zu\n", nb_chunk, nb_element, range_per_chunk);

	s_copy = push_stack_copy(stack);
	s_copy = bubble_sort_stack(s_copy);
	add_sort_value(&s_copy);
	change_sort_value(&stack, s_copy);
	tmp = stack.stack_a->_data;
	while (check_stack(stack, PUSH_SWAP))
	{
		merge_algo(stack, range_per_chunk, id);
		break; 
	}
	return (0);
}
