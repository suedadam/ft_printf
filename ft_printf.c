/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyed <asyed@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/23 22:22:48 by asyed             #+#    #+#             */
/*   Updated: 2017/11/07 03:22:49 by asyed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

struct	flag_entry	flags[] = {
	{'#', &altform},
	{'0', &padded}
};

struct	entry		conversion[] = {
	{'s', &string},
	{'d', &integer},
	{'c', &charparse},
	{'x', &hexadec},
	{'p', &pointeraddr},
	{'i', &integer},
	{'o', &octal},
	{'%', &charparse},
	{0, NULL}
};

int	ft_printf(const char *str, ...)
{
	va_list		ap;
	int			i;
	t_options	info;

	va_start(ap, str);
	while (*str)
	{
		if (*str == '%')
		{
			// info = (t_options) { 0 };
			clearvar(&info);
			str++;
			flag_parse((char **)&str, &info, ap);
			min_width((char **)&str, &info, ap);
			percision((char **)&str, &info, ap);
			l_modifier((char **)&str, &info, ap);
			i = 0;
			while (conversion[i].command)
			{
				if (ft_tolower(*str) == conversion[i].command)
				{
					str += conversion[i].func(ap, CAPS(*str), &info);
					break ;
				}
				i++;
			}
		}
		else
			ft_putchar(*str++);
	}
	va_end(ap);
	return (1);
}
