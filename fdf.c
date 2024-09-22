#include "./include/fdf.h"

static void	create_img(t_data *data)
{
	data->img = mlx_new_image(data->mlx_ptr, HEIGHT, WIDTH);
	if (!data->img)
		end_prog(data, 2);
	data->addr = mlx_get_data_addr(data->img, \
	&data->bpp, &data->ll, &data->end);
}

void	init_data(t_data *data)
{
	data->height = 0;
	data->width = 0;
	data->x_step = 0;
	data->y_step = 0;
	data->zoom = 40;
	data->angle = 0.8;
	data->shift_x = 300;
	data->shift_y = 300;
	data->img = NULL;
	data->addr = NULL;
	data->colors = NULL;
	data->matrix = NULL;
	data->mlx_ptr = NULL;
	data->wdw_ptr = NULL;
}

int	handle_key(int key, t_data *data)
{
	if (key == XK_Escape)
		close_prog(data);
	if (key == XK_Up || key == XK_Down)
		handle_zoom(key, data);
	if (key == XK_w || key == XK_W || key == XK_a || key == XK_A \
	|| key == XK_d || key == XK_D || key == XK_s || key == XK_S)
		handle_translation(key, data);
	if (key == XK_e || key == XK_E || key == XK_q || key == XK_Q)
		handle_rotation(key, data);
	if (key == XK_t || key == XK_T)
	{
		handle_top_down(data);
		return (0);
	}
	mlx_destroy_image(data->mlx_ptr, data->img);
	create_img(data);
	mlx_clear_window(data->mlx_ptr, data->wdw_ptr);
	draw(data);
	return (0);
}

int	main(int ac, char **av)
{
	t_data	*data;

	if (ac != 2)
		return (0);
	data = malloc(sizeof(t_data));
	if (!data)
		end_prog(data, 2);
	init_data(data);
	read_file(av[1], data);
	data->mlx_ptr = mlx_init();
	if (!data->mlx_ptr)
		end_prog(data, 2);
	data->wdw_ptr = mlx_new_window(data->mlx_ptr, HEIGHT, WIDTH, "Fil de Fer");
	if (!data->wdw_ptr)
		end_prog(data, 2);
	create_img(data);
	draw(data);
	mlx_key_hook(data->wdw_ptr, handle_key, data);
	mlx_hook(data->wdw_ptr, DestroyNotify, \
	StructureNotifyMask, &close_prog, data);
	mlx_loop(data->mlx_ptr);
	close_prog(data);
}
