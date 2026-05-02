/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chlepain <chlepain@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/02 16:15:30 by chlepain          #+#    #+#             */
/*   Updated: 2026/05/02 18:57:15 by chlepain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_specificateur(char spec, va_list ap)
{
	if (spec == 'c')
		return (ft_print_char(va_arg(ap, int)));
	else if (spec == 's')
		return (ft_print_str(va_arg(ap, char *)));
	else if (spec == 'd' || spec == 'i')
		return (ft_print_int(va_arg(ap, int)));
	else if (spec == 'u')
		return (ft_print_uint(va_arg(ap, unsigned int)));
	else if (spec == 'x' || spec == 'X')
		return (ft_print_hex(va_arg(ap, unsigned int), spec));
	else if (spec == 'p')
		return (ft_print_ptr(va_arg(ap, void *)));
	else if (spec == '%')
		return (ft_putchar('%'));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		i;
	int		count;

	va_start(ap, format);
	i = 0;
	count = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '%' && format[i + 1] != '\0')
		{
			i++;
			count = count + ft_specificateur(format[i], ap);
		}
		else
			count = count + ft_putchar(format[i]);
		i++;
	}
	va_end(ap);
	return (count);
}
/*
#include "ft_printf.h"
#include <stdio.h>

int	main(void)
{
	printf("printf : %c\n", 'A');
	ft_printf("ft_printf : %c\n", 'A');

	printf("printf : %s\n", "hello");
	ft_printf("ft_printf : %s\n", "hello");

	printf("nom: %s age: %d hex: %x\n", "Bernadette", 85, 255);
	ft_printf("nom: %s age: %d hex: %x\n", "Bernadette", 85, 255);

	printf("  [%s] a [%d] ans\n", "Bernadette", 85);
	ft_printf("  [%s] a [%d] ans\n", "Bernadette", 85);

	char	*null_str = NULL;
	printf("printf : %s\n", null_str);
	ft_printf("ft_printf : %s\n", null_str);

	printf("printf : %d\n", 42);
	ft_printf("ft_printf : %d\n", 42);

	printf("printf : %d\n", -42);
	ft_printf("ft_printf : %d\n", -42);

	int min = -2147483648;
	printf("printf : %d\n", min );
	ft_printf("ft_printf : %d\n", min);

	printf("printf : %u\n", 42);
	ft_printf("ft_printf : %u\n", 42);

	printf("printf : %x\n", 255);
	ft_printf("ft_printf : %x\n", 255);

	printf("printf : %X\n", 255);
	ft_printf("ft_printf : %X\n", 255);

	int	x = 42;
	int	*null_ptr = NULL;
	printf("printf : %p\n", (void *)&x);
	ft_printf("ft_printf : %p\n", &x);
	printf("printf : %p\n", (void *)null_ptr);
	ft_printf("ft_printf : %p\n", null_ptr);

	printf("printf : %%\n");
	ft_printf("ft_printf : %%\n");

	return (0);
}*/
