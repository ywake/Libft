/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ywake <ywake@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/24 10:16:08 by ywake             #+#    #+#             */
/*   Updated: 2020/06/24 11:48:54 by ywake            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	needle_len;
	char	*find;

	needle_len = ft_strlen(needle);
	if (needle_len == 0)
		return ((char *)haystack);
	i = 0;
	while (haystack[i] && i + needle_len <= len)
	{
		find = ft_strchr(&haystack[i], needle[0]);
		if (find - haystack + needle_len > (unsigned long)len)
			break ;
		if (ft_strncmp(find, needle, needle_len) == 0)
			return (find);
		i = find - haystack + 1;
	}
	return (NULL);
}
