/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyed <asyed@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/21 00:30:39 by asyed             #+#    #+#             */
/*   Updated: 2017/10/25 13:56:49 by asyed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "ft_printf.h"

static char *rand_string(char *str, size_t size)
{
    const char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJK...";
    if (size) {
        --size;
        for (size_t n = 0; n < size; n++) {
            int key = rand() % (int) (sizeof charset - 1);
            str[n] = charset[key];
        }
        str[size] = '\0';
    }
    return str;
}

int
main(int argc, char *argv[])
{
	char *hello;
	int	i;

	srandomdev();

	i = random();

	printf("Manually compare\n============\n");
	printf("\n===x/X===\n");
	ft_printf("%x = ", i);
	printf("%x\n", i);
	ft_printf("%X = ", i);
	printf("%X\n", i);
	hello = (char *)ft_memalloc(20 * sizeof(char));
	hello = rand_string(hello, 20);
	printf("\n===s===\n");
	ft_printf("\"%s\" = ", hello);
	printf("\"%s\"\n", hello);
	// ft_printf("\"%S\" = ", hello);
	// printf("\"%S\"\n", hello);
	printf("\n===c/C===\n");
	ft_printf("\"%c\" = ", *hello);
	printf("\"%c\"\n", *hello);
	ft_printf("\"%C\" = ", *hello);
	printf("\"%C\"\n", *hello);
	printf("\n===d/D===\n");
	ft_printf("%d = ", i);
	printf("%d\n", i);
	ft_printf("%D = ", i);
	printf("%D\n", i);
	printf("\n===i===\n");
	ft_printf("%i = ", i);
	printf("%i\n", i);
	printf("\n===p===\n");
	ft_printf("%p = ", &i);
	printf("%p\n", &i);
	printf("\n===o/O===\n");
	ft_printf("%o = ", i);
	printf("%o\n", i);
	ft_printf("%O = ", i);
	printf("%O\n", i);

	// if (argc >= 2)
	// {
	// 	ft_printf(argv[1]);
	// }
	// ft_printf("\n");
	// ft_printf("%s and c = %c", "hi", 'h');

	ft_printf("str \"%s\" num \"%d\" and char \"%c\" and pointer \"%p\" and hex = \"%X\"\n", hello, 1, hello[0], &i, i);
	printf("[Official] = \"%X\"\n", i);
	printf("================\n");
	// printf("%%\n");
	printf("%'.2f", 1234567.89);
	// numbase(12, 10);
	// ft_printf("%d\n", 1);
	return (1);
}