/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coscialp <coscialp@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 09:01:20 by coscialp          #+#    #+#             */
/*   Updated: 2021/03/05 13:23:35 by coscialp         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#define MIN(a, b) ((a < b) ? a : b)
#define MAX(a, b) ((a > b) ? a : b)

void	stack_state(t_push_stack s)
{
	size_t	i;
	t_node_stack *a;
	t_node_stack *b;

	a = s.stack_a->_data;
	b = s.stack_b->_data;
	i = MAX(s.stack_a->_size, s.stack_b->_size);

	while (i > MIN(s.stack_a->_size, s.stack_b->_size))
	{
		if (s.stack_a->_size > s.stack_b->_size)
		{
			ft_dprintf(2, "%10d | \n", a->value);
			a = a->_next;
		}
		else
		{
			ft_dprintf(2, "           | %-10d\n", b->value);
			b = b->_next;
		}
		--i;
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
