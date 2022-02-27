/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ywake <ywake@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/27 03:06:33 by ywake             #+#    #+#             */
/*   Updated: 2022/02/27 14:27:07 by ywake            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	rsign;
	int	value;

	rsign = -1;
	value = 0;
	while (('\t' <= *str && *str <= '\r') || *str == ' ')
		str++;
	if (*str == '+' || *str == '-')
		rsign = -(',' - *str++);
	while (*str && '0' <= *str && *str <= '9')
	{
		value = value * 10 - (*str++ - '0');
		if (value > 0)
			return (-(rsign < 0));
	}
	return (rsign * value);
}
