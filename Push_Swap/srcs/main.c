/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akerdeka <akerdeka@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 13:13:05 by coscialp          #+#    #+#             */
/*   Updated: 2021/03/09 10:30:33 by akerdeka         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "../../Includes/push_swap.h"

int	get_value(char **ptr)
{
	int	value;

	value = 0;
	while (**ptr != '\0')
	{
		value <<= 8;
		value += **ptr;
		(*ptr)++;
	}
	return (value);
}

char	**clone(char **str)
{
	static char	*ptr;

	ptr = *str;
	return (&ptr);
}

static void	push_swap(t_push_stack s, t_instruc *insn)
{
	first_algo(s, insn);
	check_stack(s);
}

void	parser(t_push_stack *s, t_instruc *insn, char **arg)
{
	char	*tok;

	tok = NULL;
	tok = ft_strsep(arg, " ");
	while (tok)
	{
		if (ft_stris(tok, ft_is_number))
		{
			if (s->stack_b->push(s->stack_b, ft_atoi(tok)) == -1 || \
			no_duplicate_number(s->stack_a, ft_atoi(tok)))
				log_error(DUNUM);
		}
		else
			log_error(NONUM);
		tok = ft_strsep(arg, " ");
	}
	while (s->stack_b->_size)
		insn[3].func(s);
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
