/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzhakhan <dzhakhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 10:23:37 by dzhakhan          #+#    #+#             */
/*   Updated: 2024/09/23 10:23:38 by dzhakhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

static void	fill(t_data *data, int row, int column, char *num)
{
	char	**n_c;

	n_c = ft_split(num, ',');
	if (!n_c)
		end_prog(data, 2);
	if (n_c[0])
	{
		data->matrix[row][column] = ft_atoi(n_c[0]);
		if (n_c[1] && is_hex(n_c[1]))
			data->colors[row][column] = hex_to_dec(n_c[1]);
		else
		{
			if (data->matrix[row][column] == 0)
				data->colors[row][column] = WHITE;
			else if (data->matrix[row][column] > 0)
				data->colors[row][column] = RED;
			else
				data->colors[row][column] = GREEN;
		}
	}
	free_split(&n_c);
}

static void	fill_z(t_data *data, int row, char *line)
{
	char	**nums;
	int		i;

	i = 0;
	nums = ft_split(line, ' ');
	if (!nums)
		end_prog(data, 2);
	while (nums[i])
	{
		fill(data, row, i, nums[i]);
		i++;
	}
	free_split(&nums);
}

static void	fill_maps(t_data *data, char *file)
{
	int		fd;
	int		i;
	char	*line;

	fd = open(file, O_RDONLY, 0);
	line = get_next_line(fd);
	i = 0;
	while (line)
	{
		fill_z(data, i, line);
		gnl_free(&line);
		line = get_next_line(fd);
		i++;
	}
	data->matrix[i] = NULL;
	data->colors[i] = NULL;
	close(fd);
}

void	read_file(char *file, t_data *data)
{
	int		i;

	get_height(data, file);
	get_width(data, file);
	data->matrix = (int **)malloc(sizeof(int *) * (data->height + 1));
	data->colors = (int **)malloc(sizeof (int *) * (data->height + 1));
	if (!data->matrix || !data->colors)
		end_prog(data, 2);
	i = 0;
	while (i < data->height)
	{
		data->matrix[i] = (int *)malloc(sizeof(int) * (data->width + 1));
		data->colors[i] = (int *)malloc(sizeof(int) * (data->width + 1));
		if (!data->matrix[i] || !data->colors[i])
			end_prog(data, 2);
		i++;
	}
	fill_maps(data, file);
}
