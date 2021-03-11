/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coscialp <coscialp@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 09:01:20 by coscialp          #+#    #+#             */
/*   Updated: 2021/03/11 10:41:58 by coscialp         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	check_stack_checker(t_push_stack s)
{
	t_node_stack	*a;

	if (s.stack_b->_size != 0)
	{
		ft_dprintf(1, "\033[31;01m[KO]\033[00m\n");
		exit(1);
	}
	a = s.stack_a->_data;
	while (a->_next)
	{
		if (a->value > a->_next->value)
		{
			ft_dprintf(1, "\033[31;01m[KO]\033[00m\n");
			exit(1);
		}
		a = a->_next;
	}
	ft_dprintf(1, "\033[32;01m[OK]\033[00m\n");
	exit(0);
}

static bool	check_stack_pushswap(t_push_stack s)
{
	t_node_stack	*a;

	if (s.stack_b->_size != 0)
		return (1);
	a = s.stack_a->_data;
	while (a->_next)
	{
		if (a->value > a->_next->value)
			return (1);
		a = a->_next;
	}
	return (0);
}

bool	check_stack(t_push_stack s, int program)
{
	if (program == CHECKER)
		check_stack_checker(s);
	else if (program == PUSH_SWAP)
		return (check_stack_pushswap(s));
	return (0);
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

bool	no_duplicate_number(t_stack *a, int value)
{
	t_node_stack	*tmp;

	tmp = a->_data;
	while (tmp)
	{
		if (tmp->value == value)
			return (1);
		tmp = tmp->_next;
	}
	return (0);
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
