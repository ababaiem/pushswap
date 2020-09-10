/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababaie- <ababaie-@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 20:09:00 by ababaie-          #+#    #+#             */
/*   Updated: 2020/09/10 17:31:46 by ababaie-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"
#include <stdio.h>

static void	free_stacks(t_stack *stack_a, t_stack *stack_b)
{
	free_stack(stack_a);
	free_stack(stack_b);
}

static int	checker(t_stack *stack_a, t_stack *stack_b)
{
	int	bad_op;
	char	*line;

	bad_op = 0;
	while (get_next_line(0, &line) == 1)
	{
		if (!check_op(line))
		{
			ft_putendl(ERROR);
			free_stacks(stack_a, stack_b);
			free(line);
			return (0);
		}
		do_op(line, &stack_a, &stack_b);
		free(line);
	}
	if (!bad_op)
		ft_putendl((is_sorted(stack_a) && stack_b == NULL) ? OK : KO);
	else
		ft_putendl(ERROR);
	free_stacks(stack_a, stack_b);
	return (1);
}

int	main(int ac, char **av)
{
	t_stack *stack_a;
	t_stack *stack_b;

	if (ac < 3)
		return (0);
	if (valid_input(ac, av))
	{
		stack_a = NULL;
		stack_b = NULL;
		make_stack(ac, av, &stack_a);
		if (!checker(stack_a, stack_b))
			return (0);
	}
	else
	{
		ft_putendl(ERROR);
		return (0);
	}
	return (1);
}
