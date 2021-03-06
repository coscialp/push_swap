/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akerdeka <akerdeka@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 13:13:05 by coscialp          #+#    #+#             */
/*   Updated: 2021/03/11 11:22:01 by akerdeka         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

char	**clone(char **str)
{
	static char	*ptr;

	ptr = *str;
	return (&ptr);
}

static void	checker(t_push_stack s, t_instruc *insn, int stop)
{
	int				value;
	static size_t	nb = 0;
	short			i;
	static char		*line = NULL;

	while (get_next_line(0, &line) > 0)
	{
		value = get_value(clone(&line));
		i = -1;
		while (++i < 11)
		{
			if (insn[i].value == value && nb++ >= 0)
			{
				insn[i].func(&s);
				if (stop == 2)
				{
					ft_dprintf(2, "\n    instruction: %s\n", line);
					stack_state(s, \
					st_max(s.stack_a->_size, s.stack_b->_size), nb);
				}
				break ;
			}
		}
		if (i == 11)
			log_error(NOTINS);
		ft_strdel(&line);
	}
	check_stack(s, CHECKER);
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
		checker(stack, insn, stop);
	}
	return (0);
}
