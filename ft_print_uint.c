/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_uint.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chlepain <chlepain@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/02 14:40:30 by chlepain          #+#    #+#             */
/*   Updated: 2026/05/02 17:03:59 by chlepain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_uint(unsigned int n)
{
	char	c;
	int		count;

	count = 0;
	if (n >= 10)
		count = count + ft_print_uint(n / 10);
	c = '0' + (n % 10);
	write (1, &c, 1);
	return (count + 1);
}
