/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coscialp <coscialp@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 09:06:26 by coscialp          #+#    #+#             */
/*   Updated: 2021/03/05 09:40:43 by coscialp         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../Dependencies/libft/includes/stack.h"

# define DUNUM 0x000001
# define NONUM 0x000002

typedef struct s_instruction	t_instruc;
struct s_instruction
{
	int		value;
	void	(*func)(t_stack *);
};

void	log_error(int error);

#endif

