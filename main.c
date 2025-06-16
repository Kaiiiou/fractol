/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarti <amarti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 14:35:36 by amarti            #+#    #+#             */
/*   Updated: 2025/06/16 21:17:46 by amarti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

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
