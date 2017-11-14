/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ret.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyed <asyed@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/21 00:30:39 by asyed             #+#    #+#             */
/*   Updated: 2017/11/13 16:35:57 by asyed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
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
	char 		*hello;
	char 		*lmao;
	int  		ret;
	__int64_t	i;

	srandomdev();

	i = random();

	// printf("========%%i=======\n");
	// ret = printf("pf: (%lld)", i);
	// printf(" (%d)\n", ret);
	// ret = ft_printf("ft: (%lld)", i);
	// ft_printf(" (%d)\n", ret);
	// ret = printf("pf: (%zd%zd)", 0,42);
	// printf(" (%d)\n", ret);
	// ret = ft_printf("ft: (%zd%zd)", 0,42);
	// ft_printf(" (%d)\n", ret);
	// ret = printf("pf: (%zu, %zu)", 0, ULLONG_MAX);
	// printf(" (%d)\n", ret);
	// ret = ft_printf("ft: (%zu, %zu)", 0, ULLONG_MAX);
	// ft_printf(" (%d)\n", ret);
	ret = printf("pf: (%zo, %zo)", 0, ULLONG_MAX);
	printf(" (%d)\n", ret);
	ret = ft_printf("ft: (%zo, %zo)", 0, ULLONG_MAX);
	ft_printf(" (%d)\n", ret);
	// ret = printf("pf: (%-#10o, %o)", 0, ULLONG_MAX);
	// printf(" (%d)\n", ret);
	// ret = ft_printf("ft: (%-#10o, %o)", 0, ULLONG_MAX);
	// ft_printf(" (%d)\n", ret);
	// ret = printf("pf: (%zx, %zx)", 0, ULLONG_MAX);
	// printf(" (%d)\n", ret);
	// ret = ft_printf("ft: (%zx, %zx)", 0, ULLONG_MAX);
	// ft_printf(" (%d)\n", ret);
	// ft_printf(" (%d)\n", ret);
	ret = printf("pf: (%O)", LONG_MAX);
	printf(" (%d)\n", ret);
	ret = ft_printf("ft: (%O)", LONG_MAX);
	ft_printf(" (%d)\n", ret);
	return (1);
}