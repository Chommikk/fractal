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

void	rendering_julia_image(t_image*data, float *c)
{
	int	i;
	int	j;
	float	z[2];
	int		colour;

	i = 0;
	while(i < 1000)
	{
		j = 0;
		while(j < 1000)
		{
			z[0] = (j - 500.0) / (50.0 * data->scale);
			z[1] = (i - 500.0) / (50.0 * data->scale);

			colour = algorithm(z, c);
			if (colour == 0)
				colour = 0xDBB658; //oragne
			else if (colour < 1000 - 50) 
				colour = 0xcedc3f; //lime
			else if (colour < 1000 - 20) 
				colour = 0x746dd7; //purple
			else if (colour < 1000 - 5) 
				colour = 0x165ACD; //blue
			else
				colour = 0xB74054; //read
			
			my_mlx_pixel_put(data, j, i, colour);
			j ++;
		}
		i++;
	}
}


float get_real(void)
{
	char	str[1024];
	ssize_t	i;
	float	tmp;

	write(1, "type value the real part of c in format A/B use whole numbers othervise it is undefined behaviour\n", 98);
	i = read(1, str, 1024);
	if (i == 0)
		exit(0);
	if (i == -1)
		exit(1);
	str[i] = 0;
	tmp = aatof(str);
	write(1, "B=\n", 3);
	i = read(1, str, 1024);
	if (i == 0)
		exit(0);
	if (i == -1)
		exit(1);
	tmp = tmp  / aatof(str);
	printf("real  == %f\n", tmp);
	return (tmp);
}

float get_imaginary(void)
{
	char	str[1024];
	ssize_t	i;
	float	tmp;
	float	tmp2;

	write(1, "type value the imaginary part of c in format A/B use whole numbers othervise it is undefined behaviour\n", 103);
	i = read(1, str, 1024);
	if (i == 0)
		exit(0);
	if (i == -1)
		exit(1);
	str[i] = 0;
	tmp = aatof(str);
	write(1, "B=\n", 3);
	i = read(1, str, 1024);
	if (i == 0)
		exit(0);
	if (i == -1)
		exit(1);
	tmp = tmp  / aatof(str);
	return (tmp);
}


int updatej(void *param)
{
	t_image *img;

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
//	mlx_hook(img.window, 2, 1L << 0, ft_exit, &img); 
	mlx_mouse_hook(img.window, *scaling, &img);
	mlx_loop_hook(img.sesion, updatej, &img);
	mlx_loop(img.sesion);
}

void julia()
{
	char str[1024];
	int		i;
	float	c[2];
	
	c[0] = get_real();
	c[1] = get_imaginary();
	help(c);
	exit(1);
}
