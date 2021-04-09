/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pattern.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coscialp <coscialp@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 13:45:19 by coscialp          #+#    #+#             */
/*   Updated: 2021/04/08 13:43:54 by coscialp         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

static void	delete_instruction(t_push_stack *s, int index, int each, int algo)
{
	while (each--)
		s->algo[algo]->remove(s->algo[algo], index);
}

static bool	compare_pattern(t_pattern pattern, t_result *res, size_t index)
{
	int			i;
	static int	cmp = 0;

	i = -1;
	cmp++;
	while (++i < pattern.size)
		if (res->size <= (size_t)(i + index) || \
		(int)res->ins[i + index] != pattern.current[i])
			return (1);
	return (0);
}

static void	insert_instruction(t_pattern pattern, t_result *res, size_t index)
{
	if (res->size + pattern.new_size > res->capacity)
		realloc_ins(res, res->capacity * 2);
	ft_memmove(res->ins + index + pattern.new_size, \
	res->ins + index, (res->size - index) * sizeof(t_ins));
	ft_memcpy(res->ins + index, pattern.newpattern, \
	pattern.new_size * sizeof(t_ins));
	res->size += pattern.new_size;
}

static void	change_pattern(t_push_stack *s, int id, t_pattern *pattern)
{
	int					i;
	size_t				j;

	j = -1;
	while (++j < s->algo[id]->size)
	{
		i = -1;
		while (++i < 14)
		{
			if (j + pattern[i].size <= s->algo[id]->size && \
			!compare_pattern(pattern[i], s->algo[id], j))
			{
				delete_instruction(s, j, pattern[i].size, id);
				if (pattern[i].new_size != 0)
					insert_instruction(pattern[i], s->algo[id], j);
				j -= !!j;
				j -= !!j;
				break ;
			}
		}
	}
}

void	change_by_pattern(t_push_stack *s, int id)
{
	static t_pattern	pattern[14] = {
		{3, 2, {Ra, Pb, Rra}, {Sa, Pb}}, {3, 2, {Pb, Ra, Pa}, {Sa, Ra}},
		{2, 1, {Sa, Sb}, {Ss}}, {2, 1, {Sb, Sa}, {Ss}},
		{2, 0, {Ra, Rra}, {}}, {2, 0, {Rb, Rrb}, {}},
		{2, 0, {Rra, Ra}, {}}, {2, 0, {Rrb, Rb}, {}},
		{2, 1, {Ra, Rb}, {Rr}}, {2, 1, {Rb, Ra}, {Rr}},
		{2, 1, {Rra, Rrb}, {Rrr}}, {2, 1, {Rrb, Rra}, {Rrr}},
		{2, 0, {Pb, Pa}, {}}, {2, 0, {Pa, Pb}, {}}
	};

	change_pattern(s, id, pattern);
}
