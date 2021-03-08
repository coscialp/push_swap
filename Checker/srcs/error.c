/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coscialp <coscialp@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 09:01:20 by coscialp          #+#    #+#             */
/*   Updated: 2021/03/08 08:49:07 by coscialp         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	stack_state(t_push_stack s, size_t i)
{
	t_node_stack	*a;
	t_node_stack	*b;

	a = s.stack_a->_data;
	b = s.stack_b->_data;
	while (i > st_min(s.stack_a->_size, s.stack_b->_size))
	{
		if (s.stack_a->_size > s.stack_b->_size && \
		ft_dprintf(2, "%10d | \n", a->value))
			a = a->_next;
		else
		{
			ft_dprintf(2, "           | %-10d\n", b->value);
			b = b->_next;
		}
		i--;
	}
	while (i > 0)
	{
		ft_dprintf(2, "%10d | %-10d\n", a->value, b->value);
		a = a->_next;
		b = b->_next;
		--i;
	}
	ft_dprintf(2, "------------------------\n         a | b      \n");
}

void	log_error(int error)
{
	if (error == DUNUM)
		ft_dprintf(2, "Error:\tNo duplicates numbers!\n");
	else if (error == NONUM)
		ft_dprintf(2, "Error:\tOnly numbers are accepted!\n");
	else if (error == NOTINS)
		ft_dprintf(2, "Error:\tNot instruction!\n");
	exit(1);
}
