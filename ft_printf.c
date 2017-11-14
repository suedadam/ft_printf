/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyed <asyed@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/23 22:22:48 by asyed             #+#    #+#             */
/*   Updated: 2017/11/14 01:51:56 by asyed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

struct s_flag_entry	flags[] = {
	{'#', &altform},
	{'0', &padded},
	{'-', &left},
	{' ', &space},
	{'^', &special},
	{'+', &plus}
};

// struct entry		conversion[] = {
// 	{'s', &string},
// 	{'d', &integer},
// 	{'u', &uinteger},
// 	{'c', &charparse},
// 	{'x', &hexadec},
// 	{'p', &pointeraddr},
// 	{'i', &integer},
// 	{'o', &octal},
// 	{0, NULL}
// };

int	ft_printf(const char *str, ...)
{
	va_list		ap;
	int			i;
	t_options	info;
	char		buffer[1028];

	va_start(ap, str);
	info.written = 0;
	while (*str)
	{
		if (*str == '%')
		{
			if (*buffer)
				print_buffer(buffer, &info);
			clearvar(&info);
			str++;
			parse_options((char **)&str, &info, ap);
		}
		else
			addchar(buffer, *str++);
	}
	if (*buffer)
		print_buffer(buffer, &info);
	va_end(ap);
	return (info.written);
}
