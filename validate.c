/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alborz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 21:14:36 by alborz            #+#    #+#             */
/*   Updated: 2020/09/11 12:54:12 by ababaie-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

int	valid_input_string(char **av)
{
	static char	**arr;
	int			i;

	arr = ft_strsplit(av[1], ' ');
	i = 0;
	if (!only_digits(av[1]))
		return (0);
	while (arr[i])
	{
		if (int_overflows(arr[i]))
			return (0);
		i++;
	}
	return (1);
}

int	valid_input_int(int ac, char **av)
{
	int i;

	i = 1;
	while (av[i])
	{
		if (int_overflows(av[i]))
			return (0);
		if (!only_digits(av[i]))
			return (0);
		i++;
	}
	if (found_dupes(ac, av))
		return (0);
	return (1);
}

int	validate_input(int ac, char **av)
{
	int ret;

	ret = 0;
	if (ac < 3 || found_dupes(ac, av))
		return (ret);
	ret = 1;
	return (ret);
}

int	valid_input(int ac, char **av)
{
	if (ac == 2)
	{
		if (!valid_input_string(av))
			return (0);
	}
	else if (ac > 2)
	{
		if (!valid_input_int(ac, av))
			return (0);
	}
	return (1);
}
