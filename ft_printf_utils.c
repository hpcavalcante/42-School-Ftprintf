/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hepiment <hepiment@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 13:24:03 by hepiment          #+#    #+#             */
/*   Updated: 2022/07/05 18:36:19 by hepiment         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

static void	ft_putchar_int(int i)
{
	char	c;

	c = '0';
	c = c + i;
	write(1, &c, 1);
}

int	ft_putnbr(long int n)
{
	int	i;
	int	count_size;	

	i = 1;
	count_size = 0;
	if (n == -2147483648)
		return (ft_printf("-2147483648"));
	if (n < 0)
	{
		ft_putchar('-');
		n = n * -1;
		count_size = 1;
	}
	while (i <= n / 10)
		i = i * 10;
	while (i >= 1)
	{
		ft_putchar_int(n / i);
		n = n - (n / i) * i;
		i = i / 10;
		count_size++;
	}
	return (count_size);
}

int	ft_putstr(char *s)
{	
	int	count_size;

	count_size = 0;
	if (!s)
	{
		ft_printf("(null)");
		return (6);
	}
	while (s[count_size] != '\0')
	{
		write (1, &s[count_size], 1);
		count_size++;
	}
	return (count_size);
}
