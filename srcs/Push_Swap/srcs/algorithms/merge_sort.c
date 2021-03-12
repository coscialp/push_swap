/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akerdeka <akerdeka@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 08:51:54 by akerdeka          #+#    #+#             */
/*   Updated: 2021/03/12 15:32:08 by akerdeka         ###   ########lyon.fr   */
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

	nb_chunk = ft_log(stack.stack_a->_size);
	s_copy = push_stack_copy(stack);
	s_copy = bubble_sort_stack(s_copy);
	add_sort_value(&s_copy);
	change_sort_value(&stack, s_copy);
	tmp = stack.stack_a->_data;
	while (stack.stack_a->_data)
	{
		dprintf(2, "value : %d\tsort_value = %zd\n", stack.stack_a->_data->value, stack.stack_a->_data->sort_value);
		stack.stack_a->_data = stack.stack_a->_data->_next;
	}
	stack.stack_a->_data = tmp;
	return (0);
}
