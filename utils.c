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
		free(data->sesion);
		exit(0);
	}
	return (0);
}

int ft_exit1()
{
	exit(1);
}
