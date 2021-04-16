/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coscialp <coscialp@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 10:49:50 by coscialp          #+#    #+#             */
/*   Updated: 2021/04/12 11:24:36 by coscialp         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

void	*ft_ternary(bool verif, void *a, void *b)
{
	if (verif == 0)
		return (b);
	return (a);
}

long	ft_atol(const char *s)
{
	int		i;
	long	nb;
	int		neg;

	i = 0;
	nb = 0;
	neg = 1;
	while (ft_isspace(s[i]))
		i++;
	if (s[i] == '-' || s[i] == '+')
	{
		if (s[i] == '-')
			neg = -1;
		i++;
	}
	while (ft_isdigit(s[i]))
	{
		nb *= 10;
		nb += s[i] - '0';
		i++;
	}
	return (nb * neg);
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
			continue ;
		if (ft_stris(ft_ternary(tok[0] == '-', tok + 1, tok), ft_isdigit))
		{
			if (ft_atol(tok) >= INT_MIN && ft_atol(tok) <= INT_MAX)
			{
				if (s->stack_b->push(s->stack_b, (int)ft_atol(tok)) == -1 || \
				no_duplicate_number(s->stack_a, (int)ft_atol(tok)))
					log_error(DUNUM, s);
			}
			else
				log_error(OVFLOW, s);
		}
		else
			log_error(NONUM, s);
	}
	while (s->stack_b->_size)
		insn[3].func(s);
}
