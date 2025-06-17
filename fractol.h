/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarti <amarti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 16:04:13 by amarti            #+#    #+#             */
/*   Updated: 2025/06/17 21:05:31 by amarti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <unistd.h>
#include <stdlib.h>
#include "libft.h"
#include <math.h>
#include "MLX42/MLX42.h"
#include <stdio.h>

//constantes 
#define WIDTH 800
#define HEIGHT 800
#define MAX_ITERATIONS 80

//Types de fractales
#define MANDELBROT 1
#define JULIA 2

typedef struct s_fractal
{
	int		type;
	double	julia_x;
	double	julia_y;
	double	min_x;
	double	max_x;
	double	min_y;
	double	max_y;
	double	zoom;

	mlx_t		*mlx;
	mlx_image_t	*image;
}	t_fractal;

// Prototypes des fonctions
double	atodbl(char *s);
int		mandelbrot_set(double x, double y);
int		julia_set(double x, double y, double julia_x, double julia_y);
void	init_fractal(t_fractal *fractal, int type);
double	map(double unscaled_num, double nw_min, double nw_max, double old_max);
int		mandelbrot_set(double x, double y);
int julia_set(double x, double y, double julia_x, double julia_y);
