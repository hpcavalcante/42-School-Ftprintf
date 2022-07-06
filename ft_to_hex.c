/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_to_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hepiment <hepiment@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 18:18:08 by hepiment          #+#    #+#             */
/*   Updated: 2022/07/05 18:34:04 by hepiment         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	find_size(unsigned long long int nb)
{
	int	lenght;

	lenght = 1;
	while (nb >= 16)
	{
		lenght++;
		nb = nb / 16;
	}
	return (lenght);
}

static char	to_ascii(unsigned long int src, char flag)
{
	if (src <= 9)
		return (src + 48);
	else if (flag == 'x' || flag == 'p')
		return (src + 87);
	else if (flag == 'X')
		return (src + 55);
	return ('\0');
}

int	to_hex(unsigned long long nb, char flag)
{
	char				*str;
	int					size;
	unsigned long int	mod;

	size = find_size(nb);
	if (flag == 'p')
		write(1, "0x", 2);
	if (nb == 0)
		return (ft_printf("0"));
	str = calloc(sizeof(char), (size + 1));
	while (nb != 0)
	{
		mod = (nb % 16);
		str[--size] = to_ascii(mod, flag);
		nb = nb / 16;
	}
	size = ft_printf("%s", str);
	free (str);
	return (size);
}
