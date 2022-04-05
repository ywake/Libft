/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ywake <ywake@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/22 14:15:41 by ywake             #+#    #+#             */
/*   Updated: 2022/04/05 23:26:21 by ywake            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	make_magic(size_t byte)
{
	size_t	magic;
	size_t	i;

	i = 0;
	while (i < sizeof(size_t))
	{
		magic = (magic << 8) | byte;
		i++;
	}
	return (magic);
}

static int	has_nullbyte(size_t	longword)
{
	size_t			himagic;
	size_t			lomagic;

	himagic = make_magic(0x80L);
	lomagic = make_magic(0x01L);
	return (((longword - lomagic) & ~longword & himagic) != 0);
}

static const char	*ptr_of_nullbyte(const char *char_ptr)
{
	size_t	i;

	i = 0;
	while (i < sizeof(size_t))
	{
		if (char_ptr[i] == '\0')
			return (char_ptr + i);
		i++;
	}
	return (char_ptr);
}

/**
 * ref: https://jun-networks.hatenablog.com/entry/2020/12/29/134638
 */
size_t	ft_strlen(const char *str)
{
	const char		*ptr;
	const size_t	*long_ptr;

	ptr = str;
	while ((size_t)ptr & (sizeof(size_t) - 1))
	{
		if (*ptr == '\0')
			return (ptr - str);
		++ptr;
	}
	long_ptr = (size_t *)ptr;
	while (1)
	{
		if (has_nullbyte(*long_ptr))
			return (ptr_of_nullbyte((const char *)long_ptr) - str);
		long_ptr++;
	}
}
