/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayano <dayano@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 11:53:40 by dayano            #+#    #+#             */
/*   Updated: 2025/03/06 19:42:07 by dayano           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	ft_fill_line(int *z_line, int *color_line, char *line)
{
	char	**tokens;
	int		i;
	char	*comma_ptr;

	tokens = ft_split(line, ' ');
	i = 0;
	while (tokens[i])
	{
		comma_ptr = ft_strchr(tokens[i], ',');
		if (comma_ptr)
		{
			*comma_ptr = '\0';
			z_line[i] = ft_atoi(tokens[i]);
			color_line[i] = (int)ft_strtol(comma_ptr + 1, NULL, 16);
		}
		else
		{
			z_line[i] = ft_atoi(tokens[i]);
			color_line[i] = -1;
		}
		free(tokens[i]);
		i++;
	}
	free(tokens);
}

void	ft_append_line(char ***lines, int *line_count, char *line)
{
	char	**tmp;

	tmp = ft_realloc_lines(*lines, *line_count, *line_count + 1);
	if (!tmp)
	{
		perror("Allocation error\n");
		free(line);
		if (*lines)
			ft_free_lines(*lines, *line_count);
		exit(EXIT_FAILURE);
	}
	*lines = tmp;
	(*lines)[(*line_count)++] = line;
}

static char	**ft_read_lines(char *file_name, int *line_count)
{
	char	**lines;
	char	*line;
	int		fd;

	lines = NULL;
	*line_count = 0;
	fd = ft_open_file(file_name);
	line = get_next_line(fd);
	while (line != NULL)
	{
		ft_append_line(&lines, line_count, line);
		line = get_next_line(fd);
	}
	close(fd);
	return (lines);
}

static int	**ft_alloc_matrix(int height, int width)
{
	int	**matrix;
	int	i;

	matrix = (int **)malloc(sizeof(int *) * height);
	if (!matrix)
		exit(EXIT_FAILURE);
	i = 0;
	while (i < height)
	{
		matrix[i] = (int *)ft_calloc(sizeof(int), width);
		if (!matrix[i])
		{
			while (--i >= 0)
				free(matrix[i]);
			free(matrix);
			exit(EXIT_FAILURE);
		}
		i++;
	}
	return (matrix);
}

void	ft_read_file(char *file_name, t_fdf *data)
{
	char	**lines;
	int		line_count;
	int		i;

	lines = ft_read_lines(file_name, &line_count);
	if (line_count == 0)
	{
		data->height = 0;
		data->width = 0;
		data->z_matrix = NULL;
		data->color_martix = NULL;
		return ;
	}
	data->height = line_count;
	data->width = ft_count_words(lines[0], ' ');
	data->z_matrix = ft_alloc_matrix(data->height, data->width);
	data->color_martix = ft_alloc_matrix(data->height, data->width);
	i = 0;
	while (i < data->height)
	{
		ft_fill_line(data->z_matrix[i], data->color_martix[i], lines[i]);
		free(lines[i]);
		i++;
	}
	free(lines);
}
