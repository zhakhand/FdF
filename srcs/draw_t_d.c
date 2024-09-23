/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_t_d.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzhakhan <dzhakhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 10:23:23 by dzhakhan          #+#    #+#             */
/*   Updated: 2024/09/23 10:23:24 by dzhakhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	set_utils(t_utils *utils, int param, t_data *data)
{
	if (param == 1)
	{
		utils->x2 = utils->x1 + 1;
		utils->y2 = utils->y1;
	}
	else
	{
		utils->x2 = utils->x1;
		utils->y2 = utils->y1 + 1;
	}
	utils->z1 = data->matrix[(int)utils->y1][(int)utils->x1];
	utils->z2 = data->matrix[(int)utils->y2][(int)utils->x2];
	utils->color = data->colors[(int)utils->y2][(int)utils->x2];
	if (utils->z2 < utils->z1)
		utils->color = data->colors[(int)utils->y1][(int)utils->x1];
}

static void	zoom(float *x, float *y, t_data *data)
{
	*x *= data->zoom;
	*y *= data->zoom;
}

static void	shift(float *x, float *y, t_data *data)
{
	*x += data->shift_x;
	*y += data->shift_y;
}

static void	con_dots(t_data *data, t_utils utils)
{
	int	max;

	zoom(&utils.x1, &utils.y1, data);
	zoom(&utils.x2, &utils.y2, data);
	shift(&utils.x1, &utils.y1, data);
	shift(&utils.x2, &utils.y2, data);
	data->x_step = utils.x2 - utils.x1;
	data->y_step = utils.y2 - utils.y1;
	max = ft_max(ft_abs(data->x_step), ft_abs(data->y_step));
	data->x_step /= max;
	data->y_step /= max;
	while ((int)(utils.x2 - utils.x1) || (int)(utils.y2 - utils.y1))
	{
		if (utils.x1 >= 0 && utils.x1 <= HEIGHT \
		&& utils.y1 >= 0 && utils.y1 <= WIDTH)
			*(unsigned int *)(data->addr + ((int)utils.y1 * data->ll + \
			(int)utils.x1 * (data->bpp / 8))) = utils.color;
		utils.x1 += data->x_step;
		utils.y1 += data->y_step;
	}
}

void	draw_t_d(t_data *data)
{
	t_utils	utils;

	utils.y1 = 0;
	while (utils.y1 < data->height)
	{
		utils.x1 = 0;
		while (utils.x1 < data->width)
		{
			if (utils.x1 < data->width - 1)
			{
				set_utils(&utils, 1, data);
				con_dots(data, utils);
			}
			if (utils.y1 < data->height - 1)
			{
				set_utils(&utils, 0, data);
				con_dots(data, utils);
			}
			utils.x1++;
		}
		utils.y1++;
	}
	mlx_put_image_to_window(data->mlx_ptr, data->wdw_ptr, data->img, 0, 0);
}
