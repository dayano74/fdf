/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayano <dayano@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 21:27:45 by dayano            #+#    #+#             */
/*   Updated: 2025/03/03 21:30:47 by dayano           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_free_lines(char **lines, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		free(lines[i]);
		i++;
	}
	free(lines);
}

char	**ft_realloc_lines(char **lines, int old_count, int new_count)
{
	char	**new_lines;
	int		i;

	new_lines = (char **)malloc(sizeof(char *) * new_count);
	if (!new_lines)
		return (NULL);
	i = 0;
	while (i < old_count)
	{
		new_lines[i] = lines[i];
		i++;
	}
	free(lines);
	return (new_lines);
}
