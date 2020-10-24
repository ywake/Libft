/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_x.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ywake <ywake@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/18 03:22:37 by ywake             #+#    #+#             */
/*   Updated: 2020/07/27 19:14:12 by ywake            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static char	*utox(unsigned int num, char *charset)
{
	unsigned int	t;
	int				digit;
	int				base;
	char			*buf;

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

void		print_hex(char *str, t_info *info, size_t *len, char tag)
{
	char	*field;

	if (str[0] == '0' && info->flag & IS_PRECISION && info->precision == 0)
		field = ft_strdup("");
	else
		field = proc_precision_num(info, str);
	if (tag == 'p' || (tag && (str[0] != '0')))
		free_set(&field, ft_strjoin((tag == 'X') ? "0X" : "0x", field));
	info->flag &= ~IS_PRECISION;
	print_s(field, info, len);
	free(field);
}

void		print_x(unsigned int num, t_info *info, size_t *len, char islower)
{
	char	*str;

	if (islower)
		str = utox(num, "0123456789abcdef");
	else
		str = utox(num, "0123456789ABCDEF");
	if (info->flag & FLAG_HASH)
		if (islower)
			print_hex(str, info, len, 'x');
		else
			print_hex(str, info, len, 'X');
	else
		print_hex(str, info, len, 0);
	free(str);
}
