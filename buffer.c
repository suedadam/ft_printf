/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyed <asyed@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 00:43:34 by asyed             #+#    #+#             */
/*   Updated: 2017/11/15 13:34:25 by asyed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** Zero it out incase we need to use it after!
** Amoritization :)
*/

void	print_buffer(char *str, t_options *info)
{
	int	length;

	length = ft_strlen(str);
	info->written += length;
	ft_putstr(str);
	ft_bzero(str, length * sizeof(char));
}

void	addchar(char *str, char c)
{
	while (*str)
		str++;
	*str = c;
}
