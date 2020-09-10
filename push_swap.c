/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababaie- <ababaie-@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 19:35:09 by ababaie-          #+#    #+#             */
/*   Updated: 2020/09/10 15:53:46 by ababaie-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/uio.h>

int	main(int ac, char **av)
{
	t_stack *stack_a;
	t_stack *stack_b;

	if (ac < 3)
		return (0);
	if (validate_input(ac, av))
	{
		stack_a = NULL;
		stack_b = NULL;
		make_stack(ac, av, &stack_a);
		sort(&stack_a, &stack_b, ac - 1);
		free_stack(stack_a);
		free_stack(stack_b);
	}
	return (1);
}
