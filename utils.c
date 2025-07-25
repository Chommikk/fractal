/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchoma <mchoma@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 11:17:34 by mchoma            #+#    #+#             */
/*   Updated: 2025/07/25 11:17:36 by mchoma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fractal.h"

void	my_mlx_pixel_put(t_image*data, int x, int y, int colour)
{
	char *dst; 

	dst = data->addr + (y * data->line_length 
		+ x * (data->bits_per_pixel /8));
	*(unsigned int*) dst = colour;
}

int	ft_exit(int keypress, void *param)
{
	t_image*data;

	data = param;
	if (keypress == 65307)
	{
		mlx_destroy_image(data->sesion, data->img);
		mlx_destroy_window(data->sesion, data->window);
		mlx_destroy_display(data->sesion);
		free(data->sesion);
		exit(0);
	}
	return (0);
}


int	algorithm(float *z, float *c)
{
	float	x[2];
	float	y[2];
	int		i;

	i = 1000;
	y[0] = z[0];
	y[1] = z[1];
	while(i --)
	{
		if (y[0] >= 2 || y[0] <= -2)
			return(i);
		if (y[1] >= 2 || y[1] <= -2)
			return(i);
		x[0] = y[0];
		x[1] = y[1];
		y[0] = x[0] * x[0]  - x[1] * x[1]+ c[0];
		y[1] = 2 * x[1] * x[0] + c[1];
	}
	return (0);
}
int ft_exit1(void *param)
{
	t_image*data;

	data = param;
	mlx_destroy_image(data->sesion, data->img);
	mlx_destroy_window(data->sesion, data->window);
	mlx_destroy_display(data->sesion);
	free(data->sesion);
	exit(0);
}

float	aatof(char *str)
{
	size_t	i;
	float	nbr;
	float	porn;
	
	porn = 1.0;
	i = 0;
	nbr = 0.0;
	if (str[i] == '-')
		porn = -1.0;
	while (str[i] <= '9' && str[i] >= '0')
	{
		nbr = nbr * 10 + str[i] - '0';
		i ++;
	}
	return (nbr);
}
