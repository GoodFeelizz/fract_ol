/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: togomez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 14:21:38 by togomez           #+#    #+#             */
/*   Updated: 2024/11/05 14:21:41 by togomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int nb)
{
	int	total;

	total = 0;
	if (nb == -2147483648)
	{
		ft_putstr("-2147483648");
		return (11);
	}
	if (nb < 0)
	{
		total += ft_putchar('-');
		nb = -nb;
	}
	if (nb > 9)
		total += ft_putnbr(nb / 10);
	total += ft_putchar(nb % 10 + '0');
	return (total);
}

int	ft_putunbr(unsigned int nb)
{
	int	total;

	total = 0;
	if (nb > 9)
		total += ft_putnbr(nb / 10);
	total += ft_putchar(nb % 10 + '0');
	return (total);
}

int	ft_hexa_putnbr(unsigned long int nb, char var)
{
	int		total;
	char	*base;

	total = 0;
	base = NULL;
	if (var == 'x')
		base = "0123456789abcdef";
	else if (var == 'X')
		base = "0123456789ABCDEF";
	if (nb >= 16)
		total += ft_hexa_putnbr(nb / 16, var);
	total += ft_putchar(base[nb % 16]);
	return (total);
}

int	ft_print_p(unsigned long nb)
{
	int	printed;

	printed = 0;
	if (!nb)
	{
		ft_putstr("(nil)");
		return (5);
	}
	printed += ft_putstr("0x");
	printed += ft_hexa_putnbr(nb, 'x');
	return (printed);
}
