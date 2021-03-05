/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coscialp <coscialp@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 13:13:05 by coscialp          #+#    #+#             */
/*   Updated: 2021/03/05 14:02:34 by coscialp         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

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

void	check_stack(t_push_stack s)
{
	if (s.stack_b->_size != 0)
	{
		ft_dprintf(1, "[KO]\n");
		exit(1);
	}
	t_node_stack *a;

	a = s.stack_a->_data;
	while (a->_next)
	{
		if (a->value > a->_next->value)
		{
			ft_dprintf(1, "[KO]\n");
			exit(1);
		}
		a = a->_next;
	}
	ft_dprintf(1, "[OK]\n");
	exit(0);
}


int	main(int ac, char **av)
{
	static char			*line = NULL;
	char				*ptr;
	t_push_stack		stack;
	static t_instruc	insn[11] = {
		{0x7361, swap_a}, {0x7362, swap_b}, {0x7373, swap_s}, \
		{0x7061, push_a}, {0x7062, push_b}, {0x7261, rotate_a}, \
		{0x7262, rotate_b}, {0x7272, rotate_r}, {0x727261, r_rotate_a}, \
		{0x727262, r_rotate_b}, {0x727272, r_rotate_r}
	};
	int		value;
	short	i;

	if (ac >= 2)
	{
		stack = new_push_stack();
		while (ac-- > 1)
		{
			if (ft_stris(av[ac], ft_is_number))
			{
				if (stack.stack_a->push(stack.stack_a, ft_atoi(av[ac])) == -1)
					log_error(DUNUM);
			}
			else
				log_error(NONUM);
		}
		while (get_next_line(0, &line) > 0)
		{
			ptr = line;
			value = get_value(&ptr);
			i = -1;
			while (++i < 11)
			{
				if (insn[i].value == value)
				{
					insn[i].func(&stack);
					stack_state(stack);
					break ;
				}
			}
			if (i == 11)
				log_error(NOTINS);
			ft_strdel(&line);
		}
		check_stack(stack);
	}
	return (0);
}
