/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarti <amarti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 14:36:14 by amarti            #+#    #+#             */
/*   Updated: 2025/06/19 20:07:03 by amarti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	scroll_hook(double xdelta, double ydelta, void *param)
{
	t_fractal	*fractal;
	double		zoom_factor;
	int32_t		mouse_x;
	int32_t		mouse_y;

	(void)xdelta;
	fractal = (t_fractal *) param;
	if (ydelta > 0)
		zoom_factor = 0.9;
	else if (ydelta < 0)
		zoom_factor = 1.1;
	else
		return ;
	mlx_get_mouse_pos(fractal->mlx, &mouse_x, &mouse_y);
	zoom_at_mouse(fractal, zoom_factor, mouse_x, mouse_y);
	fractal_render(fractal);
}

void	key_hook(mlx_key_data_t keydata, void *param)
{
	t_fractal	*fractal;

	fractal = (t_fractal *)param;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		mlx_close_window(fractal->mlx);
}

void	close_hook(void *param)
{
	t_fractal	*fractal;

	fractal = (t_fractal *)param;
	mlx_close_window(fractal->mlx);
}

void	zoom_at_mouse(t_fractal *fractal, double zmfcr, int msex, int msey)
{
	double	mouse_real;
	double	mouse_imag;
	double	width;
	double	height;

	mouse_real = map(msex, fractal->min_x, fractal->max_x, WIDTH);
	mouse_imag = map(msey, fractal->min_y, fractal->max_y, HEIGHT);
	width = (fractal->max_x - fractal->min_x) * zmfcr;
	height = (fractal->max_y - fractal->min_y) * zmfcr;
	fractal->min_x = mouse_real - (mouse_real - fractal->min_x) * zmfcr;
	fractal->max_x = fractal->min_x + width;
	fractal->min_y = mouse_imag - (mouse_imag - fractal->min_y) * zmfcr;
	fractal->max_y = fractal->min_y + height;
}
