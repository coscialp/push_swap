/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   result.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akerdeka <akerdeka@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 11:43:12 by coscialp          #+#    #+#             */
/*   Updated: 2021/04/06 15:53:29 by akerdeka         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

void	ft_strswap(char **a, char **b)
{
	char	*tmp;

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
		ft_insswap(&res->ins[i], &res->ins[i + 1]);
		i++;
	}
	res->popback(res);
}

void	first_in_last(t_result *res)
{
	size_t	i;

	i = -1;
	while (++i < res->size - 1)
		ft_insswap(&res->ins[i], &res->ins[i + 1]);
}

void	last_in_front(t_result *res)
{
	size_t	i;

	i = res->size;
	while (--i > 0)
		ft_insswap(&res->ins[i], &res->ins[i - 1]);
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
