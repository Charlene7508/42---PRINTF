/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chlepain <chlepain@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/02 17:17:43 by chlepain          #+#    #+#             */
/*   Updated: 2026/05/02 17:40:01 by chlepain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int	ft_printf(const char *format, ...);
int	ft_specificateur(char spec, va_list ap);
int	ft_print_char(char c);
int	ft_print_str(char *str);
int	ft_print_int(int n);
int	ft_print_uint(unsigned int n);
int	ft_print_hex(unsigned int n, char cas);
int	ft_print_ptr(void *ptr);
int	ft_putchar(char c);

#endif
