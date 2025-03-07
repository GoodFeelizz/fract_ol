/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: togomez <togomez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 12:15:22 by togomez           #+#    #+#             */
/*   Updated: 2025/03/05 12:17:47 by togomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

void	show_helper(void)
{
	ft_putstr_fd("\n\n", 1);
	ft_putstr_fd("|--------------- How to launch fractol---------------|\n", 1);
	ft_putstr_fd("|                                                    |\n", 1);
	ft_putstr_fd("|    ./fractol mandelbrot                            |\n", 1);
	ft_putstr_fd("|    ./fractol burningship                           |\n", 1);
	ft_putstr_fd("|    ./fractol julia [real] [imaginary]              |\n", 1);
	ft_putstr_fd("|    Example: ./fractol julia -0.8 0.156             |\n", 1);
	ft_putstr_fd("|                                                    |\n", 1);
	ft_putstr_fd("|-------------- How to use the keyboard -------------|\n", 1);
	ft_putstr_fd("|                                                    |\n", 1);
	ft_putstr_fd("|     Press arrow keys to move the view              |\n", 1);
	ft_putstr_fd("|     Press ESC to close the window                  |\n", 1);
	ft_putstr_fd("|     Click the window's close button to exit        |\n", 1);
	ft_putstr_fd("|     Scroll to zoom in/out (follows the mouse)      |\n", 1);
	ft_putstr_fd("|                                                    |\n", 1);
	ft_putstr_fd("|----------------------------------------------------|\n", 1);
	ft_putstr_fd("\n\n", 1);
}

int	is_numeric(char *str)
{
	int	i;

	i = 0;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (!ft_isdigit(str[i]) && str[i] != '.'
			&& str[i] != '+' && str[i] != '-')
			return (0);
		if (i > 0 && (str[i] == '+' || str[i] == '-'))
			return (0);
		if (!ft_isdigit(str[i + 1])
			&& (str[i] == '+' || str[i] == '-'))
			return (0);
		if (str[i] == '.' && !str[i + 1])
			return (0);
		if (str[i] == '.' && i == 0)
			return (0);
		i++;
	}
	return (1);
}