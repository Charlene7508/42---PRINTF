/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chlepain <chlepain@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/02 14:45:27 by chlepain          #+#    #+#             */
/*   Updated: 2026/05/02 17:32:33 by chlepain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_hex(unsigned int n, char cas)
{
	char	*base;
	char	c;
	int		count;

	if (cas == 'x')
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	count = 0;
	if (n >= 16)
		count = count + ft_print_hex(n / 16, cas);
	c = base[n % 16];
	write(1, &c, 1);
	return (count + 1);
}
