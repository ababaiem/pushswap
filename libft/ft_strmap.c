/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alborz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 18:27:48 by alborz            #+#    #+#             */
/*   Updated: 2020/08/13 18:27:48 by alborz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*freshstr;
	int		i;

	i = 0;
	if (!s || !f)
		return (NULL);
	freshstr = ft_strnew(ft_strlen(s));
	if (!freshstr)
		return (NULL);
	while (s[i] != '\0')
	{
		freshstr[i] = (*f)(s[i]);
		i++;
	}
	return (freshstr);
}
