/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alborz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 18:29:30 by alborz            #+#    #+#             */
/*   Updated: 2020/08/13 18:29:30 by alborz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char *freshstr;

	freshstr = ft_strnew(len);
	if (!freshstr || !s || !*(s + start))
		return (0);
	freshstr = (char *)ft_memmove(freshstr, (s + start), len);
	return (freshstr);
}
