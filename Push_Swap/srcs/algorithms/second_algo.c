/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   second_algo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akerdeka <akerdeka@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 12:58:09 by akerdeka          #+#    #+#             */
/*   Updated: 2021/03/09 13:28:05 by akerdeka         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "../../../Includes/push_swap.h"

int	second_algo(t_push_stack stack, t_instruc *insn)
{
	int				temp_value;
	size_t			index;
	t_node_stack	*tmp;

	(void)insn;
	tmp = stack.stack_a->_data;
	temp_value = tmp->value;
	index = 0;
	if (temp_value < tmp->_next->value)
	{
		
	}
}