/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayano <dayano@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 15:41:16 by dayano            #+#    #+#             */
/*   Updated: 2025/03/06 19:43:35 by dayano           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_init_line_points(t_point *p, t_fdf *data, float x, float y)
{
	p->x = x;
	p->y = y;
	p->z = data->z_matrix[(int)y][(int)x];
	p->color = data->color_martix[(int)y][(int)x];
}

int	ft_select_color(int z, int z1)
{
	if (z > 0 || z1 > 0)
		return (0xe80c0c);
	else if (z < 0 || z1 < 0)
		return (0x0c0ce8);
	return (0xffffff);
}

void	ft_isometric(t_point *p, t_fdf *data)
{
	float	old_x;
	float	old_y;

	old_x = p->x;
	old_y = p->y;
	p->x = (old_x - old_y) * cos(ISO_ANGLE);
	p->y = (old_x + old_y) * sin(ISO_ANGLE) - (p->z * data->z_scale);
}

void	ft_transform_point(t_point *p, t_fdf *data)
{
	ft_isometric(p, data);
	p->x = p->x * data->zoom;
	p->y = p->y * data->zoom;
	p->x += data->shift_x;
	p->y += data->shift_y;
}
