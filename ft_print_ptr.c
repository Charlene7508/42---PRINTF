/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chlepain <chlepain@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/02 14:59:49 by chlepain          #+#    #+#             */
/*   Updated: 2026/05/02 17:11:49 by chlepain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_putnbr_base_ul(unsigned long n, const char *base)
{
	char	c;
	int		count;

	count = 0;
	if (n >= 16)
		count = count + ft_putnbr_base_ul(n / 16, base);
	c = base[n % 16];
	write(1, &c, 1);
	return (count + 1);
}

int	ft_print_ptr(void *ptr)
{
	int	count;

	if (ptr == NULL)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	write(1, "0x", 2);
	count = ft_putnbr_base_ul((unsigned long)ptr, "0123456789abcdef");
	return (count + 2);
}
