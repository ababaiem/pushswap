/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_20.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alborz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/10 19:53:27 by alborz            #+#    #+#             */
/*   Updated: 2020/09/10 19:59:06 by ababaie-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

static int	get_inc(t_stack **a, int len)
{
	int inc;

	if (len >= 20 && len <= 100)
	{
		inc = find_max(*a) / 6;
	}
	else
	{
		if (find_max(*a) == len)
			inc = 36;
		else
			inc = find_max(*a) / 15;
	}
	return (inc);
}

void		sort_20(t_stack **a, t_stack **b, int len)
{
	int	range;
	int	i;
	int	inc;

	range = find_min(*a);
	inc = get_inc(a, len);
	i = 1;
	while (*a)
	{
		range += inc;
		while (contains_range(*a, range))
		{
			if (!(*a))
				break ;
			if ((*a)->num <= range)
			{
				print_do_op(PB, a, b);
				i++;
			}
			else
				print_do_op(RA, a, b);
		}
	}
	i--;
	push_max_a_r(b, a, i);
}
