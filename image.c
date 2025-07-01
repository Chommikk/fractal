#include "fractal.h"


void	my_mlx_pixel_put(t_image*data, int x, int y, int colour)
{
	char *dst; 

	dst = data->addr + (y * data->line_length 
		+ x * (data->bits_per_pixel /8));
	*(unsigned int*) dst = colour;
}

int	algorithm22(float *z, float *c)
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

void	rendering_madelbrot_image(t_image*data)
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

			colour = algorithm22(z, c);
			//printf("co7our = %i\n",0colour);
			colour = colour * (1658);
			/*
			if (colour == 0)
				colour = 0xDBB658; //oragne
			else if (colour < 1000 - 20) 
				colour = 0xcedc3f; //lime
			else if (colour < 1000 - 4) 
				colour = 0x746dd7; //purple
			else if (colour < 1000 - 3) 
				colour = 0x165ACD; //blue
			else
				colour = 0xB74054; //read
			*/
			my_mlx_pixel_put(data, j, i, colour);
			j ++;
		}
		i++;
	}
}

int loop(void *param)
{
	t_image *img;
	
	img = param;
	rendering_madelbrot_image(img);
	img->scale ++;
	return (1);
}

int	ft_exit(int keypress, void *param)
{
	t_image*data;
	data = param;
	if (keypress == 65307)
	{
		mlx_destroy_image(data->sesion, data->img);
		mlx_destroy_window(data->sesion, data->window);
		exit(0);
	}

	else if (keypress == 65451)
	{
		data->scale ++;
	}
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

int ft_exit1()
{
	exit(1);
}

int update(void *param)
{

	t_image *img;

	img = param;
	rendering_madelbrot_image(img);
	mlx_put_image_to_window(img->sesion, img->window, img->img, 0, 0);
	return (1);
}


int main()
{
	t_image	img;

	img.sesion = mlx_init();
	img.window = mlx_new_window(img.sesion, 1000, 1000, "hello");
	img.img = mlx_new_image(img.sesion, 1000, 1000);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, 
							  &img.line_length, &img.endian);
	img.scale = 1;

	img.scale ++;


	mlx_hook(img.window, 17, 1L << 2, ft_exit1, &img); 
	mlx_hook(img.window, 2, 1L << 0, ft_exit, &img); 
	mlx_hook(img.window, 2, 1L << 0, ft_exit, &img); 

	mlx_loop_hook(img.sesion, update, &img);
	mlx_loop(img.sesion);
}
