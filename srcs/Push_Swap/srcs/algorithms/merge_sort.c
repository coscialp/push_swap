/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akerdeka <akerdeka@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 08:51:54 by akerdeka          #+#    #+#             */
/*   Updated: 2021/03/11 11:38:20 by akerdeka         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "../../../Includes/push_swap.h"

int	merge_sort(t_push_stack stack, t_instruc *insn, int id)
{
	(void)insn;
	(void)id;
	int		nb_chunk;

	nb_chunk = ft_log(stack.stack_a->_size);
	dprintf(2, "%d\n", nb_chunk);
	return (0);
}
