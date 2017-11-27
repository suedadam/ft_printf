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
	// ft_printf("%%#o 0 ==  %#o\n", 0);
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
	// // ft_printf("\"% 4d\"\n", -42);
	// ft_printf("%Le", (long double)42);
	// ft_printf("Kashim a %Le histoires à raconter", (long double)1001);
	// ft_printf("Il fait au moins %Le\n", (long double)-8000);
	// ft_printf("%Le", (long double)-0);
	// ft_printf("%Le", (long double)0);
	// ft_printf("%Le", (long double)INT_MAX);
	// ft_printf("%Le", (long double)INT_MIN);
	// ft_printf("%Le", (long double)INT_MIN - 1);
	// ft_printf("%Le", (long double)INT_MAX + 1);
	// ft_printf("%Le", (long double)LONG_MAX);
	// ft_printf("%Le", (long double)LONG_MIN);
	// ft_printf("%Le", (long double)LONG_MIN - 1);
	// ft_printf("%Le", (long double)LONG_MAX + 1);
	// ft_printf("%%Le 0000042 == |%Le|\n", (long double)0000042);
	// ft_printf("%%Le \t == |%Le|\n", (long double)'\t');
	// ft_printf("%%Le Lydie == |%Le|\n", (long double)'L'+'y'+'d'+'i'+'e');
	// ft_printf("%%Le 42.42 == |%Le|\n", (long double)42.42);
	// ft_printf("ft: %X\n", 10000);
	// printf("pf: %X\n", 10000);
	ft_printf("%c %d %s %x %x %x %x %x\n", 'p', 234, "penis", 123, 42, 1242, 442, 432);
	printf("%x %x %x %x\n", 42, 1242, 442, 432);
	// ft_printf("%c %C %s. %d, %u, %o, %c", 'c', L'à', "Ly", 2, 10, 10000, '\n', "ôHohoho");
	// ft_printf("%c %C %s. %d, %u, %X, %c", 'c', L'à', "Ly", 2, 10, 10000, '\n', "ôHohoho");
	// printf("%c %C %s. %d, %u, %X, %c", 'c', L'à', "Ly", 2, 10, 10000, '\n', "ôHohoho");
	ft_printf("Lalalala, %d%% des gens qui parlent %C Ly adorent %s. Ou Presque. %d, %u, %X, %c", 100, L'à', "Ly", 2, 10, 10000, '\n', "ôHohoho");

}