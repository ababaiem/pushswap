/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_pop.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alborz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 20:39:02 by alborz            #+#    #+#             */
/*   Updated: 2020/09/10 17:53:15 by ababaie-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

t_stack	*new_node(int val)
{
	t_stack *stack;

	stack = (t_stack*)malloc(sizeof(t_stack));
	(stack)->num = val;
	(stack)->next = NULL;
	return (stack);
}

t_stack	*append(t_stack *end, t_stack *new)
{
	end->next = new;
	return (end->next);
}

void		print_stack(t_stack *start)
{
	t_stack *ptr;

	ptr = start;
	while (ptr != NULL)
	{
		ft_putnbr(ptr->num);
		ft_putchar('\n');
		ptr = ptr->next;
	}
	ft_putchar('\n');
}

void		print_stacks(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a)
		print_stack(stack_a);
	if (stack_b)
		print_stack(stack_b);
}

void		free_stack(t_stack *start)
{
	t_stack *ptr;

	ptr = start;
	while (ptr != NULL)
	{
		start = ptr;
		ptr = ptr->next;
		free(start);
	}
}

int		stack_len(t_stack **head)
{
	t_stack	*ptr;
	int	len;
	
	len = 0;
	if (*head != NULL)
	{
		len = 1;
		ptr = *head;
		while (ptr->next != NULL)
		{
			len++;
			ptr = ptr->next;
		}
	}
	return (len);
}

int		is_sorted(t_stack *start)
{
	t_stack *ptr;

	ptr = start;
	while (ptr->next != NULL)
	{
		if (ptr->num > ptr->next->num)
			return (0);
		ptr = ptr->next;
	}
	return (1);
}
