/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyed <asyed@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/21 00:32:07 by asyed             #+#    #+#             */
/*   Updated: 2017/11/21 13:51:48 by asyed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "libft.h"
# include <stdlib.h>
# include <stdarg.h>
# include <stdint.h>
# include <limits.h>
# define CAPS(c) (c >= 'A' && c <= 'Z')
# define IS_FLAG(c) (c == '-' || c == '0' || c == '+' || c == ' ' || c == '#')
# define IS_LMOD(c) (c == 'h' || c == 'l' || c == 'L' || c == 'j' || c == 'z')

/*
** Length code chart:
** 0 = unset
** 1 = h (short int/unsigned short int)
** 2 = hh (signed char/unsigned char)
** 3 = l (long int/unsigned long int)
** 4 = ll (long long int/unsigned long long int)
** 5 = j (intmax_t/uintmax_t)
** 6 = z (size_t/ssize_t)
*/

typedef	struct		s_options
{
	uint8_t			altform:1;
	uint8_t			padding:1;
	uint8_t			neg:1;
	uint8_t			space:1;
	uint8_t			sign:1;
	uint8_t			left:1;
	uint8_t			special:1;
	uint8_t			plus:1;
	int				min_width;
	int				precision;
	int				length;
	int				written;
	char			*buf;
}					t_options;

/*
** ft_printf.c
*/
int					ft_printf(const char *str, ...);

/*
** num_fetch.c
*/
int64_t				s_numfetch(va_list ap, t_options *info);
uint64_t			u_numfetch(va_list ap, t_options *info);

/*
** utils.c
*/
void				clearvar(t_options *info);
size_t				s_n_length(intmax_t n);
size_t				u_n_length(uintmax_t n);
int					ft_unichar(va_list ap, t_options *info);
char				*numbase(size_t dec, int base, uint8_t caps, int *i);

/*
** buffer.c
*/
void				print_buffer(char *str, t_options *info);
void				addchar(char *str, char c);

/*
** parse.c
*/
void				parse_options(char **str, t_options *info, va_list ap);
void				min_width(char **str, t_options *info, va_list ap);
void				precision(char **str, t_options *info, va_list ap);
void				l_modifier(char **str, t_options *info, va_list ap);

/*
** flags.c
*/
int					altform(t_options *info);
int					padded(t_options *info);
int					left(t_options *info);
int					space(t_options *info);
int					special(t_options *info);
int					plus(t_options *info);

/*
** format.c
*/
int					precision_adjust(t_options *info, intmax_t num);
int					integer(va_list ap, uint8_t caps, t_options *info);
int					percent(va_list ap, uint8_t caps, t_options *info);
int					string(va_list ap, uint8_t caps, t_options *info);
int					charparse(va_list ap, uint8_t caps, t_options *info);
int					hexadec(va_list ap, uint8_t caps, t_options *info);
int					octal(va_list ap, uint8_t caps, t_options *info);

struct				s_entry {
	char	command;
	int		(*func)(va_list, uint8_t, struct s_options *);
}					t_entry;

struct				s_flag_entry {
	char	command;
	int		(*func)(struct s_options *);
}					t_flag_entry;

extern struct s_flag_entry		flags[];
extern struct s_entry			conversion[];

#endif
