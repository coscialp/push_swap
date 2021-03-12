/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akerdeka <akerdeka@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 13:13:05 by coscialp          #+#    #+#             */
/*   Updated: 2021/03/12 14:17:40 by akerdeka         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

static void	push_swap(t_push_stack s)
{
	size_t	i;
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
				tmp_nb = first_algo(s, i);
				// tmp_nb = merge_sort(s, i);
		}
		if (tmp_nb < min_insn)
		{
			min_insn = tmp_nb;
			best_algo = i;
		}
		i++;
	}
	change_by_pattern(&s, best_algo);
	print_instruction(s.algo[best_algo]);
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
		push_swap(stack);
	}
	return (0);
}
