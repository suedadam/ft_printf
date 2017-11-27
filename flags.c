/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyed <asyed@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 01:03:33 by asyed             #+#    #+#             */
/*   Updated: 2017/11/26 20:35:51 by asyed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	altform(t_options *info)
{
	info->altform = 1;
	return (1);
}

int	padded(t_options *info)
{
	if (!info->left)
		info->padding = 1;
	return (1);
}

int	left(t_options *info)
{
	info->left = 1;
	info->padding = 0;
	return (1);
}

int	space(t_options *info)
{
	info->space = 1;
	return (1);
}

int	special(t_options *info)
{
	info->min_width = 1;
	return (1);
}

/*
** Handling Rules:
** Handle on signed conversions only (forces sign?)
** %+d = +42
** %+d = -42
*/

int	plus(t_options *info)
{
	info->plus = 1;
	info->space = 0;
	return (1);
}
