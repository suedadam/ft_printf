/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyed <asyed@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 12:57:53 by asyed             #+#    #+#             */
/*   Updated: 2017/11/14 15:54:07 by asyed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	precision_adjust(t_options *info, intmax_t num)
{
	int	i;

	if (info->precision)
	{
		if (info->min_width)
		{
			info->min_width -= info->precision;
			if (info->plus || (info->left && num < 0))
				info->min_width--;
			i = info->min_width;
			while ((info->buf)[i])
				(info->buf)[i++] = '\0';
		}
		if (num < 0)
			num = -num;
		info->precision -= s_n_length(num);
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

int	integer(va_list ap, uint8_t caps, t_options *info)
{
	int			i;
	int			length;
	intmax_t	num;	

	if (caps)
		num = va_arg(ap, long int);
	else
		num = s_numfetch(ap, info);
	precision_adjust(info, num);
	if (!info->left)
	{
		ft_putstr(info->buf);
		if (info->plus)
		{
			if (num < 0)
			{
				num = -num;
				ft_putchar('-');
			}
			else
				ft_putchar('+');
		}
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
			ft_putchar('+');
		while ((info->precision)-- > 0)
			ft_putchar('0');
		ft_putnbr(num);
		ft_putstr(info->buf);
	}
	return (1);
}