/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyed <asyed@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 12:57:53 by asyed             #+#    #+#             */
/*   Updated: 2017/11/16 10:27:48 by asyed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		percent(va_list ap, uint8_t caps, t_options *info)
{
	ft_putchar('%');
	info->written++;
	(void)caps;
	(void)ap;
	return (1);
}

// int		precision_adjust(t_options *info, intmax_t num)
// {
// 	int			i;
// 	intmax_t	length;

// 	length = s_n_length(num);
// 	if (info->min_width)
// 	{
// 		info->min_width -= length;
// 		if (info->plus || (info->left && num < 0))
// 			info->min_width--;
// 		i = info->min_width;
// 		while ((info->buf)[i])
// 			(info->buf)[i++] = '\0';
// 	}
// 	if (info->precision)
// 	{
// 		if (info->min_width)
// 		{
// 			info->min_width -= info->precision;
// 			i = info->min_width;
// 			while ((info->buf)[i])
// 				(info->buf)[i++] = '\0';
// 		}
// 		if (num < 0)
// 			num = -num;
// 		info->precision -= length;
// 	}
// 	info->written += info->precision + info->min_width;
// 	return (1);
// }

int		precision_adjust(t_options *info, intmax_t num)
{
	intmax_t	i;
	intmax_t	length;

	length = s_n_length(num);
	if (info->min_width)
	{
		info->min_width -= (length + ((info->plus) ? 1 : 0));
		i = info->min_width;
		while ((info->buf)[i])
			(info->buf)[i++] = '\0';
		if (num < 0)
			num = -num;
		info->written += info->min_width;
	}
	if (info->precision)
	{
		info->precision -= length;
		info->written -= info->min_width;
		info->min_width -= info->precision;
		info->written += info->precision;
	}
	return (1);
}

/*
** Max itterated size = 1024 bytes.
*/

void	multi_print(char c, int n)
{
	char	buf[1024];
	int		i;

	i = 0;
	while (i < n)
		buf[i++] = c;
	ft_putstr(buf);
}

int		integer(va_list ap, uint8_t caps, t_options *info)
{
	intmax_t	num;	

	if (caps)
		num = va_arg(ap, long int);
	else
		num = s_numfetch(ap, info);
	precision_adjust(info, num);
	if (!info->left)
	{
		ft_putstr((info->altform) ? info->buf : 0);
		if (num < 0)
		{
			num = -num;
			ft_putchar('-');
			info->written++;
		}
		if (info->plus && num > 0)
		{
			info->written++;
			ft_putchar('+');
		}
		ft_putstr((info->altform) ? 0 : info->buf);
		while ((info->precision)-- > 0)
			ft_putchar('0');
		ft_putnbr(num);
	}
	else
	{
		if (num < 0)
		{
			num = -num;
			ft_putchar('-');
		}
		else if (info->plus)
		{
			info->written++;
			ft_putchar('+');
		}
		while ((info->precision)-- > 0)
			ft_putchar('0');
		ft_putnbr(num);
		ft_putstr(info->buf);
	}
	info->written += s_n_length(num);
	return (1);
}