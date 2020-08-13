/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alborz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 18:23:58 by alborz            #+#    #+#             */
/*   Updated: 2020/08/13 18:23:58 by alborz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char		*dst1;
	unsigned char const *src1;

	dst1 = (unsigned char *)dst;
	src1 = (unsigned char const *)src;
	while (n > 0)
	{
		if ((*dst1++ = *src1++) == (unsigned char)c)
			return (dst1++);
		n--;
	}
	return (NULL);
}
