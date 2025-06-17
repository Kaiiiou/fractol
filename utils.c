/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarti <amarti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 14:36:26 by amarti            #+#    #+#             */
/*   Updated: 2025/06/17 20:09:57 by amarti           ###   ########.fr       */
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
double map(double unscaled_num, double nw_min, double nw_max, double old_max)
{
	double largeur_totale;
	double pourcentage;
	double decalage;
	double resultat;

	largeur_totale = nw_max - nw_min;
	pourcentage = unscaled_num / old_max;
	decalage = largeur_totale * pourcentage;
	resultat = nw_min + decalage;
	return (resultat);
}