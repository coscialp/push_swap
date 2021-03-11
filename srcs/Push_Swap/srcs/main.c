/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coscialp <coscialp@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 13:13:05 by coscialp          #+#    #+#             */
/*   Updated: 2021/03/11 10:52:16 by coscialp         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

static void	push_swap(t_push_stack s, t_instruc *insn)
{
	size_t	i;
	static t_pattern pattern[7] = {
		{2, 1, {"sa", "sb"}, {"ss"}},
		{2, 1, {"sb", "sa"}, {"ss"}},
		{2, 1, {"ra", "rb"}, {"rr"}},
		{2, 1, {"rb", "ra"}, {"rr"}},
		{2, 1, {"rra", "rrb"}, {"rrr"}},
		{2, 1, {"rrb", "rra"}, {"rrr"}},
		{3, 2, {"ra", "pb", "rra"}, {"sa", "pb"}}
	};
	int	tmp_nb;
	int	min_insn;
	int	best_algo;

	i = 0;
	best_algo = 0;
	min_insn = INT_MAX;
	while (i < 1)
	{
		while (check_stack(s, PUSH_SWAP))
		{
			if (i == 0)
				tmp_nb = first_algo(s, insn, i);
		}
		if (tmp_nb < min_insn)
		{
			min_insn = tmp_nb;
			best_algo = i;
		}
		i++;
	}
	i = -1;
	while (++i < 7)
	{
		if (pattern[i].size == 3 && s.algo[best_algo]->size >= 3)
		{
			size_t	j = -1;
			while (++j < s.algo[best_algo]->size - 2)
			{
				if (!ft_strcmp(pattern[i].current[0], s.algo[best_algo]->ins[j]) && \
					!ft_strcmp(pattern[i].current[1], s.algo[best_algo]->ins[j + 1]) && \
					!ft_strcmp(pattern[i].current[2], s.algo[best_algo]->ins[j + 2]))
					{
						s.algo[best_algo]->remove(s.algo[best_algo], j);
						s.algo[best_algo]->remove(s.algo[best_algo], j);
						s.algo[best_algo]->remove(s.algo[best_algo], j);
						int k = pattern[i].new_size;
						size_t l = -1;
						while (++l < j)
							first_in_last(s.algo[best_algo]);
						while (--k >= 0)
							s.algo[best_algo]->pushfront(s.algo[best_algo], pattern[i].newpattern[k]);
						l = -1;
						while (++l < j)
							last_in_front(s.algo[best_algo]);
					}
			}
		}
		else if (pattern[i].size == 2 && s.algo[best_algo]->size >= 2)
		{
			size_t	j = -1;
			while (++j < s.algo[best_algo]->size - 1)
			{
				if (!ft_strcmp(pattern[i].current[0], s.algo[best_algo]->ins[j]) && \
					!ft_strcmp(pattern[i].current[1], s.algo[best_algo]->ins[j + 1]))
					{
						s.algo[best_algo]->remove(s.algo[best_algo], j);
						s.algo[best_algo]->remove(s.algo[best_algo], j);
						int k = pattern[i].new_size;
						size_t l = -1;
						while (++l < j)
							first_in_last(s.algo[best_algo]);
						while (--k >= 0)
							s.algo[best_algo]->pushfront(s.algo[best_algo], pattern[i].newpattern[k]);
						l = -1;
						while (++l < j)
							last_in_front(s.algo[best_algo]);
					}
			}
		}
	}
	i = -1;
	while (++i < s.algo[best_algo]->size)
		ft_dprintf(STDOUT, "%s\n", s.algo[best_algo]->ins[i]);
}

int	main(int ac, char **av)
{
	t_push_stack		stack;
	static int			stop = 1;
	static t_instruc	insn[11] = {
		{Sa, swap_a}, {Sb, swap_b}, {Ss, swap_s}, {Pa, push_a}, \
		{Pb, push_b}, {Ra, rotate_a}, {Rb, rotate_b}, {Rr, rotate_r}, \
		{Rra, r_rotate_a}, {Rrb, r_rotate_b}, {Rrr, r_rotate_r}
	};

	if (ac >= 2)
	{
		stack = new_push_stack();
		if (!ft_strcmp(av[1], "-v"))
			stop = 2;
		while (ac-- > stop)
			parser(&stack, insn, &av[ac]);
		push_swap(stack, insn);
	}
	return (0);
}
