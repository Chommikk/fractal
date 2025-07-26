/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchoma <mchoma@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 11:15:21 by mchoma            #+#    #+#             */
/*   Updated: 2025/07/25 11:15:22 by mchoma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fractal.h"

void	rendering_madelbrot_image(t_image*data)
{
	int		i;
	int		j;
	float	c[2];
	float	z[2];
	int		colour;

	z[0] = 0;
	z[1] = 0;
	i = 0;
	while (i < 1000)
	{
		j = 0;
		while (j < 1000)
		{
			c[0] = (j - 500.0) / (50.0 * data->scale);
			c[1] = (i - 500.0) / (50.0 * data->scale);
			colour = colouring(algorithm(z, c));
			my_mlx_pixel_put(data, j, i, colour);
			j ++;
		}
		i++;
	}
}

int	loop(void *param)
{
	t_image	*img;

	img = param;
	rendering_madelbrot_image(img);
	return (1);
}

int	update(void *param)
{
	t_image	*img;

	img = param;
	rendering_madelbrot_image(img);
	mlx_put_image_to_window(img->sesion, img->window, img->img, 0, 0);
	return (1);
}

int	scaling(int key, int x, int y, void *param)
{
	int		i;
	t_image	*data;

	i = x;
	i = y;
	data = (t_image *)param;
	if (key == 4)
		data->scale ++;
	if (key == 5)
	{
		if (data->scale)
			data->scale --;
	}
	return (i);
}

void	madelbrot(void)
{
	t_image	img;

	img.sesion = mlx_init();
	img.window = mlx_new_window(img.sesion, 1000, 1000, "hello");
	img.img = mlx_new_image(img.sesion, 1000, 1000);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel,
			&img.line_length, &img.endian);
	img.scale = 1;
	mlx_hook(img.window, 17, 1L << 2, ft_exit1, &img);
	mlx_hook(img.window, 2, 1L << 0, ft_exit, &img);
	mlx_mouse_hook(img.window, *scaling, &img);
	mlx_loop_hook(img.sesion, update, &img);
	mlx_loop(img.sesion);
}
