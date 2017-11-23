#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

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
	ret = ft_printf("ft: %X\n", &c);
	printf("%d\n", ret);
	// ret = printf("pf: %p\n", &c);
	// printf("%d\n", ret);
	ret = ft_printf("%X\n", 10000);
	printf("%d\n", ret);
}