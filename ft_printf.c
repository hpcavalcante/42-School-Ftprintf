/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hepiment <hepiment@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 13:24:07 by hepiment          #+#    #+#             */
/*   Updated: 2022/07/07 00:41:21 by hepiment         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	types(const char *str, va_list arg)
{
	if (*str == 'c')
		return (ft_putchar(va_arg(arg, int)));
	if (*str == 's')
		return (ft_putstr(va_arg(arg, char *)));
	if (*str == 'p')
		return (to_hex(va_arg(arg, unsigned long int), 'p') + 2);
	if (*str == 'd')
		return (ft_putnbr(va_arg(arg, int)));
	if (*str == 'i')
		return (ft_putnbr(va_arg(arg, int)));
	if (*str == 'u')
		return (ft_putnbr(va_arg(arg, unsigned int)));
	if (*str == 'x')
		return (to_hex(va_arg(arg, unsigned int), 'x'));
	if (*str == 'X')
		return (to_hex(va_arg(arg, unsigned int), 'X'));
	if (*str == '%')
		return (ft_putchar('%'));
	return (0);
}

int	ft_printf(const char *print, ...)
{
	int		i;
	va_list	ap;

	i = 0;
	va_start(ap, print);
	while (*print != 0)
	{
		if (*print == '%')
		{
			print++;
			i += types(print, ap);
		}
		else
		{
			ft_putchar(*print);
			i++;
		}
		print++;
	}
	return (i);
}
