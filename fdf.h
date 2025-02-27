/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayano <dayano@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 11:48:42 by dayano            #+#    #+#             */
/*   Updated: 2025/02/26 19:48:32 by dayano           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <fcntl.h>     // Definition of open
# include <sys/stat.h>  // Definition of file attributes
# include <sys/types.h> // Definition of mode
# include <unistd.h>    // Definition of close
//
# include "libft/incs/libft.h"
# include "minilibx-linux/mlx.h"
# include <math.h>
//
# include <stdio.h> // for Debug

typedef struct
{
	int		width;
	int		height;
	int		**z_matrix;
	int		zoom;
	int		color;

	int		shift_x;
	int		shift_y;

	float	rotation;
	void	*mlx_ptr;
	void	*win_ptr;
}			fdf;

void		ft_read_file(char *file_name, fdf *data);
int			ft_count_words(const char *s, char c);
void		ft_bresenham(float x, float y, float x1, float y1, fdf *data);
float		ft_max(float a, float b);
float		ft_mod(float i);
int			ft_select_color(int z, int z1);
void		ft_draw(fdf *data);
int			ft_deal_key(int key, fdf *data);
int			ft_close_windw(fdf *data);
void		ft_free_data(fdf *data);

#endif
