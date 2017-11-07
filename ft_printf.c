/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyed <asyed@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/23 22:22:48 by asyed             #+#    #+#             */
/*   Updated: 2017/10/27 15:03:48 by asyed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <math.h>
#include "ft_printf.h"
#define IS_FLAG(c) (c == '-' || c == '0' || c == '+' || c == ' ' || c == '#')
struct	flag_entry	flags[] = { {'#', &altform} , {'0', &padded}};
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

void numbase(size_t dec, int base, char **output, uint8_t caps)
{
	if (!dec)
		return ;
	numbase(dec / base, base, output, caps);
	if (caps)
		**output = "0123456789ABCDEF"[dec % base];
	else
		**output = "0123456789abcdef"[dec % base];
	(*output)++;
}

int	string(int fd, va_list ap, uint8_t caps, t_options *info)
{
	ft_putstr(va_arg(ap, char *));
	return (1);
}

int integer(int fd, va_list ap, uint8_t caps, t_options *info)
{
	int num;
	int length;
	int i;

	num = va_arg(ap, int);
	length = numlength(num);
	i = info->min_width;
	while (i > length)
	{
		ft_putchar('0');
		// ft_putchar((info->zero) ? '0' : ' ');
		i--;
	}
	ft_putnbr(num);
	return (1);
}

int charparse(int fd, va_list ap, uint8_t caps, t_options *info)
{
	ft_putchar((char)va_arg(ap, int));
	return (1);
}

int	hexadec(int fd, va_list ap, uint8_t caps, t_options *info)
{
	size_t	hex;
	char	*output;
	char	*save;

	hex = va_arg(ap, size_t);
	output = ft_memalloc(10 * sizeof(char));
	save = output;
	numbase(hex, 16, &output, caps);
	output = save;
	// ft_putstr("0x7fff");
	if (info->altform && ft_strcmp(output, "0"))
		ft_putstr("0X");
	ft_putstr(output);
	free(output);
	return (1);
}

int		octal(int fd, va_list ap, uint8_t caps, t_options *info)
{
	size_t	oct;
	char	*output;
	char	*save;

	oct = va_arg(ap, size_t);
	output = ft_memalloc(10 * sizeof(char));
	save = output;
	numbase(oct, 8, &output, caps);
	output = save;
	if (info->altform)
		ft_putchar('0');
	ft_putstr(output);
	free(output);
	return (1);
}

int 	pointeraddr(int fd, va_list ap, uint8_t caps, t_options *info)
{
	size_t	hex;
	char	*output;
	char	*save;

	hex = va_arg(ap, size_t);
	output = ft_memalloc(17 * sizeof(char));
	save = output;
	numbase(hex & 0x7fffffffffff, 16, &output, caps);
	output = save;
	ft_putstr("0x");
	ft_putstr(output);
	free(output);
	return (1);
}

int		udecimal()
{
	return (1);
}

int 	altform(int fd, va_list ap, t_options *info)
{
	info->altform = 1;
	return (1);
}

int 	padded(int fd, va_list ap, t_options *info)
{
	info->zero = 1;
	return (1);
}

void	flag_parse(char **str, t_options *info, va_list ap)
{
	int i;

	while (**str && IS_FLAG(**str))
	{
		i = 0;
		while (flags[i].command)
		{
			if (**str == flags[i].command)
			{
				flags[i].func(1, ap, info);
				printf("Called a func for flag_parse()\n");
			}
			i++;
		}
		(*str)++;
	}
}

void	percision(char **str, t_options *info, va_list ap)
{
	if (**str == '.')
	{
		(*str)++;
		if (**str == '*')
		{
			info->percision = va_arg(ap, int);
			(*str)++;
		}
		else if (**str >= '0' && **str <= '9')
		{
			info->percision = ft_atoi(*str);
			(*str) += numlength(info->percision);
		}
	}
}


void	min_width(char **str, t_options *info, va_list ap)
{
	if (**str == '*')
	{
		info->min_width = va_arg(ap, int);
		(*str)++;
	}
	else if (**str >= '0' && **str <= '9')
	{
		info->min_width = ft_atoi(*str);
		(*str) += numlength(info->min_width);
	}
}

void	length_modifiers(char **str, t_options *info, va_list ap)
{

}

/*
** https://www.lix.polytechnique.fr/~liberti/public/computing/prog/c/C/FUNCTIONS/format.html
*/

int	ft_printf(const char *str, ...)
{
	va_list ap;
	char	c;
	int		res;
	int		i;
	t_options	*info;

	// info = (t_options *)ft_memalloc(sizeof(struct s_options *));
	struct 	entry table[] = { {"s", &string}, {"d", &integer}, {"c", &charparse}, {"x", &hexadec}, {"p", &pointeraddr}, {"i", &integer}, {"o", &octal}, {NULL, NULL}};

	va_start(ap, str);
	while (*str)
	{
		if (*str == '%')
		{
			info = (t_options *)ft_memalloc(sizeof(t_options));
			str++;
			flag_parse((char **)&str, info, ap);
			// printf("Zero = %d and min_width = %d \n(%s)\n", info->zero, info->min_width, str);
			min_width((char **)&str, info, ap);
			printf("Character after min_width (%s)\n", str);
			printf("[Before] Percision flags? : %d\n", info->percision);
			percision((char **)&str, info, ap);
			printf("[After] Percision flags? : %d\n", info->percision);
			length_modifiers((char **)&str, info, ap);
			/*
			** Still have more to do!!! D: 
			*/
			i = 0;
			while(table[i].command)
			{
				c = ft_tolower(*str);
				res = ft_strncmp(table[i].command, &c, 1);
				if (!res)
				{
					str += table[i].func(1, ap, CAPS(*str), info);
					// str++;
					break ;
				}
				i++;
			}
			// printf("\nChar (\"%c\")\n", *str);
			free(info);
			// str++;
		}
		else
			ft_putchar(*str++);
	}
	va_end(ap);

	// va_start(ap, str);
	// while (*str)
	// {
	// 	if (*str != '%')
	// 	{
	// 		ft_putchar(*str++);
	// 		continue ;
	// 	}
	// 	str++;
	// 	if (IS_FLAG(*str))
	// 		parseflags((char **)&str, info, ap);
	// 	i = 0;
	// 	while (table[i].command)
	// 	{
	// 		c = ft_tolower(*str);
	// 		res = ft_strncmp(table[i].command, &c, 1);
	// 		if (!res)
	// 		{
	// 			table[i].func(1, ap, CAPS(*str), info);
	// 			str++;
	// 			break ;
	// 		}
	// 		else
	// 			i++;
	// 	}
	// }
	// va_end(ap);
	return (1);
}
