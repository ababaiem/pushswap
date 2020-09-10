/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababaie- <ababaie-@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 19:30:00 by ababaie-          #+#    #+#             */
/*   Updated: 2020/09/10 21:23:40 by ababaie-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft/libft.h"

# define SA "sa"
# define SB "sb"
# define SS "ss"
# define RA "ra"
# define RB "rb"
# define RR "rr"
# define RRA "rra"
# define RRB "rrb"
# define RRR "rrr"
# define PA "pa"
# define PB "pb"
# define OK "OK"
# define KO "KO"
# define ERROR "Error"

typedef	struct s_stack	t_stack;

struct			s_stack
{
	int			num;
	t_stack		*next;
};

t_stack			*new_node(int val);
t_stack			*append(t_stack *end, t_stack *new);
void			print_stack(t_stack *start);
void			print_stacks(t_stack *stack_a, t_stack *stack_b);
void			free_stack(t_stack *start);
void			sort_3(t_stack **stack_a, t_stack **stack_b);
void			make_stack(int ac, char **av, t_stack **start);
void			print_do_op(char *s, t_stack **stack_a,
							t_stack **stack_b);
void			do_op(char *line, t_stack **stack_a, t_stack **stack_b);
void			op_sa(t_stack **start);
void			op_ra(t_stack **start);
void			op_rra(t_stack **start);
void			op_pb(t_stack **stack_a, t_stack **stack_b);
void			swap(t_stack **x, t_stack **y);
int				stack_len(t_stack **head);
int				found_dupes(int ac, char **av);
int				is_sorted(t_stack *start);
int				validate_input(int ac, char **av);

int				find_min(t_stack *stack);
int				find_max(t_stack *stack);
void			push_min_or_max_b(t_stack **a, t_stack **b, int repeat,
							int a_len);
void			push_max_a(t_stack **b, t_stack **a, int repeat);
int				find_position(t_stack *start, int n);

void			sort_4_or_5(t_stack **a, t_stack **b);

int				valid_input_string(char **av);
int				valid_input_int(int ac, char **av);
int				only_digits(char *str);
int				int_overflows(const char *str);
int				valid_input(int ac, char **av);
int				check_op(char *line);

void			sort(t_stack **a, t_stack **b, int len);
void			sort_20(t_stack **a, t_stack **b, int len);
void			push_max_a_r(t_stack **b, t_stack **a, int repeat);
int				find_min_or_max(t_stack *stack, int type);
int				find_position_r(t_stack *stack, int value);
int				list_length(t_stack **head);
int				contains_range(t_stack *stack, int range);
#endif
