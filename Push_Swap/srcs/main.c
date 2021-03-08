/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akerdeka <akerdeka@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 13:13:05 by coscialp          #+#    #+#             */
/*   Updated: 2021/03/08 14:07:23 by akerdeka         ###   ########lyon.fr   */
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

void	check_stack(t_push_stack s)
{
	t_node_stack	*a;

	if (s.stack_b->_size != 0)
	{
		ft_dprintf(1, "\033[31;01m[KO]\033[00m\n");
		exit(1);
	}
	a = s.stack_a->_data;
	while (a->_next)
	{
		if (a->value > a->_next->value)
		{
			ft_dprintf(1, "\033[31;01m[KO]\033[00m\n");
			exit(1);
		}
		a = a->_next;
	}
	ft_dprintf(1, "\033[32;01m[OK]\033[00m\n");
	exit(0);
}

static void	checker(t_push_stack s, char *ptr, t_instruc *insn, int stop)
{
	int			value;
	size_t		nb;
	short		i;
	static char	*line = NULL;

	nb = 0;
	while (get_next_line(0, &line) > 0)
	{
		ptr = line;
		value = get_value(&ptr);
		i = -1;
		while (++i < 11)
		{
			if (insn[i].value == value)
			{
				insn[i].func(&s);
				nb++;
				if (stop == 2)
					stack_state(s, st_max(s.stack_a->_size, s.stack_b->_size), nb);
				break ;
			}
		}
		if (i == 11)
			log_error(NOTINS);
		ft_strdel(&line);
	}
	check_stack(s);
}

static char	*ft_strsep(char **stringp, const char *delim)
{
	char	*begin;
	char	*end;

	begin = *stringp;
	if (begin == NULL)
		return (NULL);
	end = begin + ft_strcspn(begin, delim);
	if (*end)
	{
		*end++ = '\0';
		*stringp = end;
	}
	else
		*stringp = NULL;
	return (begin);
}

int	main(int ac, char **av)
{
	static char			*ptr = NULL;
	t_push_stack		stack;
	static int			stop = 1;
	static t_instruc	insn[11] = {
		{Sa, swap_a}, {Sb, swap_b}, {Ss, swap_s}, \
		{Pa, push_a}, {Pb, push_b}, {Ra, rotate_a}, \
		{Rb, rotate_b}, {Rr, rotate_r}, {Rra, r_rotate_a}, \
		{Rrb, r_rotate_b}, {Rrr, r_rotate_r}
	};
	static char	*tok = NULL;

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
					if (stack.stack_b->push(stack.stack_b, ft_atoi(tok)) == -1)
						log_error(DUNUM);
				}
				else
					log_error(NONUM);
				tok = ft_strsep(&av[ac], " ");
			}
			while (stack.stack_b->_size)
				insn[3].func(&stack);
		}
		checker(stack, ptr, insn, stop);
	}
	return (0);
}
