/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyed <asyed@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 21:54:34 by asyed             #+#    #+#             */
/*   Updated: 2017/11/13 14:59:45 by asyed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>
#include "ft_printf.h"

size_t	s_n_length(__int64_t n)
{
	size_t	i;

	i = 0;
	if (n < 0)
	{
		i++;
		n = -n;
	}
	while (n)
	{
		i++;
		n /= 10;
	}
	return (i);
}

size_t	u_n_length(__uint64_t n)
{
	size_t	i;

	i = 0;
	if (!n)
		return (1);
	while (n)
	{
		i++;
		n /= 10;
	}
	return (i);
}

void	ft_unistr(int *str, t_options *info)
{
	if (info->length == 3)
		while (*str)
			ft_unichar(*str++, info);
	else
		ft_putstr((char *)str);
}

void	ft_unichar(int c, t_options *info)
{
	if (c < 0x80 || info->length != 3)
		ft_putchar(c);
	else if (info->length == 3)
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

char	*numbase(size_t dec, int base, uint8_t caps, int *i)
{
	static	char	buffer[20];

	if (!*i)
		ft_bzero(buffer, 20);
	if (!dec)
		return (NULL);
	numbase(dec / base, base, caps, i);
	if (caps)
		buffer[*i] = "0123456789ABCDEF"[dec % base];
	else
		buffer[*i] = "0123456789abcdef"[dec % base];
	(*i)++;
	return (buffer);
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
	info->left = 0;
	info->special = 0;
}