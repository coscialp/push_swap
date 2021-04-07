/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pattern.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akerdeka <akerdeka@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 13:45:19 by coscialp          #+#    #+#             */
/*   Updated: 2021/04/07 16:08:47 by akerdeka         ###   ########lyon.fr   */
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

void	print_instruction(t_result *r)
{
	size_t	i;

	i = -1;
	while (++i < r->size)
	{
		if (r->ins[i] == Pa)
			ft_dprintf(STDOUT, "pa\n");
		else if (r->ins[i] == Pb)
			ft_dprintf(STDOUT, "pb\n");
		else if (r->ins[i] == Sa)
			ft_dprintf(STDOUT, "sa\n");
		else if (r->ins[i] == Sb)
			ft_dprintf(STDOUT, "sb\n");
		else if (r->ins[i] == Ss)
			ft_dprintf(STDOUT, "ss\n");
		else if (r->ins[i] == Ra)
			ft_dprintf(STDOUT, "ra\n");
		else if (r->ins[i] == Rb)
			ft_dprintf(STDOUT, "rb\n");
		else if (r->ins[i] == Rra)
			ft_dprintf(STDOUT, "rra\n");
		else if (r->ins[i] == Rrb)
			ft_dprintf(STDOUT, "rrb\n");
		else if (r->ins[i] == Rr)
			ft_dprintf(STDOUT, "rr\n");
		else if (r->ins[i] == Rrr)
			ft_dprintf(STDOUT, "rrr\n");
	}
}

static void	insert_instruction(t_pattern pattern, t_result *res, size_t index)
{
	if (res->size + pattern.new_size > res->capacity)
		realloc_ins(res, res->capacity * 2);
    ft_memmove(res->ins + index + pattern.new_size, res->ins + index, (res->size - index) * sizeof(t_ins));
    ft_memcpy(res->ins + index, pattern.newpattern, pattern.new_size * sizeof(t_ins));
    res->size += pattern.new_size;
}

void	change_by_pattern(t_push_stack *s, int id)
{
	int					i;
	size_t				j;
	static t_pattern	pattern[14] = {
		{3, 2, {Ra, Pb, Rra}, {Sa, Pb}},
		{3, 2, {Pb, Ra, Pa}, {Sa, Ra}},
		{2, 1, {Sa, Sb}, {Ss}},
		{2, 1, {Sb, Sa}, {Ss}},
		{2, 0, {Ra, Rra}, {}},
		{2, 0, {Rb, Rrb}, {}},
		{2, 0, {Rra, Ra}, {}},
		{2, 0, {Rrb, Rb}, {}},
		{2, 1, {Ra, Rb}, {Rr}},
		{2, 1, {Rb, Ra}, {Rr}},
		{2, 1, {Rra, Rrb}, {Rrr}},
		{2, 1, {Rrb, Rra}, {Rrr}},
		{2, 0, {Pb, Pa}, {}},
		{2, 0, {Pa, Pb}, {}}
	};

	j = 0;
	while (j < s->algo[id]->size)
	{
		i = 0;
		while (i < 14)
		{
			if (j + pattern[i].size <= s->algo[id]->size && !compare_pattern(pattern[i], s->algo[id], j))
			{
				delete_instruction(s, j, pattern[i].size, id);
				if (pattern[i].new_size != 0)
					insert_instruction(pattern[i], s->algo[id], j);
				j -= !!j;
				j -= !!j;
				break ;
			}
			++i;
		}
		++j;
	}
}
