/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alborz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 18:28:36 by alborz            #+#    #+#             */
/*   Updated: 2020/08/13 18:28:36 by alborz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t i;

	i = 0;
	while (s1[i] == s2[i] && i < n)
	{
		i++;
		if (s1[i] == '\0' && s2[i] == '\0')
			return (0);
	}
	if (i == n)
		return (0);
	return (*((unsigned char *)s1 + i) < *((unsigned char *)s2 + i) ? -1 : 1);
}
