/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchoma <mchoma@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 15:30:32 by mchoma            #+#    #+#             */
/*   Updated: 2025/07/25 15:30:33 by mchoma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

int	colouring(int colour)
{
	if (colour == 0)
		colour = 0xDBB658;
	else if (colour < 1000 - 50)
		colour = 0xcedc3f;
	else if (colour < 1000 - 20)
		colour = 0x746dd7;
	else if (colour < 1000 - 5)
		colour = 0x165ACD;
	else
		colour = 0xB74054;
	return (colour);
}

void	rendering_julia_image(t_image*data, float *c)
{
	int		i;
	int		j;
	float	z[2];
	int		colour;

	i = 0;
	while (i < 1000)
	{
		j = 0;
		while (j < 1000)
		{
			z[0] = (j - 500.0) / (50.0 * data->scale);
			z[1] = (i - 500.0) / (50.0 * data->scale);
			colour = colouring(algorithm(z, c));
			my_mlx_pixel_put(data, j, i, colour);
			j ++;
		}
		i++;
	}
}

int	updatej(void *param)
{
	t_image	*img;

	img = param;
	rendering_julia_image(img, img->c);
	mlx_put_image_to_window(img->sesion, img->window, img->img, 0, 0);
	return (1);
}

void	help(float *c)
{
	t_image	img;

	img.c = c;
	img.sesion = mlx_init();
	img.window = mlx_new_window(img.sesion, 1000, 1000, "hello");
	img.img = mlx_new_image(img.sesion, 1000, 1000);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel,
			&img.line_length, &img.endian);
	img.scale = 1;
	mlx_hook(img.window, 17, 1L << 2, ft_exit1, &img);
	mlx_hook(img.window, 2, 1L << 0, ft_exit, &img);
	mlx_mouse_hook(img.window, *scaling, &img);
	mlx_loop_hook(img.sesion, updatej, &img);
	mlx_loop(img.sesion);
}

void	julia(void)
{
	char	str[1024];
	int		i;
	float	c[2];

	c[0] = get_real();
	c[1] = get_imaginary();
	help(c);
	exit(1);
}
