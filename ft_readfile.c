/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readfile.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayano <dayano@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 11:53:40 by dayano            #+#    #+#             */
/*   Updated: 2025/02/26 18:30:07 by dayano           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_get_height(char *file_name)
{
	char	*line;
	int		height;
	int		fd;

	fd = open(file_name, O_RDONLY, 0);
	height = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		height++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (height);
}

int	ft_get_width(char *file_name)
{
	char	*line;
	int		width;
	int		fd;

	fd = open(file_name, O_RDONLY, 0);
	line = get_next_line(fd);
	width = ft_count_words(line, ' ');
	free(line);
	close(fd);
	return (width);
}

void	ft_fill_matrix(int *z_line, char *line)
{
	char	**nums;
	int		i;

	nums = ft_split(line, ' ');
	i = 0;
	while (nums[i])
	{
		z_line[i] = ft_atoi(nums[i]);
		free(nums[i]);
		i++;
	}
	free(nums);
}

void	ft_read_file(char *file_name, fdf *data)
{
	int		fd;
	char	*line;
	int		i;

	data->height = ft_get_height(file_name);
	data->width = ft_get_width(file_name);
	data->z_matrix = (int **)malloc(sizeof(int *) * (data->height + 1));
	i = 0;
	while (i < data->height)
	{
		data->z_matrix[i] = (int *)malloc(sizeof(int) * (data->width));
		i++;
	}
	fd = open(file_name, O_RDONLY, 0);
	i = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		ft_fill_matrix(data->z_matrix[i], line);
		// free(line);
		line = get_next_line(fd);
		i++;
	}
	close(fd);
	data->z_matrix[i] = NULL;
}
