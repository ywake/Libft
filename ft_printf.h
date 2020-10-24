/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ywake <ywake@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/15 16:45:48 by ywake             #+#    #+#             */
/*   Updated: 2020/07/27 18:58:48 by ywake            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

# define FLAG_CHARS		("-0# +")
# define LEFT_JUSTIFIED	(0b00000001)
# define ZERO_PADDING	(0b00000010)
# define FLAG_HASH		(0b00000100)
# define FLAG_SPACE		(0b00001000)
# define FLAG_PLUS		(0b00010000)
# define IS_PRECISION	(0b10000000)

typedef struct	s_info
{
	char	flag;
	int		width;
	int		precision;
	char	modifer;
}				t_info;

int				ft_printf(const char *str, ...);

void			flag_up(t_info *info, char flag);
char			*get_info(const char *str, t_info *info, va_list list);
char			*make_field(t_info *info, size_t len);
char			*proc_precision(t_info *info, char *str);
char			*proc_precision_num(t_info *info, char *str);

void			put_char_count(char c, size_t *len);
void			print_c(char c, t_info *info, size_t *len);
void			print_s(char *str, t_info *info, size_t *len);
void			print_num(char *str, t_info *info, size_t *len);
void			print_d(int num, t_info *info, size_t *len);
void			print_u(unsigned int num, t_info *info, size_t *len);
void			print_hex(char *str, t_info *info, size_t *len, char tag);
void			print_x(unsigned int num, t_info *info,
						size_t *len, char islower);
void			print_p(size_t num, t_info *info, size_t *len);
void			print_n(int	*d, t_info *info, size_t *len);

int				max(int a, int b);
int				abs_p(int *p);
void			free_set(char **dst, char *src);
int				ft_strchr_i(const char *s, int c);

#endif
