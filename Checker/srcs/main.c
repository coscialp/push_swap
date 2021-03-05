/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coscialp <coscialp@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 13:13:05 by coscialp          #+#    #+#             */
/*   Updated: 2021/03/05 09:11:29 by coscialp         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

int	main(int ac, char **av)
{
	static char	*line = NULL;
	t_stack		stack;

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
			ft_dprintf(1, "%s\n", line);
			ft_strdel(&line);
		}
	}
	return (0);
}
