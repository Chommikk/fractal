/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gettingnumbers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchoma <mchoma@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 14:29:59 by mchoma            #+#    #+#             */
/*   Updated: 2025/07/26 14:30:00 by mchoma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fractal.h"

float	get_real(void)
{
	char	str[1024];
	ssize_t	i;
	float	tmp;

	write(1, "type value the real part of c in format A/B use", 47);
	write(1, "whole numbers othervise it is undefined behaviour\n A=\n", 54);
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
	tmp = tmp / aatof(str);
	printf("real  == %f\n", tmp);
	return (tmp);
}

float	get_imaginary(void)
{
	char	str[1024];
	ssize_t	i;
	float	tmp;
	float	tmp2;

	write(1, "type value the real imaginary of c in format A/B use", 52);
	write(1, "whole numbers othervise it is undefined behaviour\n A=\n", 54);
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
	tmp = tmp / aatof(str);
	return (tmp);
}
