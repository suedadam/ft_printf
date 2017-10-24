/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suedadam <suedadam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/21 00:25:11 by asyed             #+#    #+#             */
/*   Updated: 2017/10/22 21:34:46 by suedadam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>
#include <math.h>
#include "ft_printf.h"

size_t 	numlength(size_t dec)
{
	size_t i;

	i = 0;
	while (dec)
	{
		i++;
		dec /= 10;
	}
	return (i);
}

void 	printmem(char *str, size_t n)
{
	int i;

	i = 0;
	ft_putstr("\n==============\n");
	while (i < n)
	{
		ft_putnbr(str[i]);
		if (i != n - 1)
			ft_putchar(',');
		i++;
	}
	ft_putstr("\n==============\n");
}

char 	*numbase(size_t dec, int base)
{
	char 	*output;
	// size_t 	length;
	int 	i;
	int 	r;
	float	ratio;

	i = 0;

	// length = numlength(dec);
	// r = length;
	ratio = ceil((float)dec / (float)base);
	r = ratio;

	// printf("Ratio = %f\n", ratio);

	output = (char *)ft_memalloc(ratio-- * sizeof(char));

	while (dec)
	{
		output[(int)ratio] = "0123456789ABCDEF"[dec % base];
		// printf("output[%d] = %c\n", (int)ratio, output[(int)ratio]);
		ratio--;
		dec /= base;
	}
	// printf("[1] = %c\n", output[1]);
	// while (output[i])
	// {
	// 	printf("(%d) %c\n", i, output[i]);
	// 	i++;
	// }
	// printmem(output, r + 1);
	// printf("Output = %s\n", output);
	return (output);
}

int	string(int fd, va_list ap)
{
	ft_putstr(va_arg(ap, char *));
	return (1);
}

int integer(int fd, va_list ap)
{
	ft_putnbr(va_arg(ap, int));
	return (1);
}

int charparse(int fd, va_list ap)
{
	ft_putchar((char)va_arg(ap, int));
	return (1);
}

int	hexadec(int fd, va_list ap)
{
	ft_putstr(numbase(va_arg(ap, unsigned int), 16));
	// printf("Pointer func: \"%s\"\n", numbase(va_arg(ap, unsigned int), 16));
	// printf("POinter func: \"%p\"\n", (char *)va_arg(ap, char *));
	// ft_putstr((char *)va_arg(ap, char *));
	return (1);
}

int	ft_printf(const char *str, ...)
{
	va_list ap;
	int		res;
	int		i;


	struct 	entry{
		char	*command;
		int		(*func)(int, va_list);
	};

	struct 	entry table[] = { {"s", &string}, {"d", &integer}, {"c", &charparse}, {"x", &hexadec}, {NULL, NULL}};

	va_start(ap, str);
	while (*str)
	{
		if (*str != '%')
		{
			ft_putchar(*str++);
			continue ;
		}
		str++;
		i = 0;
		while (table[i].command)
		{
			res = ft_strncmp(table[i].command, &*str, 1);
			if (!res)
			{
				table[i].func(1, ap);
				str++;
				break ;
			}
			else
			{
				// printf("Res = %d\n", res);
				i++;
			}
		}
	}
	va_end(ap);
	return (1);
}


// int	ft_printf(const char *str, ...)
// {
// 	va_list	ap;
// 	int		res;

// 	va_start(ap, str);
// 	while (*str)
// 	{
// 		if (*str != '%')
// 		{
// 			ft_putchar(*str++);
// 			continue ;
// 		}
// 		if (*++str == 's')
// 			ft_putstr(va_arg(ap, char *));
// 		else if (*str == 'c')
// 			ft_putchar((char)va_arg(ap, int));
// 		else if (*str == 'd')
// 			ft_putnbr(va_arg(ap, int));
// 		else
// 		{
// 			printf("Other!\n");
// 		}
// 		str++;
// 	}
// 	va_end(ap);
// 	return (1);
// }