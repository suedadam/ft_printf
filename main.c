/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyed <asyed@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/21 00:30:39 by asyed             #+#    #+#             */
/*   Updated: 2017/10/24 00:33:01 by asyed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "ft_printf.h"

int
main(int argc, char *argv[])
{
	char *hello = "Hello World!";
	int	i;

	i = 12;
	// if (argc >= 2)
	// {
	// 	ft_printf(argv[1]);
	// }
	// ft_printf("\n");
	// ft_printf("%s and c = %c", "hi", 'h');

	ft_printf("str \"%s\" num \"%d\" and char \"%c\" and pointer \"%p\"\n", hello, 1, hello[0], &i);
	printf("[Official] = \"%p\"\n", &i);
	// numbase(12, 10);
	// ft_printf("%d\n", 1);
	return (1);
}