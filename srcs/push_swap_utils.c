/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akerdeka <akerdeka@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 09:24:52 by akerdeka          #+#    #+#             */
/*   Updated: 2021/03/11 10:58:53 by akerdeka         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//int	change_sort_value(t_push_stack s)
//{
//	size_t			sort_value;
//	int				smallest;
//	t_node_stack	*tmp;
//
//	sort_value = 0;
//	while (1)
//	{
//		smallest = find_smallest_element_a(s);
//		tmp = s.stack_a->_data;
//		if (sort_value == s.stack_a->_size)
//			break ;
//		while (tmp)
//		{
//			if (tmp->value == smallest)
//				break ;
//			tmp = tmp->_next;
//		}
//		tmp->sort_value = sort_value;
//		sort_value++;
//	}
//	return (0);
//}

int	ft_log(size_t value)
{
	size_t	e;
	int		ret;

	e = 1;
	ret = 0;
	while (value > e)
	{
		e *= 2;
		ret++;
	}
	return (ret);
}

int	find_smallest_element_a(t_push_stack stack)
{
	int				smallest;
	t_node_stack	*tmp;

	smallest = INT_MAX;
	tmp = stack.stack_a->_data;
	while (tmp)
	{
		if (tmp->value < smallest)
			smallest = tmp->value;
		// dprintf(2, "DEBUG: value: %d smallest: %d\n", tmp->value, smallest);
		tmp = tmp->_next;
	}
	// dprintf(2, "DEBUG: Choice: smallest: %d\n", smallest);
	return (smallest);
}

int	find_smallest_element_b(t_push_stack stack)
{
	int				smallest;
	t_node_stack	*tmp;

	smallest = INT_MAX;
	tmp = stack.stack_b->_data;
	while (tmp)
	{
		if (tmp->value < smallest)
			smallest = tmp->value;
		// dprintf(2, "DEBUG: value: %d smallest: %d\n", tmp->value, smallest);
		tmp = tmp->_next;
	}
	// dprintf(2, "DEBUG: Choice: smallest: %d\n", smallest);
	return (smallest);
}

int	find_smallest_element_index(t_push_stack stack, int smallest)
{
	t_node_stack	*tmp;
	int				i;

	tmp = stack.stack_a->_data;
	i = 0;
	while (tmp)
	{
		if (tmp->value == smallest)
			break ;
		tmp = tmp->_next;
		i++;
	}
	return (i);
}