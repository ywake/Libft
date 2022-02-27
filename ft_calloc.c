/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ywake <ywake@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/27 05:00:33 by ywake             #+#    #+#             */
/*   Updated: 2022/02/27 16:28:26 by ywake            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <limits.h>
#include <stdint.h>

void	*ft_calloc(size_t count, size_t size)
{
	void	*rtn;
	size_t	len;

	if (count != 0 && size > SIZE_MAX / count)
		return (NULL);
	len = size * count;
	if (len == 0)
		len = 1;
	rtn = (void *)malloc(len);
	if (rtn)
		ft_bzero(rtn, len);
	return (rtn);
}
