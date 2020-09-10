/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alborz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/10 17:57:31 by alborz            #+#    #+#             */
/*   Updated: 2020/09/10 18:08:56 by alborz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"
#include <stdio.h>

void		make_stack(int ac, char **av, t_stack **start)
{
	int		i;
	t_stack	*new;
	t_stack	*end;

	new = NULL;
	new = new_node(ft_atoi(av[1]));
	end = new;
	*start = end;
	i = 2;
	while (i < ac)
	{
		new = new_node(ft_atoi(av[i]));
		end = append(end, new);
		i++;
	}
}

static void	do_op_bis(char *line, t_stack **stack_a, t_stack **stack_b)
{
	if (line[0] == 'r' && line[1] == 'a')
		op_ra(stack_a);
	else if (line[0] == 'r' && line[1] == 'b')
		op_ra(stack_b);
	else if (line[0] == 'r' && line[1] == 'r' && line[2] == 'a')
		op_rra(stack_a);
	else if (line[0] == 'r' && line[1] == 'r' && line[2] == 'b')
		op_rra(stack_b);
	else if (line[0] == 'r' && line[1] == 'r' && line[2] == 'r')
	{
		op_rra(stack_a);
		op_rra(stack_b);
	}
	else if (line[0] == 'r' && line[1] == 'r')
	{
		op_ra(stack_a);
		op_ra(stack_b);
	}
}

void		do_op(char *line, t_stack **stack_a, t_stack **stack_b)
{
	if (line[0] == 'r')
		do_op_bis(line, stack_a, stack_b);
	else if (line[0] == 's' && line[1] == 'a')
		op_sa(stack_a);
	else if (line[0] == 's' && line[1] == 'b')
		op_sa(stack_b);
	else if (line[0] == 's' && line[1] == 's')
	{
		op_sa(stack_a);
		op_sa(stack_b);
	}
	else if (line[0] == 'p' && line[1] == 'b')
		op_pb(stack_a, stack_b);
	else if (line[0] == 'p' && line[1] == 'a')
		op_pb(stack_b, stack_a);
}

void		swap(t_stack **x, t_stack **y)
{
	int tmp;

	tmp = (*x)->num;
	(*x)->num = (*y)->num;
	(*y)->num = tmp;
}

void		print_do_op(char *s, t_stack **stack_a, t_stack **stack_b)
{
	ft_putendl(s);
	do_op(s, stack_a, stack_b);
}
