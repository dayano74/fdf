/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayano <dayano@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 09:06:50 by dayano            #+#    #+#             */
/*   Updated: 2025/03/04 16:39:42 by dayano           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_draw_line_segment(t_point *start, t_point *end, t_fdf *data)
{
	float	step_x;
	float	step_y;
	int		max;

	step_x = end->x - start->x;
	step_y = end->y - start->y;
	max = ft_max(ft_mod(step_x), ft_mod(step_y));
	step_x /= max;
	step_y /= max;
	while ((int)(start->x - end->x) || (int)(start->y - end->y))
	{
		mlx_pixel_put(data->mlx_ptr, data->win_ptr, start->x, start->y,
			data->color);
		start->x += step_x;
		start->y += step_y;
	}
}

void	ft_bresenham_x(float x, float y, t_fdf *data)
{
	t_point	start;
	t_point	end;

	ft_init_line_points(&start, data, x, y);
	ft_init_line_points(&end, data, x + 1, y);
	data->color = ft_select_color(start.z, end.z);
	transform_point(&start, data);
	transform_point(&end, data);
	ft_draw_line_segment(&start, &end, data);
}

void	ft_bresenham_y(float x, float y, t_fdf *data)
{
	t_point	start;
	t_point	end;

	ft_init_line_points(&start, data, x, y);
	ft_init_line_points(&end, data, x, y + 1);
	data->color = ft_select_color(start.z, end.z);
	transform_point(&start, data);
	transform_point(&end, data);
	ft_draw_line_segment(&start, &end, data);
}

void	ft_draw(t_fdf *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < data->height)
	{
		x = 0;
		while (x < data->width)
		{
			if (x < data->width - 1)
				ft_bresenham_x(x, y, data);
			if (y < data->height - 1)
				ft_bresenham_y(x, y, data);
			x++;
		}
		y++;
	}
}
