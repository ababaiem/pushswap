/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_helper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alborz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/10 20:01:35 by alborz            #+#    #+#             */
/*   Updated: 2020/09/10 20:03:22 by alborz           ###   ########.fr       */
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

