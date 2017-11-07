/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyed <asyed@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/21 00:32:07 by asyed             #+#    #+#             */
/*   Updated: 2017/10/27 15:03:34 by asyed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "libft.h" 
# include <stdio.h>
# include <stdlib.h>
# include <stdint.h>
# define CAPS(c) (c >= 'A' && c <= 'Z')

typedef struct		s_options
{
	uint8_t			caps;
	uint8_t			altform;
	uint8_t			zero;
	uint8_t			neg;
	uint8_t 		space;
	uint8_t 		sign;
	int				min_width;
	int				percision;
}					t_options;

int		ft_printf(const char *str, ...);
void 	numbase(size_t dec, int base, char **output, uint8_t caps);
int 	altform(int fd, va_list ap, t_options *info);
int 	padded(int fd, va_list ap, t_options *info);

struct 	entry{
	char	*command;
	// int		(*func)(int, va_list, char **, struct s_options *);
	int		(*func)(int, va_list, uint8_t, struct s_options *);
};

struct flag_entry {
	char	command;
	int 	(*func)(int, va_list, struct s_options *);
};

#endif