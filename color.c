/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: togomez <togomez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 10:13:03 by togomez           #+#    #+#             */
/*   Updated: 2025/03/03 13:10:23 by togomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

static int	ft_get_color(int color, t_fractal *fractal)
{
	double	t;
	int		red;
	int		green;
	int		blue;

	t = (double)color / fractal->max_iter;
	red = (int)(9 * (1 - t) * t * t * t * 255);
	green = (int)(15 * (1 - t) * (1 - t) * t * t * 255);
	blue = (int)(8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255);
	color = (red << 16) | (green << 8) | blue;
	return (color);
}

int	ft_get_pixel_color(t_graphics *graphics, t_complex c)
{
	int	color;

	color = 0;
	if (graphics->fractal->name && ft_strcmp(graphics->fractal->name,
			"mandelbrot") == 0)
		color = ft_calculate_mandelbrot(c, graphics->fractal->max_iter);
	else if (graphics->fractal->name && ft_strcmp(graphics->fractal->name,
			"julia") == 0)
		color = ft_calculate_julia(c, graphics->fractal);
	if (color == graphics->fractal->max_iter)
		color = 0x000000;
	else
	{
		color = ft_get_color(color, graphics->fractal);
	}
	return (color);
}