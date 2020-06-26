/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ywake <ywake@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/27 03:06:33 by ywake             #+#    #+#             */
/*   Updated: 2020/06/27 04:57:24 by ywake            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	pow10(int n)
{
	int rtn;

	rtn = 1;
	while (n-- > 0)
		rtn *= 10;
	return (rtn);
}

static int	str_to_int(char *str, int len)
{
	int	rtn;

	rtn = 0;
	while (len > 0)
		rtn += (*str++ - '0') * pow10(--len);
	return (rtn);
}

int			ft_atoi(const char *str)
{
	char	*src;
	int		rtn;
	int		len;

	src = (char *)str;
	rtn = 1;
	while (ft_isspace(*src))
		src++;
	if (*src == '+' || *src == '-')
		rtn = 44 - *src++;
	len = 0;
	while (ft_isdigit(src[len]))
		len++;
	rtn *= str_to_int(src, len);
	return (rtn);
}