/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyed <asyed@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 21:54:34 by asyed             #+#    #+#             */
/*   Updated: 2017/11/07 06:51:29 by asyed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>
#include "ft_printf.h"

size_t	n_length(size_t n)
{
	size_t	i;

	i = 0;
	while (n)
	{
		i++;
		n /= 10;
	}
	return (i);
}

void	ft_unistr(int *str, t_options *info)
{
	while (*str)
		ft_unichar(*str++, info);
}

void	ft_unichar(int c, t_options *info)
{
	if (c < 0x80 || info->length != 3)
	{
		// printf("Char = %c\n", c);
		ft_putchar(c);
		return ;
	}
	if (info->length == 3)
	{
		if (c < 0x800)
		{
			ft_putchar(0xC0 | (c >> 6));
			ft_putchar(0x80 | (c & 0x3F));
		}
		else if (c < 0x10000)
		{
			ft_putchar(0xE0 | (c >> 12));
			ft_putchar(0x80 | (c >> 6 & 0x3F));
			ft_putchar(0x80 | (c & 0x3F));
		}
		else if (c < 0x200000)
		{
			ft_putchar(0xF0 | (c >> 18));
			ft_putchar(0x80 | (c >> 12 & 0x3F));
			ft_putchar(0x80 | (c >> 6 & 0x3F));
			ft_putchar(0x80 | (c & 0x3F));
		}
	}
}

void	numbase(size_t dec, int base, char **output, uint8_t caps)
{
	if (!dec)
		return ;
	numbase(dec / base, base, output, caps);
	if (caps)
		**output = "0123456789ABCDEF"[dec % base];
	else
		**output = "0123456789abcdef"[dec % base];
	(*output)++;
}

void	clearvar(t_options *info)
{
	info->altform = 0;
	info->padding = 0;
	info->neg = 0;
	info->space = 0;
	info->sign = 0;
	info->min_width = 0;
	info->percision = 0;
	info->length = 0;
}