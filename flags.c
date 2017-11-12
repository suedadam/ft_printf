/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyed <asyed@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 21:54:34 by asyed             #+#    #+#             */
/*   Updated: 2017/11/07 07:37:59 by asyed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "ft_printf.h"

int			altform(va_list ap, t_options *info, char **str)
{
	info->altform = 1;
	(void)ap;
	(void)str;
	return (1);
}

int			padded(va_list ap, t_options *info, char **str)
{
	if (!info->left)
		info->padding = 1;
	(void)ap;
	(void)str;
	return (1);
}

int			special(va_list ap, t_options *info, char **str)
{
	info->special = 1;
	(void)ap;
	(void)str;
	return (1);
}

int			left(va_list ap, t_options *info, char **str)
{
	if (info->padding)
		info->padding = 0;
	info->left = 1;
	(void)ap;
	(void)str;
	return (1);
}

int			space(va_list ap, t_options *info, char **str)
{
	ft_putchar(' ');
	(*str)++;
	(void)ap;
	(void)info;
	return (1);
}
