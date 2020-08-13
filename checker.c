/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababaie- <ababaie-@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 20:09:00 by ababaie-          #+#    #+#             */
/*   Updated: 2020/08/14 00:23:17 by ababaie-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"
#include <stdio.h>
/*
int	checker(t_stack *stack_a, t_stack *b, int ac, char **av)
{
}
*/

int	main(int ac, char **av)
{
	if (ac < 3)
		return 0;
	if (valid_input(ac, av))
	{
		t_stack *stack_a = NULL;
		t_stack *stack_b = NULL;
		make_stack(ac, av, &stack_a);

		int bad_op = 0;
		char *line;
		int fd = 0;
		int r;
		if ((r = get_next_line(fd, &line)))
		{
		    while (r == 1)
		    {
			if (!check_op(line))
			{
			    ft_putendl(ERROR);
			    free_stack(stack_a);
			    free_stack(stack_b);
			    free(line);
			    return (0);
			}
			do_op(line, &stack_a, &stack_b);
			free(line);
			r = (get_next_line(fd, &line));
		    }
		}
		if (!bad_op)
		{
			if(is_sorted(stack_a) && stack_b == NULL)
				ft_putendl(OK);
			else
			    ft_putendl(KO);
		}
		else
			ft_putendl(ERROR);
		free_stack(stack_a);
		free_stack(stack_b);

	}
	else
	{
		ft_putendl(ERROR);
		return (0);
	}
	return (1);
}
