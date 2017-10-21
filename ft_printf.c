/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyed <asyed@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/21 00:25:11 by asyed             #+#    #+#             */
/*   Updated: 2017/10/21 01:28:16 by asyed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>
#include "ft_printf.h"

// int	parse_type(char *str)
// {

// }

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	int		res;

	va_start(ap, str);
	while (*str)
	{
		if (*str != '%')
		{
			ft_putchar(*str++);
			continue ;
		}
		if (*str == 's')
		{
			printf("String returned: %s\n", va_arg(ap, char *));
			// break ;
		}
		str++;
	}
	va_end(ap);
	return (1);
}