/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kai-iou <kai-iou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 14:35:36 by amarti            #+#    #+#             */
/*   Updated: 2025/06/18 01:35:11 by kai-iou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void fractal_render(t_fractal *fractal)
{
	int		x;
	int		y;
	double	real;
	double	imag;
	int		iterations;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		imag = fractal->min_y + y * ((fractal->max_y - fractal->min_y) / HEIGHT);
		while (x < WIDTH)
		{
			real = fractal->min_x + x * ((fractal->max_x - fractal->min_x) / WIDTH);
			if (fractal->type == MANDELBROT)
				iterations = mandelbrot_set(real, imag);
			else
				iterations = julia_set(real, imag, fractal->julia_x, fractal->julia_y);
			mlx_put_pixel(fractal->image, x, y, calculate_color(iterations));
			x++;
		}
		y++;
	}
}

static void	print_usage(void)
{
	ft_printf("./fractol [type] [parameters]\n");
	ft_printf("1 : Mandelbrot\n");
	ft_printf("2 : Julia <value_1> <value_2>\n");
	exit(1);
}

int	main(int argc, char **argv)
{
	t_fractal	fractal;

	if (2 == argc && !ft_strncmp(argv[1], "mandelbrot", 10))
		init_fractal(&fractal, MANDELBROT);
	else if(4 == argc && !ft_strncmp(argv[1], "julia", 5))
	{
		init_fractal(&fractal, JULIA);
		fractal.julia_x = atodbl(argv[2]);
		fractal.julia_y = atodbl(argv[3]);
	}
	else
		print_usage();
	mlx_scroll_hook(fractal.mlx, scroll_hook, &fractal);
	mlx_key_hook(fractal.mlx, key_hook, &fractal);
	mlx_close_hook(fractal.mlx, close_hook, &fractal);
	fractal_render(&fractal);
	mlx_image_to_window(fractal.mlx, fractal.image, 0, 0);
	mlx_loop(fractal.mlx);
	mlx_terminate(fractal.mlx);
	return (0);
}
