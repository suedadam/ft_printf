/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyed <asyed@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/21 00:32:07 by asyed             #+#    #+#             */
/*   Updated: 2017/11/07 02:04:06 by asyed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "libft.h" 
# include <stdlib.h>
# include <stdarg.h>
# include <stdint.h>
# define CAPS(c) (c >= 'A' && c <= 'Z')
# define IS_FLAG(c) (c == '-' || c == '0' || c == '+' || c == ' ' || c == '#')

typedef	struct 		s_options
{
	uint8_t			altform:1,padding:1,neg:1,space:1,sign:1;
	int				min_width;
	int				percision;	
}					t_options;

/* ft_printf.c */
int		ft_printf(const char *str, ...);

/* flags.c */
int		altform(va_list ap, t_options *info);
int		padded(va_list ap, t_options *info);

/* parse.c */
void	flag_parse(char **str, t_options *info, va_list ap);
void	min_width(char **str, t_options *info, va_list ap);
void	percision(char **str, t_options *info, va_list ap);

/* conversions.c */

int	string(va_list ap, uint8_t caps, t_options *info);
int	integer(va_list ap, uint8_t caps, t_options *info);
int	charparse(va_list ap, uint8_t caps, t_options *info);
int	hexadec(va_list ap, uint8_t caps, t_options *info);
int	pointeraddr(va_list ap, uint8_t caps, t_options *info);
int	octal(va_list ap, uint8_t caps, t_options *info);

/* utils.c */
size_t	n_length(size_t n);
void	ft_unichar(int c);
void	numbase(size_t dec, int base, char **output, uint8_t caps);
void	clearvar(t_options *info);

struct 	entry {
	char	command;
	int		(*func)(va_list, uint8_t, struct s_options *);
};

struct flag_entry {
	char	command;
	int 	(*func)(va_list, struct s_options *);
};

extern struct flag_entry	flags[];
extern struct entry			conversion[];

#endif