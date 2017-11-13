/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyed <asyed@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/21 00:32:07 by asyed             #+#    #+#             */
/*   Updated: 2017/11/13 14:19:47 by asyed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "libft.h" 
# include <stdlib.h>
# include <stdarg.h>
# include <stdint.h>
# define CAPS(c) (c >= 'A' && c <= 'Z')
/* 
** Build '+' functionality
*/ 
# define IS_FLAG(c) (c == '-' || c == '0' || c == '+' || c == ' ' || c == '#'\
					|| c == '^')
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

typedef	struct 		s_options
{
	uint8_t			altform:1,padding:1,neg:1,space:1,sign:1,left:1,special:1;
	int				min_width;
	int				percision;
	int				length;
	int				written;
}					t_options;

/* ft_printf.c */
int		ft_printf(const char *str, ...);

/* num_fetch.c */
uint64_t	u_numfetch(va_list ap, t_options *info);
uint64_t	s_numfetch(va_list ap, t_options *info);

/* flags.c */
int			altform(va_list ap, t_options *info, char **str);
int			padded(va_list ap, t_options *info, char **str);
int			left(va_list ap, t_options *info, char **str);
int			space(va_list ap, t_options *info, char **str);
int			special(va_list ap, t_options *info, char **str);

/* parse.c */
void	flag_parse(char **str, t_options *info, va_list ap);
void	min_width(char **str, t_options *info, va_list ap);
void	percision(char **str, t_options *info, va_list ap);
void	l_modifier(char **str, t_options *info, va_list ap);
int		odd_check(char **str, t_options	*info, va_list ap);

/* conversions.c */

int	string(va_list ap, uint8_t caps, t_options *info);
int	uinteger(va_list ap, uint8_t caps, t_options *info);
int	integer(va_list ap, uint8_t caps, t_options *info);
int	charparse(va_list ap, uint8_t caps, t_options *info);
int	hexadec(va_list ap, uint8_t caps, t_options *info);
int	pointeraddr(va_list ap, uint8_t caps, t_options *info);
int	octal(va_list ap, uint8_t caps, t_options *info);

/* utils.c */
size_t	u_n_length(__uint64_t n);
size_t	s_n_length(__int64_t n);
void	ft_unichar(int c, t_options *info);
char	*numbase(size_t dec, int base, uint8_t caps, int *i);
void	clearvar(t_options *info);
void	ft_unistr(int *str, t_options *info);

struct 	entry {
	char	command;
	int		(*func)(va_list, uint8_t, struct s_options *);
};

struct flag_entry {
	char	command;
	int 	(*func)(va_list, struct s_options *, char **);
};

extern struct flag_entry	flags[];
extern struct entry			conversion[];

#endif