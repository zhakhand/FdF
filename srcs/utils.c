/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzhakhan <dzhakhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 10:23:39 by dzhakhan          #+#    #+#             */
/*   Updated: 2024/09/23 10:23:40 by dzhakhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

float	ft_max(float a, float b)
{
	if (a > b)
		return (a);
	return (b);
}

float	ft_abs(float x)
{
	if (x < 0)
		return (-x);
	return (x);
}

void	get_height(t_data *data, char *file)
{
	int		fd;
	char	*line;

	fd = open(file, O_RDONLY, 0);
	line = get_next_line(fd);
	if (!line)
		end_prog(data, 4);
	while (line)
	{
		data->height++;
		gnl_free(&line);
		line = get_next_line(fd);
	}
	close(fd);
}

void	get_width(t_data *data, char *file)
{
	int		fd;
	int		width;
	char	*line;

	fd = open(file, O_RDONLY, 0);
	line = get_next_line(fd);
	if (!line)
		end_prog(data, 4);
	data->width = ft_wrdcount(line, ' ');
	gnl_free(&line);
	line = get_next_line(fd);
	while (line)
	{
		width = ft_wrdcount(line, ' ');
		if (data->width > width)
			end_prog(data, 4);
		gnl_free(&line);
		line = get_next_line(fd);
	}
	close(fd);
}

int	ft_wrdcount(char const *str, char c)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (*(str + i))
	{
		if (*(str + i) != c)
		{
			count++;
			while (*(str + i) && (*(str + i) != c))
				i++;
		}
		else if (*(str + i) == c)
			i++;
	}
	return (count);
}
