/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alborz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 18:23:23 by alborz            #+#    #+#             */
/*   Updated: 2020/08/13 18:23:23 by alborz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	if ((*alst)->next)
		ft_lstdel(&(*alst)->next, del);
	ft_lstdelone(&(*alst), del);
}
/*
**void    freefunct(void *d, size_t s)
**{
**    free(d);
**    (void)s;
**}
**
**int        main(void)
**{
**    t_list    *begin;
**    size_t    v;
**
**    v = 1;
**    begin = ft_lstnew(&v, sizeof(void *));
**    begin->next = ft_lstnew(&v, sizeof(void *));
**    begin->next->next = ft_lstnew(&v, sizeof(void *));
**    ft_lstdel(&begin, freefunct);
**    if (begin != NULL)
**    {
**        write(1, "Didn't work\n", 16);
**        return (0);
**    }
**    write(1, "Success\n", 9);
**    return (0);
**}
*/
