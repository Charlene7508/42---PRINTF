/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chlepain <chlepain@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/02 14:22:15 by chlepain          #+#    #+#             */
/*   Updated: 2026/05/02 18:51:37 by chlepain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_putnbr_long(long nb)
{
	char	c;
	int		count;

	count = 0;
	if (nb >= 10)
		count = count + ft_putnbr_long(nb / 10);
	c = '0' + (nb % 10);
	write(1, &c, 1);
	return (count + 1);
}

int	ft_print_int(int n)
{
	long	nb;
	int		count;

	nb = (long)n;
	count = 0;
	if (n < 0)
	{
		write(1, "-", 1);
		count++;
		nb = -nb;
	}
	return (count + ft_putnbr_long(nb));
}
