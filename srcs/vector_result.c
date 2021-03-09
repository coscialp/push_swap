/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_result.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coscialp <coscialp@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 11:43:12 by coscialp          #+#    #+#             */
/*   Updated: 2021/03/09 15:33:53 by coscialp         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

void	realloc_ins(t_result *res, size_t capacity)
{
	size_t	i;
	char	**ret;

	i = -1;
	ret = ft_memalloc(capacity * sizeof(char*));
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
	int i;

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

void	ft_strswap(char **a, char **b)
{
	char *tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	res_remove(t_result *res, int index)
{
	size_t	i;

	i = index;
	while (i < res->size - 1)
	{
		ft_strswap(&res->ins[i], &res->ins[i + 1]);
		i++;
	}
	res->popback(res);
}

void	first_in_last(t_result *res)
{
	size_t	i;

	i = -1;
	while (++i < res->size - 1)
		ft_strswap(&res->ins[i], &res->ins[i + 1]);
}

void	last_in_front(t_result *res)
{
	size_t	i;

	i = res->size;
	while (--i > 0)
		ft_strswap(&res->ins[i], &res->ins[i - 1]);
}

t_result	*new_res(void)
{
	t_result	*res;

	res = ft_xmalloc(sizeof(t_result));
	res->capacity = 4;
	res->ins = ft_calloc(4, sizeof(char *));
	res->size = 0;
	res->popback = res_popback;
	res->pushback = res_pushback;
	res->remove = res_remove;
	res->pushfront = res_pushfront;
	return (res);
}