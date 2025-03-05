/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_program.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: togomez <togomez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 10:17:44 by togomez           #+#    #+#             */
/*   Updated: 2025/03/05 12:27:08 by togomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

void	ft_init_fractal(t_fractal *fractal, char **argv)
{
	fractal->shift_x = 0.0;
	fractal->shift_y = 0.0;
	fractal->zoom = 1.0;
	fractal->max_iter = MAX_ITER;
	if (fractal->julia_im)
	{
		fractal->julia_re = ft_atod(argv[2]);
		fractal->julia_im = ft_atod(argv[3]);
	}
}

static void	ft_init_graphics_struct(t_graphics *graphics)
{
	graphics->mlx = NULL;
	graphics->win = NULL;
	graphics->img = NULL;
	graphics->data = NULL;
	graphics->bpp = 0;
	graphics->line_len = 0;
	graphics->endian = 0;
	graphics->fractal = NULL;
}

void	ft_init_graphics(t_graphics *graphics, t_fractal *fractal)
{
	ft_init_graphics_struct(graphics);
	graphics->mlx = mlx_init();
	if (!graphics->mlx)
		ft_error_exit("Failed to initialize MLX");
	graphics->win = mlx_new_window(graphics->mlx, WIDTH, HEIGHT, "Fract-ol");
	if (!graphics->win)
	{
		ft_free_graphics(graphics);
		ft_error_exit("Failed to create MLX window");
	}
	graphics->img = mlx_new_image(graphics->mlx, WIDTH, HEIGHT);
	if (!graphics->img)
	{
		ft_free_graphics(graphics);
		ft_error_exit("Failed to create MLX image");
	}
	graphics->data = (int *)mlx_get_data_addr(graphics->img, &graphics->bpp,
			&graphics->line_len, &graphics->endian);
	if (!graphics->data)
	{
		ft_free_graphics(graphics);
		ft_error_exit("Failed to get image data address");
	}
	graphics->fractal = fractal;
}

void	ft_input_handling(int argc, char **argv, t_fractal *fractal)
{
	fractal->name = argv[1];
	if (argc == 1)
		exit(0);
	
	else if (!ft_strcmp("mandelbrot", argv[1]) && argc == 2)
	{
		fractal->julia_im = 0;
		return ;
	}
	else if (!ft_strcmp("julia", argv[1]) && argc == 4
			&& is_numeric(argv[2]) && is_numeric(argv[3]))
		return ;
	else
	{
		show_helper();
		exit(0);
	}
}