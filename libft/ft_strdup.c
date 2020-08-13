/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alborz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 18:26:33 by alborz            #+#    #+#             */
/*   Updated: 2020/08/13 18:26:33 by alborz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	len;
	char	*dup;

	len = ft_strlen(s1);
	dup = ft_strnew(len);
	if (!dup)
		return (NULL);
	dup = (char *)ft_memcpy(dup, s1, len);
	dup[len] = '\0';
	return (dup);
}
