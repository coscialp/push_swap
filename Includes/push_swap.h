/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akerdeka <akerdeka@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 09:06:26 by coscialp          #+#    #+#             */
/*   Updated: 2021/03/05 09:57:54 by akerdeka         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../Dependencies/libft/includes/stack.h"

# define DUNUM 0x000001
# define NONUM 0x000002

void	log_error(int error);

typedef struct s_push_stack		t_push_stack;
struct s_push_stack
{
	t_stack			*stack_a;
	t_stack			*stack_b;
	void			(*sa)(t_push_stack *);
	void			(*sb)(t_push_stack *);
	void			(*ss)(t_push_stack *);
	void			(*pa)(t_push_stack *);
	void			(*pb)(t_push_stack *);
	void			(*ra)(t_push_stack *);
	void			(*rb)(t_push_stack *);
	void			(*rr)(t_push_stack *);
	void			(*rra)(t_push_stack *);
	void			(*rrb)(t_push_stack *);
	void			(*rrr)(t_push_stack *);
};

t_push_stack	new_push_stack(void);
void			swap_a(t_push_stack *stack);
void			swap_b(t_push_stack *stack);
void			swap_s(t_push_stack *stack);
void			push_a(t_push_stack *stack);
void			push_b(t_push_stack *stack);
void			rotate_a(t_push_stack *stack);
void			rotate_b(t_push_stack *stack);
void			rotate_r(t_push_stack *stack);
void			r_rotate_a(t_push_stack *stack);
void			r_rotate_b(t_push_stack *stack);
void			r_rotate_r(t_push_stack *stack);

#endif
