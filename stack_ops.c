/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_ops.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alborz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 21:04:26 by alborz            #+#    #+#             */
/*   Updated: 2020/09/10 18:11:22 by ababaie-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"
#include <stdio.h>

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
	int		tmp;
	t_stack	*ptr;

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
	int		tmp;
	t_stack	*ptr;
	t_stack *ptr1;

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
