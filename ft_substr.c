/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ywake <ywake@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/27 06:24:49 by ywake             #+#    #+#             */
/*   Updated: 2020/06/27 07:05:39 by ywake            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*buf;
	size_t	bufsize;
	size_t	i;

	bufsize = 0;
	if (ft_strlen(s) > start)
		bufsize = ft_min(ft_strlen(s) - start, len);
	buf = (char *)ft_calloc(bufsize + 1, sizeof(char));
	if (buf == NULL)
		return (NULL);
	i = 0;
	while (s[start + i] && i < bufsize)
	{
		buf[i] = s[start + i];
		i++;
	}
	return (buf);
}
