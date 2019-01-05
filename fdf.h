/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fviolin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/23 10:25:02 by fviolin           #+#    #+#             */
/*   Updated: 2016/04/01 14:58:04 by fviolin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <mlx.h>
# include "../libft/libft.h"
# include <stdlib.h>
# include <unistd.h>

# define WHITE 0x00FFFFFF
# define WIN_WIDTH 1500
# define WIN_HEIGHT 1500

typedef struct		s_lst
{
	int				*tab;
	int				len;
	struct s_lst	*next;
}					t_lst;

typedef struct		s_coor3d
{
	int				x;
	int				y;
	int				z;
}					t_coor3d;

typedef struct		s_coor2d
{
	int				x;
	int				y;
}					t_coor2d;

typedef struct		s_dot
{
	int				color;
	t_coor2d		coor2d;
	t_coor3d		coor3d;
}					t_dot;

typedef struct		s_map
{
	int				offsetx;
	int				offsety;
	int				padding;
	int				max_width;
	int				max_len;
	int				max_height;
}					t_map;

typedef struct		s_env
{
	void			*mlx;
	void			*win;
	int				z_factor;
	double			pers;
	t_map			map;
	t_lst			*list;
}					t_env;

int					check_line(char **str);
int					check_args(int ac, char **av);
void				init_env_default(t_env *env);
int					get_color(int dz, int z);
int					draw_map(t_env *env);
int					x_project(int x, int y, int z);
int					y_project(int x, int y, int z, t_env *env);
int					key_hook_manager(int keycode, t_env *env);
void				init_struct_env(t_lst *list, int line_flag);
t_lst				*add_node_lst(t_lst *head, char **str);
t_lst				*save_map(int fd);
void        		free_list(t_lst *node);

#endif
