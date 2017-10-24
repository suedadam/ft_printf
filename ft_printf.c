/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyed <asyed@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/23 22:22:48 by asyed             #+#    #+#             */
/*   Updated: 2017/10/24 00:50:41 by asyed            ###   ########.fr       */
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

void numbase(size_t dec, int base, char **output)
{
	if (!dec)
		return ;
	numbase(dec / base, base, output);
	**output = "0123456789abcdef"[dec % base];
	(*output)++;
}

// char 	*numbase(size_t dec, int base)
// {
// 	char 	*output;
// 	int 	i;

// 	i = numlength(dec);

// 	output = (char *)ft_memalloc(i-- * sizeof(char));

// 	while (dec)
// 	{
// 		output[i] = "0123456789ABCDEF"[dec & 0xF];
// 		printf("output[%d] = %c\n", i, output[i]);
// 		dec /= base;
// 		i--;
// 	}
// 	return (output);
// }

// char 	*numbase(size_t dec, int base)
// {
// 	char 	*output;
// 	// size_t 	length;
// 	int 	i;
// 	int 	r;
// 	float	ratio;

// 	i = 0;

// 	// length = numlength(dec);
// 	// r = length;
// 	ratio = ceil((float)dec / (float)base);
// 	r = ratio;

// 	// printf("Ratio = %f\n", ratio);

// 	output = (char *)ft_memalloc(ratio-- * sizeof(char));

// 	while (dec)
// 	{
// 		output[(int)ratio] = "0123456789ABCDEF"[dec % base];
// 		printf("output[%d] = %c\n", (int)ratio, output[(int)ratio]);
// 		ratio--;
// 		dec /= base;
// 	}
// 	// printf("[1] = %c\n", output[1]);
// 	// while (output[i])
// 	// {
// 	// 	printf("(%d) %c\n", i, output[i]);
// 	// 	i++;
// 	// }
// 	// printmem(output, r + 1);
// 	// printf("Output = %s\n", output);
// 	return (output);
// }

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
	size_t	hex;
	char	*output;
	char	*save;

	hex = va_arg(ap, size_t);
	output = ft_memalloc(10 * sizeof(char));
	save = output;
	numbase(hex, 16, &output);
	output = save;
	ft_putstr("0x7fff");
	ft_putstr(output);
	return (1);
}

int 	pointeraddr(int fd, va_list ap)
{
	size_t	hex;
	char	*output;
	char	*save;

	hex = va_arg(ap, size_t);
	output = ft_memalloc(17 * sizeof(char));
	save = output;
	numbase(hex & 0x7fffffffffff, 16, &output);
	output = save;
	// ft_putstr("0x7fff");
	ft_putstr("0x");
	ft_putstr(output);
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

	struct 	entry table[] = { {"s", &string}, {"d", &integer}, {"c", &charparse}, {"x", &hexadec}, {"p", &pointeraddr}, {NULL, NULL}};

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