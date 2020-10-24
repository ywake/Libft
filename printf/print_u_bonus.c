/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_u.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ywake <ywake@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/18 03:22:37 by ywake             #+#    #+#             */
/*   Updated: 2020/07/23 02:39:30 by ywake            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static char	*ft_itoa_u(unsigned int n)
{
	unsigned int	t;
	int				digit;
	char			*buf;

	digit = 1;
	t = n;
	while (t /= 10)
		digit++;
	buf = (char *)ft_calloc(digit + 1, sizeof(char));
	if (buf == NULL)
		return (NULL);
	while (digit > 0)
	{
		buf[--digit] = n % 10 + '0';
		n /= 10;
	}
	return (buf);
}

void		print_u(unsigned int num, t_info *info, size_t *len)
{
	char	*str;

	str = ft_itoa_u(num);
	print_num(str, info, len);
	free(str);
}
