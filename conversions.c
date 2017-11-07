/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversions.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyed <asyed@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 22:19:16 by asyed             #+#    #+#             */
/*   Updated: 2017/11/07 08:42:47 by asyed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

int	integer(va_list ap, uint8_t caps, t_options *info)
{
	__int64_t	num;
	__int64_t	length;
	int			i;

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
		num = va_arg(ap, size_t);
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
	ft_unichar(va_arg(ap, int), info);
	return (1);
}

int	hexadec(va_list ap, uint8_t caps, t_options *info)
{
	uint64_t	hex;
	char		*save;
	int			i;

	i = 0;
	hex = numfetch(ap, info);
	save = numbase(hex, 16, caps, &i);
	if (info->altform && ft_strcmp(save, "0"))
		ft_putstr("0X");
	ft_putstr(save);
	return (1);
}

int	pointeraddr(va_list ap, uint8_t caps, t_options *info)
{
	uint64_t	hex;
	char		*save;
	int			i;

	i = 0;
	hex = numfetch(ap, info);
	save = numbase(hex, 16, caps, &i);
	ft_putstr("0x7fff");
	ft_putstr(save);
	return (1);
}

int	octal(va_list ap, uint8_t caps, t_options *info)
{
	uint64_t	hex;
	char		*save;
	int			i;

	i = 0;
	hex = numfetch(ap, info);
	save = numbase(hex, 8, caps, &i);
	if (info->altform)
		ft_putstr("0X");
	ft_putstr(save);
	return (1);
}