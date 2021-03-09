/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_result.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coscialp <coscialp@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 11:43:12 by coscialp          #+#    #+#             */
/*   Updated: 2021/03/09 13:16:52 by coscialp         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

void	realloc_ins(t_result *res, size_t capacity)
{
	size_t	i;
	char	**ret;

	i = -1;
	ret = ft_memalloc(capacity * sizeof(char**));
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
	res->pushback(res, value);
	ft_strswap(&res->ins[0], &res->ins[res->size - 1]);
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

void	ft_strswap(char **a, char **b)
{
	char *tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	remove_first(t_result *res)
{
	ft_strswap(&res->ins[0], &res->ins[res->size - 1]);
	res->popback(res);
}

t_result	*new_res(void)
{
	t_result	*res;

	res = ft_xmalloc(sizeof(t_result));
	res->capacity = 4;
	res->ins = ft_calloc(4, sizeof(char **));
	res->size = 0;
	res->popback = res_popback;
	res->pushback = res_pushback;
	return (res);
}