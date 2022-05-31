/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoia <mtoia@student.42roma.it>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 10:59:02 by mtoia             #+#    #+#             */
/*   Updated: 2022/05/31 14:53:22 by mtoia            ###   ########.fr       */
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

int	main()
{
	t_vars	vars;
	t_data	img;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 1920, 1080, "Fract-ol");
	img.img = mlx_new_image(vars.mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bit_per_pixel, &img.line_length, &img.endian);
	my_mlx_pixel_put(&img, 5, 5, 0x00FF0000);
	unsigned int	ImageHeight = 1080;
	unsigned int ImageWidth = 1019;
	unsigned int y = 0;
	double MinRe = -2.0;
	double MaxRe = 1.0;
	double MinIm = -1.2;
	double MaxIm = MinIm+(MaxRe-MinRe)*ImageHeight/ImageWidth;
	double Re_factor = (MaxRe-MinRe)/(ImageWidth-1);
	double Im_factor = (MaxIm-MinIm)/(ImageHeight-1);
	unsigned MaxIterations = 30;
	unsigned int x = 0;
	unsigned int n = 0;

	while(y++ < ImageHeight)
	{
		double c_im = MaxIm - y*Im_factor;
		x = 0;
		while (++x < ImageWidth)
		{
			double c_re = MinRe + x*Re_factor;

			double Z_re = c_re, Z_im = c_im;
			int isInside = 1;
			n = 0;
			while(++n < MaxIterations)
			{
				double Z_re2 = Z_re*Z_re;
				double Z_im2 = Z_im*Z_im;
				if(Z_re2 + Z_im2 > 4)
				{
					isInside = 0;
					break;
				}
				if (Z_re2 + Z_im2 < 0.05)
				{
					my_mlx_pixel_put(&img, x, y, 0x00EFFDFD);
				}
				if (Z_re2 + Z_im2 <= 1)
				{
					my_mlx_pixel_put(&img, x, y, 0x00D3BEFB);
				}
				if (Z_re2 + Z_im2 < 0.2)
				{
					my_mlx_pixel_put(&img, x, y, 0x00CC8AFF);
				}
				Z_im = 2*Z_re*Z_im + c_im;
				Z_re = Z_re2 - Z_im2 + c_re;
			}
			if(isInside)
			{
				//printf("%d   %d\n", x, y);
				my_mlx_pixel_put(&img, x, y, 0x00FFFFFF);
			}
		}
		y++;
	}
	
	mlx_hook(vars.win, 2, 1L<<0, ftclose, &vars);
	// mlx_hook(vars.win, 6, 1L<<4, mois, &vars); when mouse enter windows mask, mois fuction is enabled
	mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);
	mlx_loop(vars.mlx);
}