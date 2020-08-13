/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alborz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 18:24:16 by alborz            #+#    #+#             */
/*   Updated: 2020/08/13 18:24:16 by alborz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Always call memmove with len multiplied by the size of
** `each element eg memmove(dst, src, len * sizeof(elem_type)
*/

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*dst1;
	unsigned char const	*src1;

	if (dst == src)
		return (dst);
	dst1 = (unsigned char *)dst;
	src1 = (unsigned const char *)src;
	if (src <= dst)
	{
		dst1 = dst1 + (len - 1);
		src1 = src1 + (len - 1);
		while (len--)
			*dst1-- = *src1--;
	}
	else
		ft_memcpy(dst, src, len);
	return (dst);
}
