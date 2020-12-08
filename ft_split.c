/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ywake <ywake@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/27 17:25:26 by ywake             #+#    #+#             */
/*   Updated: 2020/12/09 03:32:30 by ywake            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**free_all(char **buf)
{
	size_t i;

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

char		**ft_split(char const *s, char c)
{
	char		**buf;
	const char	*ptr;
	size_t		i;
	size_t		len;

	if ((ptr = s) == NULL)
		return (NULL);
	i = 1;
	while (*ptr)
		if (*ptr++ != c && (*ptr == c || *ptr == '\0'))
			i++;
	if (!(buf = (char **)malloc(sizeof(char *) * i)))
		return (NULL);
	i = 0;
	while (buf != NULL && *s)
	{
		if ((ptr = ft_strchr(s, c)) == NULL)
			ptr = s + ft_strlen(s);
		if ((len = ptr - s) > 0)
			if ((buf[i++] = ft_substr(s, 0, len)) == NULL)
				buf = free_all(buf);
		s += (s[len] == '\0') ? len : len + 1;
	}
	buf[i] = NULL;
	return (buf);
}
