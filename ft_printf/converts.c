/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converts.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: togomez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 16:52:16 by togomez           #+#    #+#             */
/*   Updated: 2024/11/07 16:52:20 by togomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_converts(char type, va_list args)
{
	if (type == 'c')
		return (ft_putchar(va_arg(args, int)));
	else if (type == 's')
		return (ft_putstr(va_arg(args, char *)));
	else if (type == 'p')
		return (ft_print_p((unsigned long)va_arg(args, void *)));
	else if (type == 'd' || type == 'i')
		return (ft_putnbr(va_arg(args, int)));
	else if (type == 'u')
		return (ft_putunbr(va_arg(args, unsigned int)));
	else if (type == 'x')
		return (ft_hexa_putnbr(va_arg(args, unsigned int), 'x'));
	else if (type == 'X')
		return (ft_hexa_putnbr(va_arg(args, unsigned int), 'X'));
	else if (type == '%')
	{
		ft_putchar('%');
		return (1);
	}
	return (0);
}
