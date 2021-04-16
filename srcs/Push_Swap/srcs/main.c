/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coscialp <coscialp@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 13:13:05 by coscialp          #+#    #+#             */
/*   Updated: 2021/04/12 15:37:37 by coscialp         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void	print_instruction(t_result *r, size_t i)
{
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

static void	push_swap(t_push_stack s)
{
	size_t	i;
	int		tmp_nb;
	int		min_insn;
	int		best_algo;

	i = 0;
	best_algo = 0;
	min_insn = INT_MAX;
	while (i < 2)
	{
		if (i == 0)
			tmp_nb = first_algo(push_stack_copy(s), &s, i);
		if (i == 1)
			tmp_nb = merge_sort(push_stack_copy(s), &s, i);
		if (tmp_nb < min_insn)
		{
			min_insn = tmp_nb;
			best_algo = i;
		}
		i++;
	}
	print_instruction(s.algo[best_algo], -1);
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
		if (stack.stack_a->_size == 0 && stack.stack_b->_size == 0)
			log_error(NOARG, &stack);
		push_swap(stack);
		ft_free_stack(&stack);
	}
	return (0);
}
