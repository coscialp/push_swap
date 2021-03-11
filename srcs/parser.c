/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coscialp <coscialp@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 10:49:50 by coscialp          #+#    #+#             */
/*   Updated: 2021/03/11 10:50:20 by coscialp         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

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
