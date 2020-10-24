/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ywake <ywake@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/18 02:36:30 by ywake             #+#    #+#             */
/*   Updated: 2020/10/23 02:30:29 by ywake            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

void	flag_up(t_info *info, char flag)
{
	if (flag == ZERO_PADDING && info->flag & LEFT_JUSTIFIED)
		return ;
	if (flag == FLAG_SPACE && info->flag & FLAG_PLUS)
		return ;
	info->flag |= flag;
	if (flag == LEFT_JUSTIFIED)
		info->flag &= ~ZERO_PADDING;
	if (flag == FLAG_PLUS)
		info->flag &= ~FLAG_SPACE;
}

void	get_flag(const char *str, char *start, t_info *info, va_list list)
{
	int	index;

	while (str < start)
		if (*str++ == '*')
			va_arg(list, int);
	while ((index = ft_strchr_i(FLAG_CHARS, *str)) > -1 && *str++)
		flag_up(info, 1 << index);
	if (ft_isdigit(*str))
		while (ft_isdigit(*str))
			info->width = info->width * 10 + (*str++ - '0');
	else if (*str == '*' && str++)
		if ((info->width = va_arg(list, int)) < 0)
			flag_up(info, LEFT_JUSTIFIED);
	info->width = abs(info->width);
	if (*str == '.')
	{
		flag_up(info, IS_PRECISION);
		if (ft_isdigit(*++str))
			while (ft_isdigit(*str))
				info->precision = info->precision * 10 + (*str++ - '0');
		else if (*str == '*' && str++)
			info->precision = va_arg(list, int);
	}
}

char	*get_info(const char *str, t_info *info, va_list list)
{
	int		flaglen;
	int		start;

	flaglen = 0;
	while (str[flaglen] && ft_strchr("-0 #+.*123456789", str[flaglen]))
		flaglen++;
	start = flaglen;
	if (start > 0 && ft_isdigit(str[start - 1]))
		while (start > 0 && ft_isdigit(str[start - 1]))
			start--;
	else if (start > 0 && str[start - 1] == '*')
		start--;
	if (start > 0 && str[start - 1] == '.')
	{
		start--;
		if (start > 0 && ft_isdigit(str[start - 1]))
			while (start > 0 && ft_isdigit(str[start - 1]))
				start--;
		else if (start > 0 && str[start - 1] == '*')
			start--;
	}
	while (start > 0 && ft_strchr(FLAG_CHARS, str[start - 1]))
		start--;
	get_flag(str, (char *)str + start, info, list);
	return ((char *)str + flaglen);
}

char	*make_field(t_info *info, size_t len)
{
	char	*rtn;

	info->width = (info->width > (int)len) ? info->width : (int)len;
	rtn = (char *)ft_calloc((info->width + 1), sizeof(char));
	if (info->flag & ZERO_PADDING)
		ft_memset(rtn, '0', info->width);
	else
		ft_memset(rtn, ' ', info->width);
	return (rtn);
}
