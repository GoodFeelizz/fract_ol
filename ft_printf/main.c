/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: togomez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 17:35:52 by togomez           #+#    #+#             */
/*   Updated: 2024/11/05 17:35:54 by togomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	int		total;
	size_t	i;
	va_list	args;

	total = 0;
	i = 0;
	if (!str)
		return (-1);
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			total += ft_converts (str[i + 1], args);
			i++;
		}
		else
		{
			total += ft_putchar(str[i]);
		}
		i++;
	}
	va_end(args);
	return (total);
}
