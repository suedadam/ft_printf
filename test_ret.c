/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ret.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyed <asyed@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/21 00:30:39 by asyed             #+#    #+#             */
/*   Updated: 2017/11/13 23:00:43 by asyed            ###   ########.fr       */
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
	char		*str = "pouet";
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
	// ret = printf("pf: (%zo, %zo)", 0, ULLONG_MAX);
	// printf(" (%d)\n", ret);
	// ret = ft_printf("ft: (%zo, %zo)", 0, ULLONG_MAX);
	// ft_printf(" (%d)\n", ret);
	// ret = printf("pf: (%-#10o, %o)", 0, ULLONG_MAX);
	// printf(" (%d)\n", ret);
	// ret = ft_printf("ft: (%-#10o, %o)", 0, ULLONG_MAX);
	// ft_printf(" (%d)\n", ret);
	// ret = printf("pf: (%zx, %zx)", 0, ULLONG_MAX);
	// printf(" (%d)\n", ret);
	// ret = ft_printf("ft: (%zx, %zx)", 0, ULLONG_MAX);
	// ft_printf(" (%d)\n", ret);
	// ft_printf(" (%d)\n", ret);
	// ret = printf("pf: (%O)", LONG_MAX);
	// printf(" (%d)\n", ret);
	// ret = ft_printf("ft: (%O)", LONG_MAX);
	// ft_printf(" (%d)\n", ret);
	// ft_printf("%o", 42);
	// ft_printf("Kashim a %o histoires à raconter", 1001);
	// ft_printf("Il fait au moins %o\n", -8000);
	// ft_printf("%o", -0);
	// ft_printf("%o", 0);
	// ft_printf("%o", INT_MAX);
	// ft_printf("%o", INT_MIN);
	// ft_printf("%o", INT_MIN - 1);
	// ft_printf("%o", INT_MAX + 1);
	// ft_printf("%%o 0000042 == |%o|\n", 0000042);
	// ft_printf("%%o \t == |%o|\n", '\t');
	// ft_printf("%%o Lydie == |%o|\n", 'L'+'y'+'d'+'i'+'e');
	// ret = printf("pf: (%p)", &i);
	// printf(" (%d)\n", ret);
	// ret = ft_printf("ft: (%p)", &i);
	// ft_printf(" (%d)\n", ret);
	// ret = printf("pf: (%p)", &str);
	// printf(" (%d)\n", ret);
	// ret = ft_printf("ft: (%p)", &str);
	// ft_printf(" (%d)\n", ret);
	// ft_printf("ft: %%      i 42 == |%      i|\n", 42);
	// printf("pf: %%      i 42 == |%      i|\n", 42);
	// ft_printf("ft: %% i -42 == |%     i|\n", 42);
	// printf("pf: %% i -42 == |%     i|\n", 42);
	// ft_printf("ft: Il fait au moins %D\n", -8000);
	// printf("pf: Il fait au moins %D\n", -8000);
	// ft_printf("%D", 42);
	// ft_printf("Kashim a %D histoires à raconter", 1001);
	// ft_printf("Il fait au moins %D\n", -8000);
	// ft_printf("%D", -0);
	// ft_printf("%D", 0);
	// ft_printf("%D", INT_MAX);
	// ft_printf("%D", INT_MIN);
	// ft_printf("%D", INT_MIN - 1);
	// ft_printf("%D", INT_MAX + 1);
	ft_printf("ft: %%+i 42 == %+i\n", 42);
	printf("pf: %%+i 42 == %+i\n", 42);
	ft_printf("ft: %%+d 42 == %+d\n", INT_MAX);
	printf("pf: %%+d 42 == %+d\n", INT_MAX);
	ft_printf("ft: %%+i -42 == %+i\n", -42);
	printf("pf: %%+i -42 == %+i\n", -42);
	ft_printf("ft: %%+04d 42 == %0+04d\n", 42);
	printf("pf: %%+04d 42 == %0+04d\n", 42);

	// ft_printf("ft: %% 4i 42 == |% 4i|\n", 42);
	// printf("pf: %% 4i 42 == |% 4i|\n", 42);
	return (1);
}