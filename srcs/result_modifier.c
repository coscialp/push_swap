/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   result_modifier.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akerdeka <akerdeka@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 13:52:58 by coscialp          #+#    #+#             */
/*   Updated: 2021/04/06 12:38:40 by akerdeka         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

void	realloc_ins(t_result *res, size_t capacity)
{
	size_t	i;
	char	**ret;

	i = -1;
	ret = ft_memalloc(capacity * sizeof(char *));
	while (++i < res->size)
	{
		ret[i] = ft_calloc(4, 1);
		ret[i] = res->ins[i];
	}
	i = -1;
	while (--i < res->size)
		free(res->ins[i]);
	free(res->ins);
	res->ins = ret;
	res->capacity = capacity;
}

void	res_pushfront(t_result *res, char *value)
{
	int	i;

	res->pushback(res, value);
	i = res->size;
	while (--i > 0)
		ft_strswap(&res->ins[i], &res->ins[i - 1]);
}

void	res_pushback(t_result *res, char *value)
{
	if (res->size >= res->capacity)
		realloc_ins(res, res->capacity * 2);
	res->ins[res->size] = ft_strdup(value);
	res->size++;
}

void	res_popback(t_result *res)
{
	ft_strdel(&res->ins[--res->size]);
}
