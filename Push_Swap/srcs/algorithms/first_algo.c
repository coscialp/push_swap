/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_algo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akerdeka <akerdeka@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 08:55:48 by akerdeka          #+#    #+#             */
/*   Updated: 2021/03/09 10:31:46 by akerdeka         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "../../../Includes/push_swap.h"

int	first_algo(t_push_stack stack, t_instruc *insn)
{
	(void)insn;
	int		smallest;
	size_t		smallest_index;

	smallest = (size_t)find_smallest_element(stack);
	smallest_index = (size_t)find_smallest_element_index(stack, smallest);
	dprintf(2, "smallest : %d\tindex : %zu\n\ntest : %d\n", smallest, smallest_index, 5/2);
	if (smallest_index <= (stack.stack_a->_size / 2))
		;
	return (smallest);
}