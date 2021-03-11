/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akerdeka <akerdeka@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 09:06:26 by coscialp          #+#    #+#             */
/*   Updated: 2021/03/09 13:21:44 by akerdeka         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../Dependencies/libft/includes/stack.h"

# define STDIN 0
# define STDOUT 1
# define STDERR 2

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

typedef enum e_ins
{
	SA,
	SB,
	SS,
	PA,
	PB,
	RA,
	RB,
	RR,
	RRA,
	RRB,
	RRR,
}			t_ins;

typedef struct s_result
{
	char		**ins;
	size_t		size;
	size_t		capacity;

	void		(*pushback)(struct s_result *, char *);
	void		(*popback)(struct s_result *);
}				t_result;

typedef struct s_push_stack		t_push_stack;
struct s_push_stack
{
	t_stack			*stack_a;
	t_stack			*stack_b;
	t_result		*algo[1];

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
void			stack_state(t_push_stack s, size_t max, size_t i);
size_t			st_max(size_t a, size_t b);
size_t			st_min(size_t a, size_t b);
void			check_stack(t_push_stack s);
bool			check_stack_p(t_push_stack s);
bool			no_duplicate_number(t_stack *a, int value);

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

int				find_smallest_element(t_push_stack stack);
int				find_smallest_element_index(t_push_stack stack, int smallest);

int				second_algo(t_push_stack stack, t_instruc *insn);
int				first_algo(t_push_stack stack, t_instruc *insn, int id);

t_result		*new_res(void);
void			remove_first(t_result *res);
void			ft_strswap(char **a, char **b);
void			res_popback(t_result *res);
void			res_pushback(t_result *res, char *value);
void			res_pushfront(t_result *res, char *value);
void			realloc_ins(t_result *res, size_t capacity);

#endif
