/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayano <dayano@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 09:06:50 by dayano            #+#    #+#             */
/*   Updated: 2025/03/06 19:59:20 by dayano           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_set_pixel(t_fdf *data, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || y < 0 || x >= WINDOW_WIDTH || y >= WINDOW_HEIGHT)
		return ;
	dst = data->img_data + (y * data->line_length) + (x * (data->bits_per_pixel
				/ 8));
	*(unsigned int *)dst = color;
}

int	ft_lerp_color(int start_color, int end_color, float t)
{
}

void	ft_draw_line_segment(t_point *start, t_point *end, t_fdf *data)
{
	float	step_x;
	float	step_y;
	int		max;
	int		i;
	int		start_color;
	int		end_color;
	int		interp_color;

	step_x = end->x - start->x;
	step_y = end->y - start->y;
	max = ft_max(ft_mod(step_x), ft_mod(step_y));
	if (max == 0)
	{
		if (start->color != -1)
			interp_color = start->color;
		else
			ft_select_color(start->z, end->z);
		ft_set_pixel(data, (int)start->x, (int)start->y, data->color);
		return ;
	}
	step_x /= max;
	step_y /= max;
	i = 0;
	while (i <= max)
	{
		ft_set_pixel(data, (int)start->x, (int)start->y, data->color);
		start->x += step_x;
		start->y += step_y;
		i++;
	}
}

void	ft_bresenham_x(float x, float y, t_fdf *data)
{
	t_point	start;
	t_point	end;

	ft_init_line_points(&start, data, x, y);
	ft_init_line_points(&end, data, x + 1, y);
	data->color = ft_select_color(start.z, end.z);
	ft_transform_point(&start, data);
	ft_transform_point(&end, data);
	ft_draw_line_segment(&start, &end, data);
}

void	ft_bresenham_y(float x, float y, t_fdf *data)
{
	t_point	start;
	t_point	end;

	ft_init_line_points(&start, data, x, y);
	ft_init_line_points(&end, data, x, y + 1);
	data->color = ft_select_color(start.z, end.z);
	ft_transform_point(&start, data);
	ft_transform_point(&end, data);
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
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_ptr, 0, 0);
}
