/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deal_key.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayano <dayano@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 18:45:28 by dayano            #+#    #+#             */
/*   Updated: 2025/03/04 16:40:39 by dayano           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_free_data(t_fdf *data)
{
	int	i;

	i = 0;
	while (i < data->height)
	{
		free(data->z_matrix[i]);
		i++;
	}
	free(data->z_matrix);
	free(data->mlx_ptr);
	free(data);
}

int	ft_close_windw(t_fdf *data)
{
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_display(data->mlx_ptr);
	ft_free_data(data);
	exit(EXIT_SUCCESS);
	return (0);
}

int	ft_deal_key(int key, t_fdf *data)
{
	if (key == 65307)
		ft_close_windw(data);
	if (key == 65362)
		data->shift_y -= 10;
	if (key == 65364)
		data->shift_y += 10;
	if (key == 65363)
		data->shift_x += 10;
	if (key == 65361)
		data->shift_x -= 10;
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	ft_draw(data);
	return (0);
}
