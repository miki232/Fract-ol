/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoia <mtoia@student.42roma.it>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 10:59:02 by mtoia             #+#    #+#             */
/*   Updated: 2022/05/23 18:37:29 by mtoia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx/mlx.h"
#include "so.h"
#include <stdlib.h>
#include <stdio.h>

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bit_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	ftclose(int keycode, t_vars *vars)
{
	if (keycode == ESC)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		exit(0);
	}
	return (0);
}

int	randomcolor()
{
	int x = rand();
	while (x < rand())
	{
		return(rand() * 20 + 20 / 100);
	}
	return(rand() * 20);
}
int	mois(void)
{
	printf("GELL");
	return (0);
}
int	main()
{
	t_vars	vars;
	t_data	img;
	int		y;
	
	y = 0;
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 1920, 1080, "Fract-ol");
	img.img = mlx_new_image(vars.mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bit_per_pixel, &img.line_length, &img.endian);
	my_mlx_pixel_put(&img, 5, 5, 0x00FF0000);
	while (y < 1000)
	{
		////my_mlx_pixel_put(&img, 5, y, 16711680);
		y++;
		int x;
		x = 0;
		while (x < 1080)
		{
			my_mlx_pixel_put(&img, x, y, 0x00FF9050);
			x++;
		}			
	}
	mlx_hook(vars.win, 2, 1L<<0, ftclose, &vars);
	// mlx_hook(vars.win, 6, 1L<<4, mois, &vars); when mouse enter windows mask, mois fuction is enabled
	mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);
	mlx_loop(vars.mlx);
}