/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alborz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 18:23:18 by alborz            #+#    #+#             */
/*   Updated: 2020/08/13 18:23:18 by alborz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd(t_list **alst, t_list *new)
{
	new->next = *alst;
	*alst = new;
}
/*
**int        main(void)
**{
**    t_list    *begin;
**    t_list    *add;
**    t_list    *tmp;
**    size_t    v;
**
**    v = 1;
**    begin = ft_lstnew(&v, sizeof(size_t));
**    tmp = begin;
**    add = ft_lstnew(&v, sizeof(size_t));
**    ft_lstadd(&begin, add);
**    if (begin != add)
**    {
**        write(1, "Didn't work\n", 16);
**        return (0);
**    }
**    if (begin->next != tmp)
**    {
**        write(1, "Didn't work\n", 16);
**        return (0);
**    }
**    free(begin->next);
**    free(begin);
**    write(1, "Success\n", 9);
**    return (0);
**}
*/
