/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversions.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suedadam <suedadam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 22:19:16 by asyed             #+#    #+#             */
/*   Updated: 2017/11/08 18:34:15 by suedadam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** Modify all functions to handle 0 as a valid parameter without seg faulting!
*/

// #include <stdio.h>
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
	while (length++ < info->min_width)
		ft_putchar((info->padding) ? '0' : ' ');
	(info->left ? 0 : ft_unistr(str, info));
	return (1);
}

int	uinteger(va_list ap, uint8_t caps, t_options *info)
{
	__uint64_t	num;
	__uint64_t	length;
	int			i;
 
	if (info->length == 1)
		num = (unsigned short int)va_arg(ap, int);
	else if (info->length == 2)
		num = (unsigned char)va_arg(ap, int);
	else if (info->length == 3)
		num = va_arg(ap, unsigned long int);
	else if (info->length == 4)
		num = va_arg(ap, unsigned long long int);
	else if (info->length == 5)
		num = va_arg(ap, uintmax_t);
	else if (info->length == 6)
		num = va_arg(ap, size_t);
	else
		num = va_arg(ap, unsigned int);
	length = n_length(num);
	i = info->min_width;
	(info->left ? ft_uputnbr(num) : 0);
	while ((__uint64_t)i-- > length)
		ft_putchar((info->padding) ? '0' : ' ');
	(info->left ? 0 : ft_uputnbr(num));
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
	if (info->length == 1)
		num = (short int)va_arg(ap, int);
	else if (info->length == 2)
		num = (char)va_arg(ap, int);
	else if (info->length == 3)
		num = va_arg(ap, long int);
	else if (info->length == 4)
		num = va_arg(ap, long long int);
	else if (info->length == 5)
		num = va_arg(ap, intmax_t);
	else if (info->length == 6)
		num = va_arg(ap, ssize_t);
	else
		num = va_arg(ap, int);
	length = n_length(num);
	i = info->min_width;
	(info->left ? ft_putnbr(num) : 0);
	while (i-- > length)
		ft_putchar((info->padding) ? '0' : ' ');
	(info->left ? 0 : ft_putnbr(num));
	(void)caps;
	return (1);
}

int	charparse(va_list ap, uint8_t caps, t_options *info)
{
	if (caps)
		info->length = 3;
	ft_putchar(va_arg(ap, unsigned char), info);
	return (1);
}

int	hexadec(va_list ap, uint8_t caps, t_options *info)
{
	uint64_t	hex;
	char		*save;
	int			i;
	int			length;

	i = 0;
	hex = numfetch(ap, info);
	save = numbase(hex, 16, caps, &i);
	length = ft_strlen(save);
	i = info->min_width;
	if (info->left && info->altform && ft_strcmp(save, "0"))
		ft_putstr((caps) ? "0X" : "0x");
	(info->left ? ft_putstr(save) : 0);
	while (i-- > length)
		ft_putchar((info->padding) ? '0' : ' ');
	if (!info->left && info->altform && ft_strcmp(save, "0"))
		ft_putstr((caps) ? "0X" : "0x");
	(info->left ? 0 : ft_putstr(save));
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
	if (!info->altform)
		ft_putstr((caps) ? "0X" : "0x");
	if (!hex)
		ft_putchar('0');
	else
		ft_putstr(save);
	return (1);
}

int	octal(va_list ap, uint8_t caps, t_options *info)
{
	__uint64_t	hex;
	__uint64_t	length;
	char		*save;
	int			i;

	i = 0;
	hex = numfetch(ap, info);
	save = numbase(hex, 8, caps, &i);
	if (info->altform && save[0] != '0')
		ft_putchar('0');
	length = ft_strlen(save);
	i = info->min_width;
	(info->left ? ft_putstr(save) : 0);
	while ((__uint64_t)i-- > length)
		ft_putchar((info->padding) ? '0' : ' ');
	(info->left ? 0 : ft_putstr(save));
	return (1);
}
