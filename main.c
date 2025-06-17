/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarti <amarti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 14:35:36 by amarti            #+#    #+#             */
/*   Updated: 2025/06/17 21:51:14 by amarti           ###   ########.fr       */
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

	x = 0;
	while (x < WIDTH)
	{
		y = 0;
		while (y < HEIGHT)
		{
			real = map(x, fractal->min_x, fractal->max_x, WIDTH);
			imag = map(y, fractal->min_y, fractal->max_y, HEIGHT);
			if (fractal->type == MANDELBROT)
				iterations = mandelbrot_set(real, imag);
			else
				iterations = julia_set(real, imag, fractal->julia_x, fractal->julia_y);
			mlx_put_pixel(fractal->image, x, y, calculate_color(iterations));
			y++;
		}
		x++;
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
	if ((2 == argc && !ft_strncmp(argv[1], "mandelbrot", 10)) || (4 == argc && !ft_strncmp(argv[1], "julia", 5)))
	{

	}
	else
		print_usage();
}
