#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <limits.h>

int
main(void)
{
	int ret;
	wchar_t		c = L'\x82';
	// unsigned long c = -125;

	// // printf("%lu\n", c);
	// ft_printf("%lu\n", c);
	// ft_printf("ft: %C\n", c);
	// ft_printf("ft: %C\n", L'ø');
	// printf("pf: %C\n", c);
	// printf("pf: %C\n", L'ø');
	// ret = ft_printf("ft: %p\n", 0);
	// printf("%d\n", ret);
	// ret = printf("pf: %p\n", 0);
	// printf("%d\n", ret);
	// ret = ft_printf("ft: %X\n", &c);
	// printf("%d\n", ret);
	// // ret = printf("pf: %p\n", &c);
	// // printf("%d\n", ret);
	// ret = ft_printf("%X\n", 10000);
	// printf("%d\n", ret);
	// ret = ft_printf("ft: %% 4.5i 42 == |% 4.5i|\n", 42);
	// printf("%d\n", ret);
	// ret = printf("pf: %% 4.5i 42 == |% 4.5i|\n", 42);
	// printf("%d\n", ret);

	// ret = ft_printf("ft: %%04.2i 42 == |%04.2i|\n", 42);
	// printf("%d\n", ret);
	// ret = printf("pf: %%04.2i 42 == |%04.2i|\n", 42);
	// printf("%d\n", ret);


	printf("\n ===== Garbage tests=====\n");
	// ret = ft_printf("ft: %%0-4.2i 42 == |%0-4.3i|\n", 42);
	// printf("%d\n", ret);
	// ret = printf("pf: %%0-4.2i 42 == |%0-4.3i|\n", 42);
	// printf("%d\n", ret);
	// ret = ft_printf("ft: %%04.2i 42 == |%-4.3i|\n", 42);
	// printf("%d\n", ret);
	// ret = printf("pf: %%04.2i 42 == |%-4.3i|\n", 42);
	// printf("%d\n", ret);
	// ret = ft_printf("ft: |%04i|\n", 42);
	// printf("%d\n", ret);
	// ret = printf("pf: |%04i|\n", 42);
	// printf("%d\n", ret);
	// ret = ft_printf("ft: %%+04d 42 == %+04d\n", 42);
	// printf("%d\n", ret);
	// ret = printf("pf: %%+04d 42 == %+04d\n", 42);
	// printf("%d\n", ret);
	// ft_printf("%%#X 42 ==  %#X\n", 42);
	// ft_printf("%%X 42 ==  %X\n", 42);
	ft_printf("%%#o 0 ==  %#o\n", 0);
	// ft_printf("%%o 0 ==  %o\n", 0);
	// ft_printf("%%#o INT_MAX ==  %#o\n", INT_MAX);
	// ft_printf("%%o INT_MAX ==  %o\n", INT_MAX);
	// ft_printf("%%#o INT_MIN ==  %#o\n", INT_MIN);
	// ft_printf("%%o INT_MIN ==  %o\n", INT_MIN);
	// ft_printf("%%#X INT_MIN ==  %#X\n", INT_MIN);
	// ft_printf("%%X INT_MIN ==  %X\n", INT_MIN);
	// ft_printf("%%#X INT_MAX ==  %#X\n", INT_MAX);
	// ft_printf("%%X INT_MAX ==  %X\n", INT_MAX);
	// ret = printf("pf: |%+.4d|\n", 42);
	// printf("%d\n", ret);
	// ret = ft_printf("ft: %%      i 42 == |%      i|\n", 42);
	// printf("%d\n", ret);
	// ret = printf("pf: %%      i 42 == |%      i|\n", 42);
	// printf("%d\n", ret);
	// printf("\"% 1d\"\n", 42);
	// printf("\"% 4d\"\n", -42);
	// ft_printf("\"% 1d\"\n", 42);
	// ft_printf("\"% 4d\"\n", -42);
}