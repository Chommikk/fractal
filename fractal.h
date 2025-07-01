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
}	t_image;


#endif
