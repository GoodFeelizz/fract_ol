/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: togomez <togomez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 10:22:55 by togomez           #+#    #+#             */
/*   Updated: 2025/03/03 13:10:16 by togomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

int	main(int argc, char **argv)
{
	t_fractal	fractal;
	t_graphics	graphics;

	ft_input_handling(argc, argv, &fractal);
	ft_init_fractal(&fractal, argv);
	ft_init_graphics(&graphics, &fractal);
	ft_render_fractal(&graphics);
	mlx_key_hook(graphics.win, ft_key_handler, &graphics);
	mlx_mouse_hook(graphics.win, ft_mouse_handler, &graphics);
	mlx_hook(graphics.win, 17, 0, ft_close_window, &graphics);
	mlx_loop(graphics.mlx);
	return (0);
}