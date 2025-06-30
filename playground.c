#include <mlx.h>
#include <unistd.h>
#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include "fractal.h"


//z_{n+1} = z_n * z_n + c;
void	algorithm(t_data *data, float *z, float *c)
{
	float	x;
	float	y;
	int		i;
	i = 100;

	while(i --)
	{
		if (z[0] >= 2 || z[0] <= -2)
			return;
		if (c[1] >= 2 || c[1] <= -2)
			return;
		mlx_pixel_put(data->sesion, data->window, 500 + (z[0] * 200) , 500 + (z[1]* 200) , data->colour);
		x = z[0];
		y = z[1];
		z[0] = x * x  - y * y+ c[0];
		z[1] = 2 * y * x + c[1];
	}
}

void fuckjulia(t_data *data, float* c)
{
	float	z[2];
	int		x;
	int		y;
	float	scale;

	scale = data->scale * 20 / 500;

	x = 0;
	while (x < 50)
	{
		y = 0;
		while (y < 50)
		{
			z[0] = (1 / 2.0) * scale;
			z[1] = (1 / 2.0) * scale;
			data->colour = 255 * 255 * 255 - 50 *y;
			algorithm(data, z, c);
			y ++;
		}
		x ++;
	}
}

int	algorithm2(t_data *data, float *z, float *c)
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


void	rendering_madelbrot(t_data *data)
{
	int	i;
	int	j;
	float	c[2];
	float	z[2];
	int		colour;

	z[0] = 0;
	z[1] = 0;
	i = 0;
	while(i < 1000)
	{
		j = 0;
		while(j < 1000)
		{
			c[0] = (j - 500.0) / 250.0;
			c[1] = (i - 500.0) / 250.0;

			colour = algorithm2(data, z, c);
			//printf("co7our = %i\n",colour);
			if (colour == 0)
				colour = 0xDBB658; //oragne
			else if (colour < 1000 - 4) 
				colour = 0x746dd7; //purple
			else if (colour < 1000 - 3) 
				colour = 0x165ACD; //blue
			else
				colour = 0xB74054; //read

			mlx_pixel_put(data->sesion, data->window, j, i, colour);
			j ++;
		}
		i++;
	}
}

void	rendering_julia(t_data *data, float *z)
{
	int	i;
	int	j;
	float	c[2];
	int		colour;

	i = 0;
	while(i < 1000)
	{
		j = 0;
		while(j < 1000)
		{
			c[0] = (j - 500.0) / 250.0;
			c[1] = (i - 500.0) / 250.0;

			colour = algorithm2(data, c, z);
			//printf("co7our = %i\n",colour);
			if (colour == 0)
				colour = 0xDBB658; //oragne
			else if (colour < 1000 - 4) 
				colour = 0x746dd7; //purple
			else if (colour < 1000 - 3) 
				colour = 0x165ACD; //blue
			else
				colour = 0xB74054; //read

			mlx_pixel_put(data->sesion, data->window, j, i, colour);
			j ++;
		}
		i++;
	}
}

int scaling(int key, t_data *data)
{
	if (key == 4)
		data->scale = 1;
	if (key == 5)
		data->scale = 2;
	return (1);
}

int	ft_exit(int keypress, void *param)
{
	param = NULL;
	if (keypress == 65307)
		exit(0);
	return (0);
}

void madelbrot()
{
	t_data	data;
	float	c[2];

	c[0] = 0;
	c[1] = 0;
	data.sesion = mlx_init();
	data.window = mlx_new_window(data.sesion, 1000, 1000, "playground");
//	data.scale = 1;
	mlx_mouse_hook(data.window, *scaling, &data);
	mlx_key_hook(data.window, *ft_exit , &data);
	rendering_madelbrot(&data);
//	rendering_julia(&data, c);
	mlx_loop(data.sesion);
}

void julia()
{
	char str[1024];
	int		i;
	float	c[2];
	
	write(1, "type value the real part of c\n", 31);
	i = read(1, str, 1024);
	if (i == 0)
		exit(0);
	if (i == -1)
		exit(1);
//	c[0] = atof(str);
	write(1, "type value the imaginary part of c\n", 31);
	i = read(1, str, 1024);
	if (i == 0)
		exit(0);
	if (i == -1)
		exit(1);
//	c[1] = atof(str);

int main()
{
	char	str[1024];
	int		i;
	
	write(1, "Type 1 for julia\n Type 2 for mandelbrot\n", 42);
	while(1)
	{
		i = read(1, str, 1024);
		if (i == 0)
			return (0);
		if (i == -1)
			return (1);
		if (str[0] == '1' && str[1] == '\n')
			julia();
		if (str[0] == '2' && str[1] == '\n')
			madelbrot();
		write(1, "Type 1 for julia\n Type 2 for mandelbrot\n", 42);
	}
	return (1);
}

