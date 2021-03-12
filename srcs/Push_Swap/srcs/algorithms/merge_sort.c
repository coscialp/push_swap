/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coscialp <coscialp@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 08:51:54 by akerdeka          #+#    #+#             */
/*   Updated: 2021/03/12 09:16:01 by coscialp         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "../../../Includes/push_swap.h"

int	merge_sort(t_push_stack stack, int id)
{
	(void)id;
	int		nb_chunk;

	nb_chunk = ft_log(stack.stack_a->_size);
	dprintf(2, "%d\n", nb_chunk);
	return (0);
}