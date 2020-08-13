/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alborz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 18:24:10 by alborz            #+#    #+#             */
/*   Updated: 2020/08/13 18:24:10 by alborz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t		i;
	char		*dst1;
	char const	*src1;

	i = -1;
	dst1 = (char *)dst;
	src1 = (char const *)src;
	if (n == 0 || dst == src)
		return (dst);
	while (++i < n)
		dst1[i] = src1[i];
	return (dst);
}
