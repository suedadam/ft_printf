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

int			altform(va_list ap, t_options *info)
{
	info->altform = 1;
	(void)ap;
	return (1);
}

int			padded(va_list ap, t_options *info)
{
	if (!info->left)
		info->padding = 1;
	(void)ap;
	return (1);
}

int			left(va_list ap, t_options *info)
{
	if (info->padding)
		info->padding = 0;
	info->left = 1;
	(void)ap;
	return (1);
}

uint64_t	numfetch(va_list ap, t_options *info)
{
	uint64_t ret;

	if (info->length == 1)
		ret = (unsigned short int)va_arg(ap, unsigned int);
	else if (info->length == 2)
		ret = (unsigned char)va_arg(ap, unsigned int);
	else if (info->length == 3)
		ret = va_arg(ap, unsigned long int);
	else if (info->length == 4)
		ret = va_arg(ap, unsigned long long int);
	else if (info->length == 5)
		ret = va_arg(ap, uintmax_t);
	else if (info->length == 6)
		ret = va_arg(ap, ssize_t);
	else
		ret = va_arg(ap, unsigned int);
	return (ret);
}