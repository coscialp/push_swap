/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coscialp <coscialp@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 10:49:50 by coscialp          #+#    #+#             */
/*   Updated: 2021/03/31 10:31:55 by coscialp         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

void	*ft_ternary(bool verif, void *a, void *b)
{
	if (verif == 0)
		return (a);
	return (b);
}

void	parser(t_push_stack *s, t_instruc *insn, char **arg)
{
	char	*tok;

	while (1)
	{
		tok = ft_strsep(arg, " ");
		if (!tok)
			break ;
		if (!ft_strcmp(tok, ""))
		{
			tok = ft_strsep(arg, " ");
			continue ;
		}
		if (ft_stris(ft_ternary(tok[0] == '-', tok + 1, tok), ft_isdigit))
		{
			if (s->stack_b->push(s->stack_b, ft_atoi(tok)) == -1 || \
			no_duplicate_number(s->stack_a, ft_atoi(tok)))
				log_error(DUNUM);
		}
		else
			log_error(NONUM);
	}
	while (s->stack_b->_size)
		insn[3].func(s);
}
