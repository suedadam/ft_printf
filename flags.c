/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyed <asyed@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 21:54:34 by asyed             #+#    #+#             */
/*   Updated: 2017/11/07 05:57:15 by asyed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "ft_printf.h"

int	altform(va_list ap, t_options *info)
{
	info->altform = 1;
	(void)ap;
	return (1);
}

int	padded(va_list ap, t_options *info)
{
	if (!info->left)
		info->padding = 1;
	(void)ap;
	return (1);
}

int	left(va_list ap, t_options *info)
{
	if (info->padding)
		info->padding = 0;
	info->left = 1;
	(void)ap;
	return (1);
}