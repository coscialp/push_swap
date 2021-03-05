/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coscialp <coscialp@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 13:13:05 by coscialp          #+#    #+#             */
/*   Updated: 2021/03/05 08:53:27 by coscialp         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "stack.h"

static int	ft_is_number(int c)
{
	return (ft_isdigit(c) || c == '-');
}

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
				{
					ft_dprintf(2, "Error:\tNo duplicates numbers!\n");
					return (1);
				}
			}
			else
			{
				ft_dprintf(2, "Error:\tOnly numbers are accepted!\n");
				return (1);
			}
		}
		while (get_next_line(0, &line) > 0)
		{
			ft_dprintf(1, "%s\n", line);
			ft_strdel(&line);
		}
	}
	return (0);
}
