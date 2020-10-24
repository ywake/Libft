/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ywake <ywake@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/15 16:43:48 by ywake             #+#    #+#             */
/*   Updated: 2020/09/19 23:12:20 by ywake            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

char	*put_var_bonus(const char *str, t_info *info, va_list list, size_t *len)
{
	(void)list;
	(void)len;
	if (*str == 'n')
		print_n(va_arg(list, int*), info, len);
	free(info);
	if (*str != '\0' && ft_strchr("n", *str))
		return ((char *)++str);
	return ((char *)str);
}

char	*put_var(const char *str, va_list list, size_t *len)
{
	t_info	*info;

	info = (t_info *)ft_calloc(1, sizeof(t_info));
	str = get_info(str, info, list);
	if (*str == '%')
		print_c('%', info, len);
	else if (*str == 'c')
		print_c(va_arg(list, int), info, len);
	else if (*str == 's')
		print_s(va_arg(list, char*), info, len);
	else if (*str == 'd' || *str == 'i')
		print_d(va_arg(list, int), info, len);
	else if (*str == 'p')
		print_p((size_t)va_arg(list, void*), info, len);
	else if (*str == 'u')
		print_u(va_arg(list, unsigned int), info, len);
	else if (*str == 'x' || *str == 'X')
		print_x(va_arg(list, unsigned int), info, len, *str & 0x20);
	if (*str != '\0' && ft_strchr("%csdipuxX", *str))
	{
		free(info);
		return ((char *)++str);
	}
	return (put_var_bonus(str, info, list, len));
}

int		ft_printf(const char *s, ...)
{
	va_list	list;
	size_t	len;

	len = 0;
	va_start(list, s);
	while (*s)
	{
		if (*s == '%')
			s = put_var(++s, list, &len);
		else
		{
			ft_putchar_fd(*s++, 1);
			len++;
		}
	}
	va_end(list);
	return (len);
}
