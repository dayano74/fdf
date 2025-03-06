/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayano <dayano@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 11:48:42 by dayano            #+#    #+#             */
/*   Updated: 2025/03/06 18:11:21 by dayano           ###   ########.fr       */
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
# include <float.h>
# include <math.h>
//
# include <stdio.h> // for Debug

# define ISO_ANGLE 0.523599f
# define WINDOW_WIDTH 1980
# define WINDOW_HEIGHT 1080
# define ISO_ANGLE 0.523599f
# define MAX_Z_SCALE 10.0f

typedef struct s_fdf
{
	int		width;
	int		height;
	int		**z_matrix;
	int		**color_martix;
	float	z_scale;
	float	zoom;
	int		color;

	int		shift_x;
	int		shift_y;

	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;
	void	*img_data;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_fdf;

typedef struct s_point
{
	float	x;
	float	y;
	int		z;
	int		color;

}			t_point;

void		ft_read_file(char *file_name, t_fdf *data);
int			ft_count_words(const char *s, char c);
int			ft_open_file(char *file_name);
void		ft_free_lines(char **lines, int count);
char		**ft_realloc_lines(char **lines, int old_count, int new_count);
float		ft_max(float a, float b);
float		ft_mod(float i);
void		ft_init_line_points(t_point *p, t_fdf *data, float x, float y);
int			ft_select_color(int z, int z1);
void		ft_isometric(t_point *p, t_fdf *data);
void		ft_transform_point(t_point *p, t_fdf *data);
void		ft_draw(t_fdf *data);
int			ft_deal_key(int key, t_fdf *data);
int			ft_close_windw(t_fdf *data);
void		ft_free_data(t_fdf *data);
// ft_calc_bounding_box.c
void		ft_calc_bounding_box(t_fdf *data, float *min_x, float *max_x,
				float *min_y, float *max_y);
void		ft_calc_zoom_and_shift(t_fdf *data);

#endif
