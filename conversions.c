/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversions.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyed <asyed@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 22:19:16 by asyed             #+#    #+#             */
/*   Updated: 2017/11/13 17:26:01 by asyed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** Modify all functions to handle 0 as a valid parameter without seg faulting!
*/

#include <stdio.h>
/*
** This could very well be useless
*/
int	string(va_list ap, uint8_t caps, t_options *info)
{
	int 	length;
	wchar_t	*str;

	str = va_arg(ap, wchar_t *);
	length = ft_strlen((char *)str);
	if (caps)
		info->length = 3;
	(info->left ? ft_unistr(str, info) : 0);
	while (length < info->min_width)
	{
		ft_putchar((info->padding) ? '0' : ' ');
		length++;
	}
	(info->left ? 0 : ft_unistr(str, info));
	info->written += length;
	return (1);
}

int	uinteger(va_list ap, uint8_t caps, t_options *info)
{
	__uint64_t	num;
	__uint64_t	length;
	int			i;
 
 	num = u_numfetch(ap, info);
	length = u_n_length(num);
	i = info->min_width;
	(info->left ? ft_uputnbr(num) : 0);
	while(length < (__uint64_t)i)
	{
		ft_putchar((info->padding) ? '0' : ' ');
		length++;
	}
	(info->left ? 0 : ft_uputnbr(num));
	info->written += length;
	(void)caps;
	return (1);
}

int	integer(va_list ap, uint8_t caps, t_options *info)
{
	intmax_t	num;
	__int64_t	length;
	int			i;
 
 	if (caps)
 		info->length = 3;
	num = s_numfetch(ap, info);
	length = s_n_length(num);
	i = info->min_width;
	if (i < info->percision)
	{
		i = info->percision;
		info->padding = 1;
	}
	(info->left ? ft_putnbr(num) : 0);
	while(length < i)
	{
		ft_putchar((info->padding) ? '0' : ' ');
		length++;
	}
	(info->left ? 0 : ft_putnbr(num));
	info->written += length;
	// printf("\nfunc integer: %lld\n", length);
	(void)caps;
	return (1);
}


// int	integer(va_list ap, uint8_t caps, t_options *info)
// {
// 	intmax_t	num;
// 	__int64_t	length;
// 	int			i;
// 	int			percision;
 
//  	if (caps)
//  		info->length = 3;
// 	num = s_numfetch(ap, info);
// 	length = s_n_length(num);
// 	percision = 0;
// 	if (info->percision > length)
// 	{
// 		percision = info->percision - length;
// 		info->written += percision;
// 	}
// 	i = info->min_width - percision;
// 	while (!info->left && length < i)
// 	{

// 		ft_putchar((info->padding) ? '0' : ' ');
// 		length++;
// 	}
// 	while (percision-- > 0)
// 		ft_putchar('0');
// 	ft_putnbr(num);
// 	while (info->left && length < i)
// 	{
// 		ft_putchar((info->padding) ? '0' : ' ');
// 		length++;
// 	}
// 	info->written += length;
// 	(void)caps;
// 	return (1);
// }

int	charparse(va_list ap, uint8_t caps, t_options *info)
{
	if (caps)
		info->length = 3;
	if (info->special)
		ft_unichar(va_arg(ap, wchar_t), info);
	else
		ft_putchar((unsigned char)va_arg(ap, wchar_t));
	info->written++;
	return (1);
}

int	hexadec(va_list ap, uint8_t caps, t_options *info)
{
	uint64_t	hex;
	char		*save;
	int			i;
	int			length;

	i = 0;
	hex = u_numfetch(ap, info);
	save = numbase(hex, 16, caps, &i);
	// if (!save)
	// 	save = "0";
	length = ft_strlen(save);
	i = info->min_width;
	if (info->left && info->altform && ft_strcmp(save, "0"))
	{
		ft_putstr((caps) ? "0X" : "0x");
		info->written += 2;
	}
	(info->left ? ft_putstr(save) : 0);
	while (length < i)
	{
		ft_putchar((info->padding) ? '0' : ' ');
		length++;
	}
	if (!info->left && info->altform && ft_strcmp(save, "0"))
	{
		ft_putstr((caps) ? "0X" : "0x");
		info->written += 2;
	}
	(info->left ? 0 : ft_putstr(save));
	info->written += length;
	return (1);
}

int	pointeraddr(va_list ap, uint8_t caps, t_options *info)
{
	unsigned long int	hex;
	char				*save;
	int					i;

	i = 0;
	hex = va_arg(ap, unsigned long int);
	save = numbase(hex, 16, caps, &i);
	// if (!save)
	// 	save = "0";
	i = ft_strlen(save);
	if (!info->altform)
	{
		ft_putstr((caps) ? "0X" : "0x");
		i += 2;
	}
	ft_putstr(save);
	info->written += i;
	return (1);
}

int	octal(va_list ap, uint8_t caps, t_options *info)
{
	uintmax_t	hex;
	uintmax_t	length;
	char		*save;
	int			i;

	i = 0;
	if (caps)
		info->length = 3;
	hex = u_numfetch(ap, info);
	if (hex)
		save = numbase(hex, 8, caps, &i);
	else
	{
		return (1);
		save = "0";
	}
	length = ft_strlen(save);
	i = info->min_width;
	if (info->altform && *save != '0')
	{
		ft_putchar('0');
		info->written++;
	}
	(info->left ? ft_putstr(save) : 0);
	while (length < (__uint64_t)i)
	{
		ft_putchar((info->padding) ? '0' : ' ');
		length++;
	}
	(info->left ? 0 : ft_putstr(save));
	info->written += length;
	return (1);
}
