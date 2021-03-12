/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akerdeka <akerdeka@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 08:51:54 by akerdeka          #+#    #+#             */
/*   Updated: 2021/03/12 13:22:10 by akerdeka         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "../../../Includes/push_swap.h"

int	merge_sort(t_push_stack stack, int id)
{
	(void)id;
	int		nb_chunk;
	t_push_stack	s_copy;
	t_node_stack	*tmp;

	tmp = stack.stack_a->_data;
	nb_chunk = ft_log(stack.stack_a->_size);
	s_copy = push_stack_copy(stack);
	dprintf(2, "BUG\n");
	s_copy = bubble_sort_stack(s_copy);
	dprintf(2, "BUG2\n");
	add_sort_value(&s_copy);
	dprintf(2, "BUG3\n");
	change_sort_value(&stack, s_copy);
	dprintf(2, "BUG4\n");
	stack.stack_a->_data = tmp;
	while (stack.stack_a->_data)
	{
		if (!stack.stack_a->_data)
			break ;
		dprintf(2, "value : %d\tsort_value = %zu\n", stack.stack_a->_data->value, stack.stack_a->_data->sort_value);
		stack.stack_a->_data = stack.stack_a->_data->_next;
	}
	return (0);
}
