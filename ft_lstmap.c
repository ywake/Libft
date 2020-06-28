/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ywake <ywake@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/29 03:38:59 by ywake             #+#    #+#             */
/*   Updated: 2020/06/29 04:11:54 by ywake            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list *elem;
	t_list *next;

	if (lst == NULL || f == NULL)
		return (NULL);
	next = ft_lstmap(lst->next, f, del);
	elem = ft_lstnew(f(lst->content));
	ft_lstadd_front(&next, elem);
	return (elem);
}
