/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyed <asyed@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 00:55:06 by asyed             #+#    #+#             */
/*   Updated: 2017/11/14 14:29:22 by asyed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	parse_options(char **str, t_options *info, va_list ap)
{
	int	i;

	while (IS_FLAG(**str))
	{
		i = 0;
		while (flags[i].command)
		{
			if (**str == flags[i].command)
			{
				flags[i].func(info);
				break;
			}
			i++;
		}
		(*str)++;
	}
	min_width(str, info, ap);
	precision(str, info, ap);
	l_modifier(str, info, ap);
	// if (info->buf)
	// 	printf("Inside buf = \"%s\"\n", info->buf);
	// else
	// 	printf("Wasn't there? (%p)\n", info->buf);
}

void	min_width(char **str, t_options *info, va_list ap)
{
	static char	buf[1024] = "";
	int		i;

	if (**str == '*')
	{
		info->min_width = va_arg(ap, int);
		(*str)++;
	}
	else if (**str >= '0' && **str <= '9')
	{
		info->min_width = ft_atoi(*str);
		(*str) += s_n_length(info->min_width);
	}
	if (info->min_width)
	{
		i = 0;
		while (i < info->min_width)
			buf[i++] = (info->padding) ? '0' : ' ';
		buf[i] = '\0';
		info->buf = buf;
	}
}

/*
** Will this be an issue if precision < min_width?
*/

void	precision(char **str, t_options *info, va_list ap)
{
	// int	i;

	if (**str == '.')
	{
		(*str)++;
		if (**str == '*')
		{
			info->precision = va_arg(ap, int);
			(*str)++;
		}
		else if (**str >= '0' && **str <= '9')
		{
			info->precision = ft_atoi(*str);
			(*str) += s_n_length(info->precision);
		}
		// if (info->min_width)
		// {
		// 	i = info->min_width - info->precision;
		// 	while ((info->buf)[i])
		// 		(info->buf)[i++] = '\0';
		// }
	}
}

/*
** The length modifier - This is a straight copy from my old code
** Shorten/Norm this bullshit
*/

void	l_modifier(char **str, t_options *info, va_list ap)
{
	while (IS_LMOD(**str))
	{
		if (**str == 'h')
		{
			(*str)++;
			if (**str == 'h')
			{
				info->length = 2;
				(*str)++;
			}
			else
				info->length = 1;
		}
		else if (**str == 'l')
		{
			(*str)++;
			if (**str == 'l')
			{
				info->length = 4;
				(*str)++;
			}
			else
				info->length = 3;
		}
		else if (**str == 'j')
		{
			info->length = 5;
			(*str)++;
		}
		else if (**str == 'z')
		{
			info->length = 6;
			(*str)++;
		}
	}
	(void)ap;
}
