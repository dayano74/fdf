/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayano <dayano@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 16:45:07 by dayano            #+#    #+#             */
/*   Updated: 2025/03/06 14:11:47 by dayano           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char **argv)
{
	t_fdf	*data;

	if (argc != 2)
		return (1);
	data = (t_fdf *)ft_calloc(sizeof(t_fdf), 1);
	if (!data)
		return (1);
	data->mlx_ptr = mlx_init();
	data->img_ptr = mlx_new_image(data->mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT);
	data->win_ptr = mlx_new_window(data->mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT,
			"FDF");
	data->img_data = mlx_get_data_addr(data->img_ptr, &data->bits_per_pixel,
			&data->line_length, &data->endian);
	data->zoom = 20;
	ft_read_file(argv[1], data);
	ft_calc_zoom_and_shift(data);
	ft_draw(data);
	mlx_key_hook(data->win_ptr, ft_deal_key, data);
	mlx_hook(data->win_ptr, 17, 0, ft_close_windw, data);
	mlx_loop(data->mlx_ptr);
	return (0);
}
