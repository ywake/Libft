/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ywake <ywake@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/18 03:22:37 by ywake             #+#    #+#             */
/*   Updated: 2020/07/27 19:11:24 by ywake            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static char	*ultox(size_t num, char *charset)
{
	size_t	t;
	int		digit;
	int		base;
	char	*buf;

	base = 16;
	digit = 1;
	t = num;
	while (t /= base)
		digit++;
	buf = (char *)ft_calloc(digit + 1, sizeof(char));
	if (buf == NULL)
		return (NULL);
	while (digit > 0)
	{
		buf[--digit] = charset[num % base];
		num /= base;
	}
	return (buf);
}

void		print_p(size_t num, t_info *info, size_t *len)
{
	char	*str;

	str = ultox(num, "0123456789abcdef");
	print_hex(str, info, len, 'p');
	free(str);
}
