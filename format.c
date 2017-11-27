/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyed <asyed@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 12:57:53 by asyed             #+#    #+#             */
/*   Updated: 2017/11/27 02:55:21 by asyed            ###   ########.fr       */
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

int		build_precision(t_options *info)
{
	int			i;
	static char buf[1024] = "";

	i = 0;
	ft_bzero(buf, 1024);
	while (i < info->precision)
	{
		buf[i] = '0';
		i++;
	}
	info->precisionbuf = buf;
	return (1);
}

int		build_minwidth(t_options *info, intmax_t numlen)
{
	int			i;
	static char buf[1024];

	i = 0;
	ft_bzero(buf, 1024);
	while (i < info->min_width)
	{
		buf[i] = (info->padding) ? '0' : ' ';
		i++;
	}
	if ((info->min_width + info->precision) < numlen && info->space)
		buf[i] = ' ';
	info->buf = buf;
	return (1);
}

int		precision_adjust(t_options *info, intmax_t num)
{
	intmax_t	length;

	length = s_n_length(num);
	if (info->precision)
	{
		info->padding = 0;
		if (info->precision > length)
		{
			info->precision -= length;
			info->min_width -= info->precision;
		}
		else
			info->precision = 0;
	}
	if (info->min_width)
	{
		info->min_width -= length + info->plus;
		if (info->min_width < 0)
			info->min_width = (info->space) ? 1 : 0;
	}
	if (num < 0)
		info->space = 0;
	build_precision(info);
	build_minwidth(info, length);
	return (1);
}

int		u_precision_adjust(t_options *info, uintmax_t num)
{
	uintmax_t	length;

	length = u_n_length(num);
	if (info->precision)
	{
		info->padding = 0;
		if ((uintmax_t)info->precision > length)
		{
			info->precision -= length;
			info->min_width -= info->precision;
		}
		else
			info->precision = 0;
	}
	if (info->min_width)
	{
		info->min_width -= length + info->plus;
		if (info->min_width < 0)
			info->min_width = (info->space) ? 1 : 0;
	}
	build_precision(info);
	build_minwidth(info, length);
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

int		uinteger(va_list ap, uint8_t caps, t_options *info)
{
	uintmax_t	num;

	info->length = (caps) ? 3 : info->length;
	num = u_numfetch(ap, info);
	u_precision_adjust(info, num);
	if (info->left)
	{
		print_buffer(info->precisionbuf, info);
		ft_uputnbr(num);
		print_buffer(info->buf, info);
	}
	else
	{
		print_buffer(info->buf, info);
		print_buffer(info->precisionbuf, info);
		ft_uputnbr(num);
	}
	info->written += u_n_length(num);
	return (1);
}

void	alignment_handle(t_options *info, char sign, intmax_t num)
{
	if (info->left)
	{
		(sign) ? ft_putchar(sign) : 0;
		print_buffer(info->precisionbuf, info);
		ft_putnbr(num);
		print_buffer(info->buf, info);
	}
	else
	{
		if (info->padding)
		{
			(sign) ? ft_putchar(sign) : 0;
			print_buffer(info->buf, info);
		}
		else
		{
			print_buffer(info->buf, info);
			(sign) ? ft_putchar(sign) : 0;
		}
		print_buffer(info->precisionbuf, info);
		ft_putnbr(num);
	}
}

int		integer(va_list ap, uint8_t caps, t_options *info)
{
	intmax_t	num;
	char		sign;

	if (caps)
		num = va_arg(ap, long int);
	else
		num = s_numfetch(ap, info);
	precision_adjust(info, num);
	if (info->plus && num > 0)
		sign = '+';
	if (num < 0)
	{
		num = -num;
		sign = '-';
	}
	alignment_handle(info, sign, num);
	info->written += s_n_length(num) + IS_SET(sign);
	return (1);
}

int		ft_putwstr(wchar_t *str)
{
	wchar_t *p;

	p = str;
	while (*str)
		write(1, str++, 1);
	return (str - p);
}

int		wcharstr(va_list ap, t_options *info)
{
	wchar_t *str;
	char	buf[1024];
	int		i;

	ft_bzero(buf, 1024);
	str = (wchar_t *)va_arg(ap, wchar_t *);
	if (!str)
		write(1, "(null", 6);
	i = ft_wcslen(str);
	if (!info->precision)
		info->precision = i;
	if (i < info->min_width)
		ft_memset(buf, ' ', info->min_width - info->precision);
	if (!info->left)
		print_buffer(buf, info);
	ft_putwstr(str);
	info->written += info->precision;
	if (info->left)
		print_buffer(buf, info);
	return (1);
}

int		string(va_list ap, uint8_t caps, t_options *info)
{
	char	*str;
	char	buf[1024];
	int		i;

	ft_bzero(buf, 1024);
	caps = (info->length == 3) ? 1 : caps;
	if (caps)
		return (wcharstr(ap, info));
	str = va_arg(ap, char *);
	if (!str)
		write(1, "(null)", 6);
	i = ft_strlen(str);
	if (!info->precision)
		info->precision = i;
	if (i < info->min_width)
		ft_memset(buf, ' ', info->min_width - info->precision);
	if (!info->left)
		print_buffer(buf, info);
	write(1, str, info->precision);
	info->written += info->precision;
	if (info->left)
		print_buffer(buf, info);
	return (1);
}

int		charparse(va_list ap, uint8_t caps, t_options *info)
{
	ft_putchar((unsigned char)va_arg(ap, int));
	info->written++;
	(void)caps;
	return (1);
}

void	null_hex(t_options *info)
{
	ft_putchar('0');
	info->written++;
}

int		octal(va_list ap, uint8_t caps, t_options *info)
{
	uint64_t	hex;
	char		*save;
	int			i;

	i = 0;
	caps = (info->length == 3) ? 1 : caps;
	hex = u_numfetch(ap, info);
	save = numbase(hex, 8, caps, &i);
	i = ft_strlen(save);
	if (!i || !save)
		null_hex(info);
	info->written += (info->altform) ? 1 : 0;
	if (!info->left && info->altform && save && *save != '0')
		write(1, "0", 1);
	ft_putstr(save);
	info->written += i;
	if (info->left && info->altform && save && *save != '0')
		write(1, "0", 1);
	return (1);
}

int		hexadec(va_list ap, uint8_t caps, t_options *info)
{
	uint64_t	hex;
	char		buf[1024];
	char		*save;
	int			i;

	i = 0;
	ft_bzero(buf, 1024);
	hex = u_numfetch(ap, info);
	save = numbase(hex, 16, caps, &i);
	i = ft_strlen(save);
	if (!i)
		null_hex(info);
	if (info->altform)
	{
		addchar(buf, '0');
		addchar(buf, (caps) ? 'X' : 'x');
	}
	if (!info->left)
		print_buffer(buf, info);
	ft_putstr(save);
	info->written += i;
	if (info->left)
		print_buffer(buf, info);
	return (1);
}

int		pointeraddr(va_list ap, uint8_t caps, t_options *info)
{
	uint64_t	hex;
	char		*save;
	int			i;

	i = 0;
	hex = u_numfetch(ap, info);
	save = numbase(hex, 16, caps, &i);
	i = ft_strlen(save);
	if (!i)
	{
		ft_putstr("0x0");
		i += 3;
	}
	else
	{
		ft_putstr("0x");
		ft_putstr(save);
		i += 2;
	}
	info->written += i;
	return (1);
}
