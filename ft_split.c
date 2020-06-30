/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ywake <ywake@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/27 17:25:26 by ywake             #+#    #+#             */
/*   Updated: 2020/06/30 13:53:30 by ywake            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static char	**free_all(char **buf)
{
	size_t i;

	i = 0;
	while (buf[i])
	{
		free(buf[i]);
		i++;
	}
	free(buf);
	buf = NULL;
	return (buf);
}

char		**ft_split(char const *s, char c)
{
	char	**buf;
	char	*tmp;
	size_t	i;
	size_t	len;

	tmp = (char *)s;
	i = 1;
	while (*tmp)
		if (*tmp++ != c && (*tmp == c || *tmp == '\0'))
			i++;
	buf = (char **)ft_calloc(i, sizeof(char *));
	i = 0;
	while (buf != NULL && (tmp = ft_strchr(s, c)))
	{
		if ((len = tmp - s) > 0)
			if ((buf[i++] = ft_substr(s, 0, len)) == NULL)
				buf = free_all(buf);
		s += len + 1;
	}
	if (buf != NULL && (*s != '\0'))
		buf[i] = ft_substr(s, 0, ft_strlen(s));
	return (buf);
}
