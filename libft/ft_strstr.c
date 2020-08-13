/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alborz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 18:29:23 by alborz            #+#    #+#             */
/*   Updated: 2020/08/13 18:29:23 by alborz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t	i;
	size_t	p;

	i = 0;
	p = 0;
	if (!*needle)
		return ((char *)haystack);
	while (haystack[i] != '\0')
	{
		if (haystack[i] == needle[p])
		{
			while (needle[p] == haystack[i] && needle[p] != '\0')
			{
				i++;
				p++;
				if (p == ft_strlen(needle))
					return ((char *)&haystack[i - p]);
			}
			i = i - p;
			p = 0;
		}
		i++;
	}
	return (NULL);
}
