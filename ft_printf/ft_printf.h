/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: togomez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 14:35:01 by togomez           #+#    #+#             */
/*   Updated: 2024/11/06 14:35:05 by togomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stddef.h>

int	ft_putchar(char c);
int	ft_putstr(char *str);
int	ft_putunbr(unsigned int nb);
int	ft_putnbr(int nb);
int	ft_hexa_putnbr(unsigned long int nb, char var);
int	ft_print_p(unsigned long nb);
int	ft_converts(char type, va_list args);
int	ft_printf(const char *str, ...);

#endif