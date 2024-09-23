/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzhakhan <dzhakhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 10:23:29 by dzhakhan          #+#    #+#             */
/*   Updated: 2024/09/23 10:23:30 by dzhakhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

static void	create_img(t_data *data)
{
	data->img = mlx_new_image(data->mlx_ptr, HEIGHT, WIDTH);
	if (!data->img)
		end_prog(data, 2);
	data->addr = mlx_get_data_addr(data->img, \
	&data->bpp, &data->ll, &data->end);
}

void	handle_top_down(t_data *data)
{
	mlx_destroy_image(data->mlx_ptr, data->img);
	create_img(data);
	mlx_clear_window(data->mlx_ptr, data->wdw_ptr);
	draw_t_d(data);
}

void	handle_zoom(int key, t_data *data)
{
	if (key == XK_Up)
		data->zoom += 2;
	if (key == XK_Down)
		data->zoom -= 2;
}

void	handle_rotation(int key, t_data *data)
{
	if (key == XK_e || key == XK_E)
		data->angle += 0.1;
	if (key == XK_q || key == XK_Q)
		data->angle -= 0.1;
}

void	handle_translation(int key, t_data *data)
{
	if (key == XK_w || key == XK_W)
		data->shift_y -= 40;
	if (key == XK_s || key == XK_S)
		data->shift_y += 40;
	if (key == XK_a || key == XK_A)
		data->shift_x -= 40;
	if (key == XK_d || key == XK_D)
		data->shift_x += 40;
}
