/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ywake <ywake@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/27 07:48:12 by ywake             #+#    #+#             */
/*   Updated: 2020/06/27 08:01:13 by ywake            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	bufsize;
	char	*buf;

	bufsize = ft_strlen(s1) + ft_strlen(s2) + 1;
	buf = (char *)ft_calloc(bufsize, sizeof(char));
	if (buf == NULL)
		return (NULL);
	ft_strlcpy(buf, s1, bufsize);
	ft_strlcat(buf, s2, bufsize);
	return (buf);
}
