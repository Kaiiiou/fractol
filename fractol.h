/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarti <amarti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 16:04:13 by amarti            #+#    #+#             */
/*   Updated: 2025/06/19 20:07:49 by amarti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <unistd.h>
#include <stdlib.h>
#include "libft.h"
#include <math.h>
#include "MLX42/include/MLX42/MLX42.h"
#include <stdio.h>

//constantes 
#define WIDTH 800
#define HEIGHT 800
#define MAX_ITERATIONS 100

//Types de fractales
#define MANDELBROT 1
#define JULIA 2

typedef struct s_fractal
{
	int			type;
	double		julia_x;
	double		julia_y;
	double		min_x;
	double		max_x;
	double		min_y;
	double		max_y;
	double		zoom;

	mlx_t		*mlx;
	mlx_image_t	*image;
}	t_fractal;

// Prototypes des fonctions
double		atodbl(char *s);
int			mandelbrot_set(double x, double y);
int			julia_set(double x, double y, double julia_x, double julia_y);
void		init_fractal(t_fractal *fractal, int type);
double		map(double unscalednum, double nwmin, double nwmax, double oldmax);
void		fractal_render(t_fractal *fractal);
uint32_t	calculate_color(int iterations);
void		scroll_hook(double xdelta, double ydelta, void *param);
void		key_hook(mlx_key_data_t keydata, void *param);
void		close_hook(void *param);
void		zoom_at_mouse(t_fractal *fractal, double zmfcr, int msex, int msey);