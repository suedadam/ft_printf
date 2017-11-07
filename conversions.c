/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversions.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyed <asyed@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 22:19:16 by asyed             #+#    #+#             */
/*   Updated: 2017/11/07 02:29:05 by asyed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	string(va_list ap, uint8_t caps, t_options *info)
{
	ft_putstr(va_arg(ap, char *));
	(void)info;
	(void)caps;
	return (1);
}

/*
** Need to handle length modifiers.
*/

int	integer(va_list ap, uint8_t caps, t_options *info)
{
	long	num;
	long	length;
	int		i;

	num = va_arg(ap, long);
	length = n_length(num);
	i = info->min_width;
	while (i-- > length)
		ft_putchar('0');
	ft_putnbr(num);
	(void)info;
	(void)caps;
	return (1);
}

int	charparse(va_list ap, uint8_t caps, t_options *info)
{
	ft_unichar(va_arg(ap, int));
	(void)info;
	(void)caps;
	return (1);
}

int	hexadec(va_list ap, uint8_t caps, t_options *info)
{
	size_t	hex;
	char	*output[20];
	void	*save;

	ft_bzero(*output, 20);
	hex = va_arg(ap, size_t);
	save = *output;
	numbase(hex, 16, (char **)&output, caps);
	*output = save;
	if (info->altform && ft_strcmp(*output, "0"))
		ft_putstr("0X");
	ft_putstr(*output);
	(void)info;
	return (1);
}

int	pointeraddr(va_list ap, uint8_t caps, t_options *info)
{
	size_t	hex;
	char	*output[20];
	void	*save;

	ft_bzero(*output, 20);
	hex = va_arg(ap, size_t);
	save = *output;
	numbase(hex & 0x7fffffffffff, 16, (char **)&output, caps);
	*output = save;
	ft_putstr("0x");
	ft_putstr(*output);
	(void)info;
	return (1);
}

int	octal(va_list ap, uint8_t caps, t_options *info)
{
	size_t	hex;
	char	*output[20];
	void	*save;

	ft_bzero(*output, 20);
	hex = va_arg(ap, size_t);
	save = *output;
	numbase(hex, 8, (char **)&output, caps);
	*output = save;
	if (info->altform)
		ft_putstr("0X");
	ft_putstr(*output);
	return (1);
}