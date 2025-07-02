#include <mlx.h>
#include <unistd.h>
#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include "fractal.h"


//z_{n+1} = z_n * z_n + c;
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
			c[0] = (j - 500.0) / (50.0 * data->scale);
			c[1] = (i - 500.0) / (50.0 * data->scale);

			colour = algorithm2(data, z, c);
			//printf("co7our = %i\n",colour);
			if (colour == 0)
				colour = 0xDBB658; //oragne
			else if (colour < 1000 - 4) 
				colour = 0x746dd7; //purple
			else if (colour < 1000 - 3) 
				colour = 0x165ACD; //blue
			else if (colour < 1000 - 2) 
				colour = 0x165ACD; //blue
			else if (colour < 1000 - 1) 
				colour = 0x165ACD; //blue
			else
				colour = 0xB74054; //read

			mlx_pixel_put(data->sesion, data->window, j, i, colour);
			j ++;
		}
		i++;
	}
}

void	rendering_julia(t_data *data, float *c)
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
			z[0] = (j - 500.0) / 250.0;
			z[1] = (i - 500.0) / 250.0;

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

int scaling(int key, int x, int y, void *param)
{
	printf("%p,param\n", param);
	t_data *data = (t_data *) param;
	if (key == 4)
	//	printf("a\n");
		data->scale ++;
	if (key == 5)
	//	printf("b\n");
		data->scale --;
	printf("%p,\n", &data->scale);
	return (1);
}

int	ft_exit(int keypress, void *param)
{
	t_data *data;
	printf("%p,\n", param);
	data = param;
	if (keypress == 65307)
		exit(0);

	else if (keypress == 65451)
		data->scale ++;
	else if (keypress == 65453)
	{
		data->scale --;
		if (data ->scale == 0)
			data->scale = 1;
	}
	else
		printf("%i\n", keypress);
	return (0);
}
int update(void *param)
{
//	printf("\n%f\n", data->scale);
//	printf("%p", &data->scale);
	rendering_madelbrot(param);
	return (1);
}

int ft_exit1()
{
	exit(1);
}
void madelbrot()
{
	t_data	data[1];
	float	c[2];

	c[0] = 0;
	c[1] = 0;
	data->sesion = mlx_init();
	data->window = mlx_new_window(data->sesion, 1000, 1000, "playground");
		data->scale = 1.0f;
	//mlx_hook(data->window, 17, 2L << 1, ft_exit, data); 
	mlx_hook(data->window, 17, 1L << 2, ft_exit1, NULL); 
//	mlx_hook(data->window, 2, 1L << 0, ft_exit, NULL); 
	printf("%p, data\n", data);
//	mlx_hook(data->window, 4, 1L << 2, scaling, &data); 
//	mlx_hook(data->window, 17, 2L << 1, ft_exit, data); 
	mlx_key_hook(data->window, *ft_exit , data);
	mlx_mouse_hook(data->window, *scaling, data);
	//rendering_madelbrot(data);
	mlx_loop_hook(data->sesion, update, data);
	mlx_loop(data->sesion);
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
	exit(1);
}

int main()
{
	char	str[1024];
	int		i;
	
	write(1, "Type 1 for julia\nType 2 for mandelbrot\n", 40);
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

