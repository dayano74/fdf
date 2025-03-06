/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calc_bounding_box.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayano <dayano@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 13:18:25 by dayano            #+#    #+#             */
/*   Updated: 2025/03/06 17:10:09 by dayano           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_calc_bounding_box(t_fdf *data, float *min_x, float *max_x,
		float *min_y, float *max_y)
{
	int		x;
	int		y;
	t_point	p;

	*min_x = FLT_MAX;
	*max_x = -FLT_MAX;
	*min_y = FLT_MAX;
	*max_y = -FLT_MAX;
	y = 0;
	while (y < data->height)
	{
		x = 0;
		while (x < data->width)
		{
			ft_init_line_points(&p, data, x, y);
			ft_isometric(&p, data);
			if (p.x < *min_x)
				*min_x = p.x;
			if (p.x > *max_x)
				*max_x = p.x;
			if (p.y < *min_y)
				*min_y = p.y;
			if (p.y > *max_y)
				*max_y = p.y;
			x++;
		}
		y++;
	}
}

void	ft_calc_z_scale(t_fdf *data)
{
	float	min_z;
	float	max_z;
	float	current_z;
	float	z_range;
	float	desired_z_range;
	int		i;
	int		j;

	min_z = FLT_MAX;
	max_z = -FLT_MAX;
	i = 0;
	while (i < data->height)
	{
		j = 0;
		while (j < data->width)
		{
			current_z = data->z_matrix[i][j];
			if (current_z < min_z)
				min_z = current_z;
			if (current_z > max_z)
				max_z = current_z;
			j++;
		}
		i++;
	}
	z_range = max_z - min_z;
	desired_z_range = WINDOW_HEIGHT / 500.0f;
	if (z_range != 0)
	{
		data->z_scale = desired_z_range / z_range;
		if (data->z_scale > MAX_Z_SCALE)
		{
			data->z_scale = MAX_Z_SCALE;
		}
	}
	else
		data->z_scale = 1.0f;
}

void	ft_calc_zoom_and_shift(t_fdf *data)
{
	float	min_x;
	float	max_x;
	float	min_y;
	float	max_y;
	float	box_width;
	float	box_height;
	float	zoom_x;
	float	zoom_y;
	float	zoom;
	int		margin;
	float	center_x;
	float	center_y;

	ft_calc_z_scale(data);
	// calc bounding box
	margin = 100;
	ft_calc_bounding_box(data, &min_x, &max_x, &min_y, &max_y);
	box_width = max_x - min_x;
	box_height = max_y - min_y;
	// calc zoom
	zoom_x = (WINDOW_WIDTH - margin) / box_width;
	zoom_y = (WINDOW_HEIGHT - margin) / box_height;
	if (zoom_x < zoom_y)
	{
		zoom = zoom_x;
		data->zoom = zoom;
	}
	else
	{
		zoom = zoom_y;
		data->zoom = zoom;
	}
	// calc center of bounding box
	center_x = (min_x + max_x) / 2;
	center_y = (min_y + max_y) / 2;
	// calc shift value
	data->shift_x = WINDOW_WIDTH / 2 - center_x * zoom;
	data->shift_y = WINDOW_HEIGHT / 2 - center_y * zoom;
	// calc z scale
}
