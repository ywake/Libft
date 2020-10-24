/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ywake <ywake@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/18 03:22:37 by ywake             #+#    #+#             */
/*   Updated: 2020/07/27 19:05:13 by ywake            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

char	*proc_precision_num(t_info *info, char *str)
{
	char	*field;
	int		i;
	int		strlen;
	int		size;
	char	flg;

	if (info->flag & IS_PRECISION)
		info->flag &= ~ZERO_PADDING;
	if (str[0] == '-')
		flag_up(info, FLAG_PLUS);
	flg = ft_strchr("+- ", str[0]) != NULL;
	strlen = ft_strlen(str) - flg;
	info->precision = max(info->precision, strlen);
	size = info->precision + flg + 1;
	field = (char *)ft_calloc(size, sizeof(char));
	i = 0;
	if (flg)
		field[i++] = str[0];
	while (info->precision-- > strlen)
		field[i++] = '0';
	ft_strlcat(field, str + flg, size);
	return (field);
}

void	print_num(char *str, t_info *info, size_t *len)
{
	char	*field;
	int		i;
	int		strlen;

	if (str[0] == '0' && info->flag & IS_PRECISION && info->precision == 0)
		field = ft_strdup("");
	else
		field = proc_precision_num(info, str);
	if (str[0] == '0' && info->flag & (FLAG_PLUS | FLAG_SPACE))
		free_set(&field, ft_strjoin((info->flag & 0b1000) ? " " : "+", field));
	info->flag &= ~IS_PRECISION;
	if (!ft_strchr("+- ", field[0]) || !(info->flag & ZERO_PADDING))
		print_s(field, info, len);
	else
	{
		put_char_count(field[0], len);
		i = 1;
		strlen = ft_strlen(field);
		while (info->width-- > strlen)
			put_char_count('0', len);
		while (field[i])
			put_char_count(field[i++], len);
	}
	free(field);
}

void	print_d(int num, t_info *info, size_t *len)
{
	char	*str;

	str = ft_itoa(num);
	if (num > 0)
	{
		if (info->flag & FLAG_PLUS)
			free_set(&str, ft_strjoin("+", str));
		else if (info->flag & FLAG_SPACE)
			free_set(&str, ft_strjoin(" ", str));
	}
	print_num(str, info, len);
	free(str);
}
