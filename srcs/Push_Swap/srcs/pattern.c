/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pattern.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akerdeka <akerdeka@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 13:45:19 by coscialp          #+#    #+#             */
/*   Updated: 2021/04/06 14:19:22 by akerdeka         ###   ########lyon.fr   */
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
		ft_strcmp(res->ins[i + index], pattern.current[i]))
			return (1);
	return (0);
}

void	print_instruction(t_result *r)
{
	size_t	i;

	i = -1;
	while (++i < r->size)
		ft_dprintf(STDOUT, "%s\n", r->ins[i]);
}

static void	insert_instruction(t_pattern pattern, t_result *r, size_t index)
{
	int		k;
	size_t	l;

	k = pattern.new_size;
	l = -1;
	while (++l < index)
		first_in_last(r);
	while (--k >= 0)
		r->pushfront(r, pattern.newpattern[k]);
	l = -1;
	while (++l < index)
		last_in_front(r);
}

void	change_by_pattern(t_push_stack *s, int id)
{
	int					i;
	size_t				j;
	static t_pattern	pattern[9] = {
		{2, 0, {PB, PA}, {}},
		{2, 0, {PA, PB}, {}},
		{2, 1, {SA, SB}, {SS}},
		{2, 1, {SB, SA}, {SS}},
		{2, 1, {RA, RB}, {RR}},
		{2, 1, {RB, RA}, {RR}},
		{2, 1, {RRA, RRB}, {RRR}},
		{2, 1, {RRB, RRA}, {RRR}},
		{3, 2, {RA, PB, RRA}, {SA, PB}}
	};

	i = -1;
	while (++i < 9)
	{
		j = -1;
		while (++j < s->algo[id]->size - pattern[i].size + 1)
		{
			if (!compare_pattern(pattern[i], s->algo[id], j))
			{
				delete_instruction(s, j, pattern[i].size, id);
				if (pattern[i].new_size != 0)
					insert_instruction(pattern[i], s->algo[id], j);
			}
		}
	}
}
