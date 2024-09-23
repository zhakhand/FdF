/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   closing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzhakhan <dzhakhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 10:23:20 by dzhakhan          #+#    #+#             */
/*   Updated: 2024/09/23 10:23:21 by dzhakhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

static char	*err(int err_no)
{
	if (err_no == 2)
		return ("malloc failed");
	else if (err_no == 3)
		return ("invalid input");
	else if (err_no == 4)
		return ("coudln't open file");
	else
		return ("error");
}

int	end_prog(t_data *data, int err_no)
{
	if (err_no != 0)
		perror(err(err_no));
	if (!data)
		exit (err_no);
	if (data->mlx_ptr)
	{
		if (data->wdw_ptr)
			mlx_destroy_window(data->mlx_ptr, data->wdw_ptr);
		if (data->img)
			mlx_destroy_image(data->mlx_ptr, data->img);
		mlx_destroy_display(data->mlx_ptr);
		free(data->mlx_ptr);
	}
	if (data->matrix)
		free_map(&data->matrix);
	if (data->colors)
		free_map(&data->colors);
	free(data);
	exit(err_no);
}

int	close_prog(t_data *data)
{
	return (end_prog(data, 0));
}
