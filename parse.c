/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyed <asyed@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 21:54:34 by asyed             #+#    #+#             */
/*   Updated: 2017/11/06 22:49:06 by asyed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "ft_printf.h"

void	flag_parse(char **str, t_options *info, va_list ap)
{
	int	i;

	while (**str && IS_FLAG(**str))
	{
		i = 0;
		while (flags[i].command)
		{
			if (**str == flags[i].command)
				flags[i].func(ap, info);
			i++;
		}
		(*str)++;
	}
}

void	min_width(char **str, t_options *info, va_list ap)
{
	if (**str == '*')
	{
		info->min_width = va_arg(ap, int);
		(*str)++;
	}
	else if (**str >= '0' && **str <= '9')
	{
		info->min_width = ft_atoi(*str);
		(*str) += n_length(info->min_width);
	}
}

void	percision(char **str, t_options *info, va_list ap)
{
	if (**str == '.')
	{
		(*str)++;
		if (**str == '*')
		{
			info->percision = va_arg(ap, int);
			(*str)++;
		}
		else if (**str >= '0' && **str <= '9')
		{
			info->percision = ft_atoi(*str);
			(*str) += n_length(info->percision);
		}
	}
}