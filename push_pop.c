/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_pop.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alborz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 20:39:02 by alborz            #+#    #+#             */
/*   Updated: 2020/09/10 20:13:47 by ababaie-         ###   ########.fr       */
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

int		stack_len(t_stack **head)
{
	int		len;
	t_stack	*ptr;

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
