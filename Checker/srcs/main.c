/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coscialp <coscialp@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 13:13:05 by coscialp          #+#    #+#             */
/*   Updated: 2021/03/05 10:58:03 by coscialp         ###   ########lyon.fr   */
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
	ft_dprintf(2, "%x\n", value);
	return (value);
}

int	main(int ac, char **av)
{
	static char			*line = NULL;
	char				*ptr;
	t_push_stack		stack;
	static t_instruc	insn[11] = {
		{0x7361, swap_a}, {0x7362, swap_b}, {0x7373, swap_s}, \
		{0x7062, push_a}, {0x7062, push_b}, {0x7261, rotate_a}, \
		{0x7262, rotate_b}, {0x7272, rotate_r}, {0x727261, r_rotate_a}, \
		{0x727262, r_rotate_b}, {0x727272, r_rotate_r}
	};

	(void)insn;
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
			get_value(&ptr);
			ft_strdel(&line);
		}
	}
	return (0);
}
