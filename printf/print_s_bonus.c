/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ywake <ywake@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/18 03:22:37 by ywake             #+#    #+#             */
/*   Updated: 2020/07/23 16:38:16 by ywake            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

char	*proc_precision(t_info *info, char *str)
{
	char	*rtn;

	if (!(info->flag & IS_PRECISION))
		info->precision = ft_strlen(str);
	rtn = ft_substr(str, 0, info->precision);
	return (rtn);
}

void	print_s(char *str, t_info *info, size_t *len)
{
	char	*field;
	int		i;

	if (str == NULL)
		str = "(null)";
	str = proc_precision(info, str);
	i = ft_strlen(str);
	field = make_field(info, i);
	if (info->flag & LEFT_JUSTIFIED)
		ft_memcpy(field, str, i);
	else
		ft_memcpy(&field[info->width - i], str, i);
	i = 0;
	while (i < info->width)
		put_char_count(field[i++], len);
	free(str);
	free(field);
}
