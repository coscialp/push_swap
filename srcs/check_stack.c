/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akerdeka <akerdeka@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 13:51:01 by coscialp          #+#    #+#             */
/*   Updated: 2021/03/12 15:22:49 by akerdeka         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

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
