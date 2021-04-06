/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akerdeka <akerdeka@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 09:06:26 by coscialp          #+#    #+#             */
/*   Updated: 2021/04/06 12:37:33 by akerdeka         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../Dependencies/libft/includes/stack.h"

/*
**┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
**┃                                  Define                                   ┃
**┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛
*/

# define STDIN 0
# define STDOUT 1
# define STDERR 2

# define DUNUM 0x000001
# define NONUM 0x000002
# define NOTINS 0x000003

# define CHECKER 0x000010
# define PUSH_SWAP 0x000011

# define STACK_A 0x000012
# define STACK_B 0x000013

# define SA "sa"
# define SB "sb"
# define SS "ss"
# define PA "pa"
# define PB "pb"
# define RA "ra"
# define RB "rb"
# define RR "rr"
# define RRA "rra"
# define RRB "rrb"
# define RRR "rrr"

/*
**┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
**┃                                  Enum                                     ┃
**┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛
*/

typedef enum e_ins
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
}			t_ins;

/*
**┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
**┃                                  Struct Result                            ┃
**┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛
*/

typedef struct s_result
{
	char		**ins;
	size_t		size;
	size_t		capacity;

	void		(*pushback)(struct s_result *, char *);
	void		(*pushfront)(struct s_result *, char *);
	void		(*popback)(struct s_result *);
	void		(*remove)(struct s_result *, int);
}				t_result;

/*
**┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
**┃                             Struct Push_Swap                              ┃
**┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛
*/

typedef struct s_push_stack		t_push_stack;
struct s_push_stack
{
	t_stack			*stack_a;
	t_stack			*stack_b;
	t_result		*algo[2];

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

/*
**┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
**┃                             Struct Instruction                            ┃
**┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛
*/

typedef struct s_instruction	t_instruc;
struct s_instruction
{
	int		value;
	void	(*func)(t_push_stack *);
};

/*
**┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
**┃                             Struct Pattern                                ┃
**┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛
*/

typedef struct s_pattern
{
	int			size;
	int			new_size;
	char		*current[4];
	char		*newpattern[4];
}				t_pattern;

/*
**┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
**┃                                Error                                      ┃
**┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛
*/

void			log_error(int error);
void			stack_state(t_push_stack s, size_t max, size_t i);
bool			check_stack(t_push_stack s, int program);
bool			no_duplicate_number(t_stack *a, int value);
void			parser(t_push_stack *s, t_instruc *insn, char **arg);

/*
**┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
**┃                             struct Push_Swap.c                            ┃
**┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛
*/

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
t_push_stack	push_stack_copy(t_push_stack s);
t_push_stack	push_stack_copy(t_push_stack s);

/*
**┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
**┃                             Searching value and index                     ┃
**┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛
*/

int				find_smallest_element(t_push_stack stack, int id_stack);
int				find_smallest_element_index(t_push_stack stack, int smallest);
int				find_smallest_element_index_b(t_push_stack stack, int smallest);
int				find_greatest_element(t_push_stack stack, int id_stack);
t_push_stack	bubble_sort_stack(t_push_stack s);
void			change_sort_value(t_push_stack *real_stack, t_push_stack copy);
void			add_sort_value(t_push_stack *stack);
void			ft_intswap(int *a, int *b);
int				ft_log(size_t value);
int				find_median(t_stack *s);
int				get_value(char **ptr);

/*
**┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
**┃                               Algorithm                                   ┃
**┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛
*/

int				second_algo(t_push_stack stack, t_instruc *insn);
int				first_algo(t_push_stack copy, t_push_stack *s, int id);
int				quick_sort(t_push_stack s, int id);
int				merge_sort(t_push_stack cpy, t_push_stack *s, int id);
bool			check_order_stack(t_push_stack s, int id_stack);
void			change_by_pattern(t_push_stack *s, int id);
void			print_instruction(t_result *r);

/*
**┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
**┃                             struct result.c                               ┃
**┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛
*/

t_result		*new_res(void);
void			res_remove(t_result *res, int index);
void			ft_strswap(char **a, char **b);
void			res_popback(t_result *res);
void			res_pushback(t_result *res, char *value);
void			res_pushfront(t_result *res, char *value);
void			realloc_ins(t_result *res, size_t capacity);
void			first_in_last(t_result *res);
void			last_in_front(t_result *res);

#endif
