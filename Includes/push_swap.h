/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coscialp <coscialp@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 09:06:26 by coscialp          #+#    #+#             */
/*   Updated: 2021/03/08 09:42:16 by coscialp         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../Dependencies/libft/includes/stack.h"

# define DUNUM 0x000001
# define NONUM 0x000002
# define NOTINS 0x000003

typedef enum e_cmd
{
	Sa = 0x7361,
	Sb = 0x7362,
	Ss = 0x7373,
	Pa = 0x7061,
	Pb = 0x7062,
	Ra = 0x7261,
	Rb = 0x7262,
	Rr = 0x7272,
	Rra = 0x727261,
	Rrb = 0x727262,
	Rrr = 0x727272
}			t_cmd;

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

typedef struct s_instruction	t_instruc;
struct s_instruction
{
	int		value;
	void	(*func)(t_push_stack *);
};

void			log_error(int error);
void			stack_state(t_push_stack s, size_t i);
size_t			st_max(size_t a, size_t b);
size_t			st_min(size_t a, size_t b);

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
