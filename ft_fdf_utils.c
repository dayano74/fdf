/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayano <dayano@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 15:16:14 by dayano            #+#    #+#             */
/*   Updated: 2025/02/26 19:48:21 by dayano           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft/incs/libft.h"

int	ft_count_words(const char *s, char c)
{
	int	count;
	int	in_word;

	count = 0;
	in_word = 0;
	if (s == NULL)
		return (0);
	while (*s)
	{
		if (*s != c && !in_word)
		{
			in_word = 1;
			count++;
		}
		else if (*s == c)
			in_word = 0;
		s++;
	}
	return (count);
}

float	ft_max(float a, float b)
{
	if (a > b)
		return (a);
	return (b);
}

float	ft_mod(float i)
{
	if (i < 0)
		return (-i);
	return (i);
}

int	ft_select_color(int z, int z1)
{
	if (z || z1)
		return (0xe80c0c);
	return (0xffffff);
}
