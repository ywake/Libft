/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ywake <ywake@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/27 17:25:26 by ywake             #+#    #+#             */
/*   Updated: 2022/02/27 12:27:34 by ywake            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**free_all(char **buf)
{
	size_t	i;

	i = 0;
	while (buf[i])
	{
		free(buf[i]);
		buf[i] = NULL;
		i++;
	}
	free(buf);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char		**buf;
	const char	*ptr;
	size_t		i;

	if (s == NULL)
		return (NULL);
	ptr = s;
	i = 1;
	while (*ptr)
		if (*ptr++ != c && (*ptr == c || *ptr == '\0'))
			i++;
	buf = (char **)ft_calloc(i, sizeof(char *));
	i = 0;
	while (s != NULL && *s != '\0' && buf != NULL)
	{
		ptr = ft_strchr(s, c);
		if (ptr == NULL)
			buf[i] = ft_strdup(s);
		else if (ptr != s)
			buf[i] = ft_substr(s, 0, ptr - s);
		if (ptr != s && buf[i++] == NULL)
			buf = free_all(buf);
		s = ptr + (ptr != NULL);
	}
	return (buf);
}
