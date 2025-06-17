/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarti <amarti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 14:35:52 by amarti            #+#    #+#             */
/*   Updated: 2025/06/17 20:40:43 by amarti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	mandelbrot_set(double x, double y)
{
	double	z_real;
	double	z_imag;
	double	z_real2;
	double	z_imag2;
	int		i;

	z_real = 0.0;
	z_imag = 0.0;
	i = 0;
	while (i < MAX_ITERATIONS)
	{
		z_imag2 = z_imag * z_imag;
		z_real2 = z_real * z_real;
		if ((z_real2 + z_imag2) > 4.0)
			break ;
		z_imag = 2 * z_real * z_imag + y;
		z_real = z_real2 - z_imag2 + x;
		i++;
	}
	return (i);
}
