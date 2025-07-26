/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchoma <mchoma@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 21:34:04 by mchoma            #+#    #+#             */
/*   Updated: 2025/06/28 21:34:32 by mchoma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTAL_H
# define FRACTAL_H
#include <mlx.h>
#include <unistd.h>
#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
		
typedef struct s_data
{
	void	*window;
	void	*sesion;
	float	scale;
}	t_data;

typedef struct s_image
{
	void	*img;
	char	*addr;
	float	scale;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	void	*window;
	void	*sesion;
	float	*c;
}	t_image;

void julia();
int	algorithm2(t_data *data, float *z, float *c);
void	my_mlx_pixel_put(t_image*data, int x, int y, int colour);
float	aatof(char *str);
int	algorithm(float *z, float *c);
int scaling(int key, int x, int y, void *param);
float	get_real(void);
float	get_imaginary(void);
int ft_exit1(void *param);
int	ft_exit(int keypress, void *param);
void	madelbrot(void);
int	colouring(int colour);

#endif
