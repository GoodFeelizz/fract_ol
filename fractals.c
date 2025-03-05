/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: togomez <togomez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 10:23:15 by togomez           #+#    #+#             */
/*   Updated: 2025/03/03 13:10:20 by togomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

int	ft_calculate_mandelbrot(t_complex c, int max_iterations)
{
	t_complex	z;
	int			iteration;
	double		temp;

	z.real = c.real;
	z.imag = c.imag;
	iteration = 0;
	while (z.real * z.real + z.imag * z.imag <= 4 && iteration < max_iterations)
	{
		temp = z.real * z.real - z.imag * z.imag + c.real;
		z.imag = 2 * z.real * z.imag + c.imag;
		z.real = temp;
		iteration++;
	}
	return (iteration);
}

int	ft_calculate_julia(t_complex z, t_fractal *fractal)
{
	int		iteration;
	double	temp;

	iteration = 0;
	while (z.real * z.real + z.imag * z.imag <= 4
		&& iteration < fractal->max_iter)
	{
		temp = z.real * z.real - z.imag * z.imag + fractal->julia_re;
		z.imag = 2 * z.real * z.imag + fractal->julia_im;
		z.real = temp;
		iteration++;
	}
	return (iteration);
}

void	ft_render_fractal(t_graphics *graphics)
{
	t_complex	c;
	int			color;
	int			y;
	int			x;

	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			c.real = (x - WIDTH / 2.0) * 4.0 / WIDTH / graphics->fractal->zoom
				+ graphics->fractal->shift_x;
			c.imag = (y - HEIGHT / 2.0) * 4.0 / WIDTH / graphics->fractal->zoom
				+ graphics->fractal->shift_y;
			color = ft_get_pixel_color(graphics, c);
			graphics->data[y * WIDTH + x] = color;
		}
	}
	mlx_put_image_to_window(graphics->mlx, graphics->win, graphics->img, 0, 0);
}