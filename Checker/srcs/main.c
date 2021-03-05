/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coscialp <coscialp@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 13:13:05 by coscialp          #+#    #+#             */
/*   Updated: 2021/03/05 09:56:01 by coscialp         ###   ########lyon.fr   */
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

int	main(int ac, char **av)
{
	static char	*line = NULL;
	char		*ptr;
	t_stack		stack;
	int			possible_insn = { 0x7361, 0x7362, 0x7062, 0x7062, 0x7261, 0x7262, 0x7272, 0x727261, 0x727262, 0x727272 };
	t_instruc	insn[11] = {
		{0x7361, }, {0x7362, }, {0x7062, }, {0x7062, }, {0x7261, }, {0x7262, }, {0x7272, }, {0x727261, }, {0x727262, }, {0x727272,}
	};

	if (ac >= 2)
	{
		stack = new_stack();
		while (ac-- > 1)
		{
			if (ft_stris(av[ac], ft_is_number))
			{
				if (stack.push(&stack, ft_atoi(av[ac])) == -1)
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
