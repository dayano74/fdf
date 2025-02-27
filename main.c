/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayano <dayano@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 16:45:07 by dayano            #+#    #+#             */
/*   Updated: 2025/02/27 20:54:51 by dayano           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char **argv)
{
	fdf	*data;

	if (argc != 2)
		return (1);
	data = (fdf *)malloc(sizeof(fdf));
	if (!data)
		return (1);
	ft_read_file(argv[1], data);
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, 1000, 1000, "FDF");
	data->zoom = 20;
	ft_draw(data);
	mlx_key_hook(data->win_ptr, ft_deal_key, data);
	mlx_hook(data->win_ptr, 17, 0, ft_close_windw, data);
	mlx_loop(data->mlx_ptr);
	return (0);
}
