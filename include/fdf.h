/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzhakhan <dzhakhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 10:23:06 by dzhakhan          #+#    #+#             */
/*   Updated: 2024/09/23 10:23:07 by dzhakhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

//# include "../minilibx-linux/mlx.h"
# include <X11/keysym.h>
# include <X11/X.h>
# include "../libft/libft.h"
# include <fcntl.h>
# include <mlx.h>
# include <math.h>

# define HEIGHT 1400
# define WIDTH	1400
# define WHITE 0xFFFFFF
# define GREEN 0x8FCE00
# define RED 0xF44336

typedef struct s_data
{
	void	*mlx_ptr;
	void	*wdw_ptr;
	/*Maps*/
	int		**matrix;
	int		**colors;
	int		height;
	int		width;
	/*Img*/
	void	*img;
	char	*addr;
	int		bpp;
	int		ll;
	int		end;
	/*Utils*/
	float	x_step;
	float	y_step;
	int		zoom;
	float	angle;
	int		shift_x;
	int		shift_y;
}				t_data;

typedef struct s_utils
{
	float	x1;
	float	y1;
	float	x2;
	float	y2;
	int		z1;
	int		z2;
	int		color;
}				t_utils;

/*Init*/
void	init_data(t_data *data);
void	set_utils(t_utils *utils, int param, t_data *data);
/*Reading map*/
void	read_file(char *file, t_data *data);
/*Utils*/
int		ft_wrdcount(char const *str, char c);
void	get_width(t_data *data, char *file);
void	get_height(t_data *data, char *file);
float	ft_abs(float x);
float	ft_max(float a, float b);
int		is_hex(char *str);
int		hex_to_dec(char *hex);
/*Frees*/
void	free_split(char ***arr);
void	free_map(int ***arr);
/*Events*/
int		handle_key(int key, t_data *data);
void	handle_translation(int key, t_data *data);
void	handle_rotation(int key, t_data *data);
void	handle_zoom(int key, t_data *data);
void	handle_top_down(t_data *data);
/*Drawing*/
void	draw(t_data *data);
void	draw_t_d(t_data *data);
/*Closing*/
int		end_prog(t_data *data, int err_no);
int		close_prog(t_data *data);

#endif
