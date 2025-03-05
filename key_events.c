/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_events.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: togomez <togomez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 10:23:02 by togomez           #+#    #+#             */
/*   Updated: 2025/03/03 13:10:17 by togomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

static void ft_zoom(t_graphics *graphics, double zoom_factor)
{
    double width;
	double height;
	double new_width;
	double new_height;

    width = WIDTH / graphics->fractal->zoom;
    height = HEIGHT / graphics->fractal->zoom;

    new_width = width / zoom_factor;
    new_height = height / zoom_factor;

    graphics->fractal->zoom *= zoom_factor;
    graphics->fractal->shift_x += (width - new_width) / 2.0 / WIDTH;
    graphics->fractal->shift_y += (height - new_height) / 2.0 / HEIGHT;
}

int ft_key_handler(int keycode, t_graphics *graphics)
{
    double move_step;

    move_step = MOVE_STEP / graphics->fractal->zoom;

    if (keycode == ESC_KEY)
    {
        mlx_destroy_image(graphics->mlx, graphics->img);
        mlx_destroy_window(graphics->mlx, graphics->win);
        mlx_destroy_display(graphics->mlx);
        free(graphics->mlx);
        exit(0);
    }
    else if (keycode == LEFT_KEY)
        graphics->fractal->shift_x -= move_step;
    else if (keycode == RIGHT_KEY)
        graphics->fractal->shift_x += move_step;
    else if (keycode == UP_KEY)
        graphics->fractal->shift_y -= move_step;
    else if (keycode == DOWN_KEY)
        graphics->fractal->shift_y += move_step;

    ft_render_fractal(graphics);
    return (0);
}

int ft_mouse_handler(int button, int x, int y, t_graphics *graphics)
{
    double zoom_center_x;
	double zoom_center_y;

    zoom_center_x = (x - WIDTH / 2.0) * 4.0 / WIDTH / graphics->fractal->zoom
                    + graphics->fractal->shift_x;
    zoom_center_y = (y - HEIGHT / 2.0) * 4.0 / WIDTH / graphics->fractal->zoom
                    + graphics->fractal->shift_y;

    if (button == MOUSE_SCROLL_UP || button == MOUSE_SCROLL_DOWN)
    {
        graphics->fractal->shift_x = zoom_center_x;
        graphics->fractal->shift_y = zoom_center_y;

        if (button == MOUSE_SCROLL_UP)
            ft_zoom(graphics, ZOOM_FACTOR);
        else if (button == MOUSE_SCROLL_DOWN)
            ft_zoom(graphics, 1.0 / ZOOM_FACTOR);

        ft_render_fractal(graphics);
    }
    return (0);
}