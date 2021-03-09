/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_algo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akerdeka <akerdeka@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 08:55:48 by akerdeka          #+#    #+#             */
/*   Updated: 2021/03/09 10:26:28 by akerdeka         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "../../../Includes/push_swap.h"

int	first_algo(t_push_stack stack, t_instruc *insn)
{
	(void)insn;
	int		smallest;
	int		smallest_index;

	smallest = find_smallest_element(stack);
	smallest_index = find_smallest_element_index(stack, smallest);
	dprintf(2, "smallest : %d\tindex : %d\n\ntest : %d\n", smallest, smallest_index, 5/2);
	if (smallest_index <= (stack.stack_a->_size / 2))
		;
	return (smallest);
}