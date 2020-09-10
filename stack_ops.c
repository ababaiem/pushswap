/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_ops.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alborz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 21:04:26 by alborz            #+#    #+#             */
/*   Updated: 2020/09/10 17:43:36 by ababaie-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"
#include <stdio.h>

void		make_stack(int ac, char **av, t_stack **start)
{
	t_stack	*new;
	t_stack	*end;
	int	i;

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

void	do_op(char *line, t_stack **stack_a, t_stack **stack_b)
{
	if (line[0] == 's' && line[1] == 'a')
		op_sa(stack_a);
	else if (line[0] == 's' && line[1] == 'b')
		op_sa(stack_b);
	else if (line[0] == 's' && line[1] == 's')
	{
		op_sa(stack_a);
		op_sa(stack_b);
	}
	else if (line[0] == 'r' && line[1] == 'a')
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
	else if (line[0] == 'p' && line[1] == 'b')
		op_pb(stack_a, stack_b);
	else if (line[0] == 'p' && line[1] == 'a')
		op_pb(stack_b, stack_a);
}

void	op_sa(t_stack **start)
{
	t_stack *ptr;

	if (*start == NULL || (*start)->next == NULL)
		return ;
	ptr = (*start)->next;
	swap(&ptr, start);
}

void	op_ra(t_stack **start)
{
	t_stack	*ptr;
	int	tmp;

	if (*start == NULL || (*start)->next == NULL)
		return ;
	ptr = *start;
	tmp = ptr->num;
	ptr = ptr->next;
	free(*start);
	*start = ptr;
	while (ptr->next != NULL)
		ptr = ptr->next;
	ptr->next = new_node(tmp);
}

void	op_rra(t_stack **start)
{
	t_stack	*ptr;
	t_stack *ptr1;
	int	tmp;

	if (*start == NULL || (*start)->next == NULL)
		return ;
	ptr = *start;
	while (ptr->next->next != NULL)
		ptr = ptr->next;
	tmp = ptr->next->num;
	ptr1 = ptr->next;
	ptr->next = NULL;
	free(ptr1);
	ptr = *start;
	*start = new_node(tmp);
	(*start)->next = ptr;
}

void	op_pb(t_stack **stack_a, t_stack **stack_b)
{
	t_stack *ptra;
	t_stack *ptrb;

	if (*stack_a == NULL)
		return ;
	ptra = *stack_a;
	ptrb = new_node(ptra->num);
	if (*stack_b == NULL)
		*stack_b = ptrb;
	else
	{
		ptrb->next = *stack_b;
		*stack_b = ptrb;
	}
	if (stack_len(stack_a) == 1)
	{
		free(*stack_a);
		*stack_a = NULL;
	}
	else
	{
		ptra = ptra->next;
		free(*stack_a);
		*stack_a = ptra;
	}
}

void	swap(t_stack **x, t_stack **y)
{
	int tmp;

	tmp = (*x)->num;
	(*x)->num = (*y)->num;
	(*y)->num = tmp;
}

void	print_do_op(char *s, t_stack **stack_a, t_stack **stack_b)
{
	ft_putendl(s);
	do_op(s, stack_a, stack_b);
}
