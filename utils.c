/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarti <amarti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 14:36:26 by amarti            #+#    #+#             */
/*   Updated: 2025/06/19 20:09:43 by amarti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	handle_decimal_part(char *s, int i, double *result)
{
	double	diviseur;

	diviseur = 10.0;
	i++;
	while(s[i] >= 48 && s[i] <= 57)
	{
		*result = *result + (s[i] - '0') / diviseur;
		diviseur = diviseur * 10;
		i++;
	}
	return (i);
}
double	atodbl(char *s)
{
	double	result;
	int	nega;
	int	i;

	result = 0.0;
	nega = 1;
	i = 0;
	while(s[i] == 32 || (s[i] >= 9 && s[i] <= 13))
		i++;
	if(s[i] == '-' || s[i] == '+')
	{
		if (s[i] == '-')
			nega = -1;
		i++;
	}
	while(s[i] >= 48 && s[i] <= 57)
	{
		result = result * 10 + (s[i] - '0');
		i++;
	}
	if(s[i] == '.')
		i = handle_decimal_part(s, i, &result);
	return (result * nega);
}
void	init_fractal(t_fractal *fractal, int type)
{
	fractal->type = type;
	fractal->min_x = -2.0;
	fractal->max_x = 2.0;
	fractal->min_y = -2.0;
	fractal->max_y = 2.0;
	fractal->zoom = 1.0;
	if (type == JULIA)
	{
		fractal->julia_x = 0.0;
		fractal->julia_y = 0.0;
	}
	fractal->mlx = mlx_init(WIDTH, HEIGHT, "fractol", false);
	if (fractal->mlx == NULL)
	{
		perror("Error: MLX initialization failed");
		exit(1);
	}
	fractal->image = mlx_new_image(fractal->mlx, WIDTH, HEIGHT);
	if(fractal->image == NULL)
	{
		perror("Error: image creation failed");
		mlx_terminate(fractal->mlx);
		exit(1);
	}
}
double map(double unscalednum, double nwmin, double nwmax, double oldmax)
{
	double largeur_totale;
	double pourcentage;
	double decalage;
	double resultat;

	largeur_totale = nwmax - nwmin;
	pourcentage = unscalednum / oldmax;
	decalage = largeur_totale * pourcentage;
	resultat = nwmin + decalage;
	return (resultat);
}

uint32_t calculate_color(int iterations)
{
	if (iterations == MAX_ITERATIONS)
		return (0x000000FF);
	if (iterations < 33)
		return (0x2E8B57FF);
	else if (iterations < 66)
		return (0x87CEEBFF);
	else
		return (0xF0E68CFF);
}