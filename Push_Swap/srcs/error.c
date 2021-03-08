/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akerdeka <akerdeka@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 13:23:08 by akerdeka          #+#    #+#             */
/*   Updated: 2021/03/08 14:08:03 by akerdeka         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/push_swap.h"

inline size_t	st_min(size_t a, size_t b)
{
	if (a < b)
		return (a);
	return (b);
}

inline size_t	st_max(size_t a, size_t b)
{
	if (a > b)
		return (a);
	return (b);
}

void	stack_state(t_push_stack s, size_t max, size_t i)
{
	t_node_stack	*a;
	t_node_stack	*b;

	a = s.stack_a->_data;
	b = s.stack_b->_data;
	while (max > st_min(s.stack_a->_size, s.stack_b->_size))
	{
		if (s.stack_a->_size > s.stack_b->_size && \
		ft_dprintf(2, "%10d | \n", a->value))
			a = a->_next;
		else
		{
			ft_dprintf(2, "           | %-10d\n", b->value);
			b = b->_next;
		}
		max--;
	}
	while (max > 0)
	{
		ft_dprintf(2, "%10d | %-10d\n", a->value, b->value);
		a = a->_next;
		b = b->_next;
		--max;
	}
	ft_dprintf(2, "------------------------\n         a | b      \n");
	ft_dprintf(2, "    nb instruction = %d\n", i);
}

void	log_error(int error)
{
	if (error == DUNUM)
		ft_dprintf(2, "\033[31;01mError:\tNo duplicates numbers!\033[00m\n");
	else if (error == NONUM)
		ft_dprintf(2, "\033[31;01mError:\tOnly numbers are accepted!\033[00m\n");
	else if (error == NOTINS)
		ft_dprintf(2, "\033[31;01mError:\tNot instruction!\033[00m\n");
	exit(1);
}
