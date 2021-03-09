/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coscialp <coscialp@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 13:13:05 by coscialp          #+#    #+#             */
/*   Updated: 2021/03/09 09:40:55 by coscialp         ###   ########lyon.fr   */
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
					stack_state(s, \
					st_max(s.stack_a->_size, s.stack_b->_size), nb);
				break ;
			}
		}
		if (i == 11)
			log_error(NOTINS);
		ft_strdel(&line);
	}
	check_stack(s);
}

bool	no_duplicate_number(t_stack *a, int value)
{
	t_node_stack	*tmp;

	tmp = a->_data;
	while (tmp)
	{
		if (tmp->value == value)
			return (1);
		tmp = tmp->_next;
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_push_stack		stack;
	static int			stop = 1;
	static char			*tok = NULL;
	static t_instruc	insn[11] = {
		{Sa, swap_a}, {Sb, swap_b}, {Ss, swap_s}, \
		{Pa, push_a}, {Pb, push_b}, {Ra, rotate_a}, \
		{Rb, rotate_b}, {Rr, rotate_r}, {Rra, r_rotate_a}, \
		{Rrb, r_rotate_b}, {Rrr, r_rotate_r}
	};

	if (ac >= 2)
	{
		stack = new_push_stack();
		if (!ft_strcmp(av[1], "-v"))
			stop = 2;
		while (ac-- > stop)
		{
			tok = ft_strsep(&av[ac], " ");
			while (tok)
			{
				if (ft_stris(tok, ft_is_number))
				{
					if (stack.stack_b->push(stack.stack_b, ft_atoi(tok)) == -1 || \
					no_duplicate_number(stack.stack_a, ft_atoi(tok)))
						log_error(DUNUM);
				}
				else
					log_error(NONUM);
				tok = ft_strsep(&av[ac], " ");
			}
			while (stack.stack_b->_size)
				insn[3].func(&stack);
		}
		checker(stack, insn, stop);
	}
	return (0);
}
