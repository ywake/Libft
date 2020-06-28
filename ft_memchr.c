/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ywake <ywake@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/24 17:40:47 by ywake             #+#    #+#             */
/*   Updated: 2020/06/29 04:22:39 by ywake            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;
	char	*csrc;

	csrc = (char *)s;
	i = 0;
	while (i < n)
	{
		if (csrc[i] == c)
			return ((void *)&csrc[i]);
		i++;
	}
	return (NULL);
}
