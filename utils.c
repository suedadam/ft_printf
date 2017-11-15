/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyed <asyed@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 00:38:23 by asyed             #+#    #+#             */
/*   Updated: 2017/11/14 14:39:17 by asyed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** Excuse info->written so that we can use it throughout the whole itteration
** of the input.
*/

void	clearvar(t_options *info)
{
	info->altform = 0;
	info->padding = 0;
	info->neg = 0;
	info->space = 0;
	info->sign = 0;
	info->left = 0;
	info->plus = 0;
	info->min_width = 0;
	info->precision = 0;
	info->length = 0;
	info->buf = NULL;
}

size_t	s_n_length(intmax_t n)
{
	int	i;

	i = 0;

	if (!n)
		return (1);
	if (n < 0)
	{
		n = -n;
		i++;
	}
	while (n)
	{
		i++;
		n /= 10;
	}
	return (i);
}

size_t	u_n_length(uintmax_t n)
{
	int	i;

	i = 0;

	if (!n)
		return (1);
	while (n)
	{
		i++;
		n /= 10;
	}
	return (i);
}