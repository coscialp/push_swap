/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   result_modifier.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akerdeka <akerdeka@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 13:52:58 by coscialp          #+#    #+#             */
/*   Updated: 2021/04/06 15:27:04 by akerdeka         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

void	realloc_ins(t_result *res, size_t capacity)
{
	size_t	i;
	t_ins	*ret;

	i = -1;
	ret = ft_memalloc(capacity * sizeof(t_ins *));
	while (++i < res->size)
		ret[i] = res->ins[i];
	i = -1;
	free(res->ins);
	res->ins = ret;
	res->capacity = capacity;
}

void	res_pushfront(t_result *res, t_ins value)
{
	int	i;

	res->pushback(res, value);
	i = res->size;
	while (--i > 0)
		ft_insswap(&res->ins[i], &res->ins[i - 1]);
}

void	res_pushback(t_result *res, t_ins value)
{
	if (res->size >= res->capacity)
		realloc_ins(res, res->capacity * 2);
	res->ins[res->size] = value;
	res->size++;
}

void	res_popback(t_result *res)
{
	--res->size;
}
