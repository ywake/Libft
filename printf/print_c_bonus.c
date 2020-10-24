/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_c.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ywake <ywake@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/17 14:32:23 by ywake             #+#    #+#             */
/*   Updated: 2020/07/22 20:16:28 by ywake            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

void	put_char_count(char c, size_t *len)
{
	ft_putchar_fd(c, 1);
	(*len)++;
}

void	print_c(char c, t_info *info, size_t *len)
{
	char	*field;
	int		i;

	field = make_field(info, 1);
	if (info->flag & LEFT_JUSTIFIED)
		field[0] = c;
	else
		field[info->width - 1] = c;
	i = 0;
	while (i < info->width)
		put_char_count(field[i++], len);
	free(field);
}
