/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoia <mtoia@student.42roma.it>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 10:59:02 by mtoia             #+#    #+#             */
/*   Updated: 2022/05/24 18:19:54 by mtoia            ###   ########.fr       */
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

float blend(float a, float b, float alpha)
{
  return (1.f - alpha) * a + alpha * b;
}

int	main()
{
	t_vars	vars;
	t_data	img;
	//int		y;
	float left, top, xside, yside;
	//int arry[610];
	//int arrx[610];
	
	left = -1.75;
    top = -0.25;
    xside = 0.25;
    yside = 0.45;
    //char driver[] = "";
	///arrx = fractalx(left, top, xside, yside);
  	
	//y = 0;
	vars.mlx = mlx_init();
	///fractal(left, top, xside, yside);
	vars.win = mlx_new_window(vars.mlx, 1920, 1080, "Fract-ol");
	img.img = mlx_new_image(vars.mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bit_per_pixel, &img.line_length, &img.endian);
	my_mlx_pixel_put(&img, 5, 5, 0x00FF0000);
	// while (y < 1079)
	// {
	// 	////my_mlx_pixel_put(&img, 5, y, 16711680);
	// 	y++;
	// 	int x;
	// 	x = 0;
	// 	while (x < 1919)
	// 	{
	// 		///my_mlx_pixel_put(&img, fractalx(left, top, xside, yside), fractaly(left, top, xside, yside), 0x00FF9050);
	// 		printf("%d  %d\n", arrx[x] ,arry[x]);
	// 		x++;
	// 	}			
	// }
	float xscale, yscale, zx, zy, cx, tempx, cy;
    int x, y;
    int maxx, maxy, count;
	// int arrx[610];
	// int arry[610];
	// int ccc = 0;

    // getting maximum value of x-axis of screen
    maxx = 600;
  
    // getting maximum value of y-axis of screen
    maxy = 600;
  
    // setting up the xscale and yscale
    xscale = xside / maxx;
    yscale = yside / maxy;
  
    // calling rectangle function
    // where required image will be seen
   // rectangle(0, 0, maxx, maxy);
  
    // scanning every point in that rectangular area.
    // Each point represents a Complex number (x + yi).
    // Iterate that complex number
    for (y = 1; y <= maxy - 1; y++) {
        for (x = 1; x <= maxx - 1; x++)
        {
            // c_real
            cx = x * xscale + left;
  
            // c_imaginary
            cy = y * yscale + top;
  
            // z_real
            zx = 0;
  
            // z_imaginary
            zy = 0;
            count = 0;
  
            // Calculate whether c(c_real + c_imaginary) belongs
            // to the Mandelbrot set or not and draw a pixel
            // at coordinates (x, y) accordingly
            // If you reach the Maximum number of iterations
            // and If the distance from the origin is
            // greater than 2 exit the loop
            while ((zx * zx + zy * zy < 4) && (count < MAXCOUNT))
            {
                // Calculate Mandelbrot function
                // z = z*z + c where z is a complex number
  
                // tempx = z_real*_real - z_imaginary*z_imaginary + c_real
                tempx = zx * zx - zy * zy + cx;
  
                // 2*z_real*z_imaginary + c_imaginary
                zy = 2 * zx * zy + cy;
  
                // Updating z_real = tempx
                zx = tempx;
  
                // Increment count
                count = count + 1;
				zx *= -10;
				zy *= -10;///////do not *-100 it will crash
            }
			
			//printf("%f\n", zx);
            // To display the created fractal
			//printf("%f\n", blend(0, 1, 10));
			my_mlx_pixel_put(&img, zx, zy, 0x00FF0000);
			//my_mlx_pixel_put(&img, 550, y - 2, 0x00FF0500);

        }
	}
	mlx_hook(vars.win, 2, 1L<<0, ftclose, &vars);
	// mlx_hook(vars.win, 6, 1L<<4, mois, &vars); when mouse enter windows mask, mois fuction is enabled
	mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);
	mlx_loop(vars.mlx);
}