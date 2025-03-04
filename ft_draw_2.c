/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayano <dayano@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 15:41:16 by dayano            #+#    #+#             */
/*   Updated: 2025/03/04 16:48:33 by dayano           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_init_line_points(t_point *p, t_fdf *data, float x, float y)
{
	p->x = x;
	p->y = y;
	p->z = data->z_matrix[(int)y][(int)x];
}

int	ft_select_color(int z, int z1)
{
	if (z > 0 || z1 > 0)
		return (0xe80c0c);
	else if (z < 0 || z1 < 0)
		return (0x0c0ce8);
	return (0xffffff);
}

void	ft_isometric(t_point *p)
{
	p->x = (p->x - p->y) * cos(0.8);
	p->y = (p->x + p->y) * sin(0.8) - p->z;
}

void	transform_point(t_point *p, t_fdf *data)
{
	p->x = p->x * data->zoom;
	p->y = p->y * data->zoom;
	ft_isometric(p);
	p->x = p->x + data->shift_x;
	p->y = p->y + data->shift_y;
}
