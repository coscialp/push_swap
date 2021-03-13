/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akerdeka <akerdeka@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 08:51:54 by akerdeka          #+#    #+#             */
/*   Updated: 2021/03/13 16:37:56 by akerdeka         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "../../../Includes/push_swap.h"

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
	return (0);
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

static void	merge_algo()
{
	static size_t	chunk = 1;

	
}

int	merge_sort(t_push_stack stack, int id)
{
	(void)id;
	int				nb_chunk;			//
	size_t			nb_element;			// Modifiable
	size_t			range_per_chunk;	//

	int				hold_first;
	int				hold_last;

	t_push_stack	s_copy;
	t_node_stack	*tmp;

	nb_chunk = ft_log(stack.stack_a->_size);	//
	nb_element = stack.stack_a->_size;			// TODO : Peut etre simplifié
	range_per_chunk = nb_element / nb_chunk;	//
	dprintf(2, "chunk = %d\telement = %zu\t range = %zu\n", nb_chunk, nb_element, range_per_chunk);

	s_copy = push_stack_copy(stack);
	s_copy = bubble_sort_stack(s_copy);
	add_sort_value(&s_copy);
	change_sort_value(&stack, s_copy);
	tmp = stack.stack_a->_data;
	while (check_stack(stack, PUSH_SWAP))
		merge_algo();
	return (0);
}
