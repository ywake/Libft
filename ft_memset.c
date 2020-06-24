/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ywake <ywake@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/24 11:54:04 by ywake             #+#    #+#             */
/*   Updated: 2020/06/24 14:02:10 by ywake            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*buf;
	unsigned char	in;

	buf = (unsigned char *)b;
	in = c;
	i = 0;
	while (i < len)
	{
		buf[i] = in;
		i++;
	}
	return ((void *)buf);
}
