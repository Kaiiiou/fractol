/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarti <amarti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 14:36:04 by amarti            #+#    #+#             */
/*   Updated: 2025/06/19 20:00:06 by amarti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	julia_set(double x, double y, double julia_x, double julia_y)
{
	double	z_real;
	double	z_imag;
	double	z_real2;
	double	z_imag2;
	int		i;

	z_real = x;
	z_imag = y;
	i = 0;
	while (i < MAX_ITERATIONS)
	{
		z_imag2 = z_imag * z_imag;
		z_real2 = z_real * z_real;
		if ((z_real2 + z_imag2) > 4.0)
			break ;
		z_imag = 2 * z_real * z_imag + julia_y;
		z_real = z_real2 - z_imag2 + julia_x;
		i++;
	}
	return (i);
}
