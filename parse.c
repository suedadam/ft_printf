/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyed <asyed@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 00:55:06 by asyed             #+#    #+#             */
/*   Updated: 2017/11/14 02:20:39 by asyed            ###   ########.fr       */
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
	if (info->buf)
		printf("Inside buf = \"%s\"\n", info->buf);
	else
		printf("Wasn't there? (%p)\n", info->buf);
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
