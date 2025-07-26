/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchoma <mchoma@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 11:04:09 by mchoma            #+#    #+#             */
/*   Updated: 2025/07/25 11:04:10 by mchoma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fractal.h"

int	main(void)
{
	char	str[1024];
	int		i;

	write(1, "Type 1 for julia\nType 2 for mandelbrot\n", 40);
	while (1)
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
