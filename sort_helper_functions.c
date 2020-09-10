/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_helper_functions.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alborz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 20:58:46 by alborz            #+#    #+#             */
/*   Updated: 2020/09/10 17:48:08 by ababaie-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

int	find_min(t_stack *stack)
{
	int min;

	min = stack->num;
	while (stack)
	{
		if (min > stack->num)
			min = stack->num;
		stack = stack->next;
	}
	return (min);
}

int	find_max(t_stack *stack)
{
	int max;

	max = stack->num;
	while (stack)
	{
		if (max < stack->num)
			max = stack->num;
		stack = stack->next;
	}
	return (max);
}

int	find_position(t_stack *start, int n)
{
	int pos;

	pos = 0;
	while (start)
	{
		if (n == start->num)
			return (pos);
		start = start->next;
		pos++;
	}
	return (pos);
}

void	push_min_or_max_b(t_stack **a, t_stack **b, int repeat, int a_len)
{
	int i;
	int min;
	int max;

	i = 0;
	min = find_min(*a);
	max = find_max(*a);
	while (i < repeat)
	{
		if (find_position(*a, min) == 0 || find_position(*a, max) == 0)
		{
			print_do_op(PB, a, b);
			i++;
		}
		else if (find_position(*a, min) > a_len / 2 ||
		find_position(*a, max) > a_len / 2)
			print_do_op(RRA, a, b);
		else if (find_position(*a, min) < a_len / 2 ||
		find_position(*a, max) < a_len / 2)
			print_do_op(RA, a, b);
	}
}

void	push_max_a(t_stack **b, t_stack **a, int repeat)
{
	int i;
	int max;

	i = 0;
	max = find_max(*b);
	while (i < repeat)
	{
		if (find_position(*b, max) == 1)
		{
			print_do_op(PA, a, b);
			i++;
			if (*b)
				max = find_max(*b);
		}
		else if (find_position(*b, max) > stack_len(b) / 2)
			print_do_op(RRB, a, b);
		else if (find_position(*b, max) <= stack_len(b) / 2)
			print_do_op(RB, a, b);
	}
}

int	contains_range(t_stack *stack, int range)
{
	while (stack)
	{
		if (stack->num <= range)
			return (1);
		stack = stack->next;
	}
	return (0);
}

void	push_max_a_r(t_stack **b, t_stack **a, int repeat)
{
	int i;
	int max;

	i = 0;
	max = find_min_or_max(*b, 1);
	while (i < repeat)
	{
		if (find_position_r(*b, max) == 1)
		{
			print_do_op(PA, a, b);
			i++;
			if (*b)
				max = find_min_or_max(*b, 1);
		}
		else if (find_position_r(*b, max) > list_length(b) / 2)
			print_do_op(RRB, a, b);
		else if (find_position_r(*b, max) <= list_length(b) / 2)
			print_do_op(RB, a, b);
	}
}

int	find_min_or_max(t_stack *stack, int type)
{
	int min_or_max;

	min_or_max = stack->num;
	if (type == 0)
	{
		while (stack)
		{
			if (min_or_max > stack->num)
				min_or_max = stack->num;
			stack = stack->next;
		}
	}
	else if (type == 1)
	{
		while (stack)
		{
			if (min_or_max < stack->num)
				min_or_max = stack->num;
			stack = stack->next;
		}
	}
	return (min_or_max);
}

int	find_position_r(t_stack *stack, int value)
{
	int position;

	position = 1;
	while (stack)
	{
		if (stack->num == value)
		{
			return (position);
		}
		stack = stack->next;
		position++;
	}
	return (0);
}

int	list_length(t_stack **head)
{
	t_stack *tmp;
	int		cnt;

	cnt = 0;
	tmp = *head;
	while (tmp != NULL)
	{
		tmp = tmp->next;
		cnt++;
	}
	return (cnt);
}
