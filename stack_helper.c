/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_helper.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alborz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/10 19:47:51 by alborz            #+#    #+#             */
/*   Updated: 2020/09/10 19:48:27 by alborz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

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
