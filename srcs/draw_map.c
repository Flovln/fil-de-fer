/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fviolin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/28 12:03:25 by fviolin           #+#    #+#             */
/*   Updated: 2016/03/30 11:43:20 by fviolin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

static t_dot	create_dot(int x, int y, int z, t_env *env)
{
	t_dot dot;

	dot.coor3d.x = x * env->map.padding;
	dot.coor3d.y = y * env->map.padding;
	dot.coor3d.z = z * env->z_factor;
	dot.coor2d.x = x_project(dot.coor3d.x, dot.coor3d.y, dot.coor3d.z) +
		env->map.offsetx;
	dot.coor2d.y = y_project(dot.coor3d.x, dot.coor3d.y, dot.coor3d.z, env) +
		env->map.offsety;
	return (dot);
}

static void		draw_segment(t_dot dot1, t_dot dot2, t_env *env)
{
	int		dx;
	int		dy;
	double	x;
	int		y;

	x = dot1.coor2d.x;
	dx = dot2.coor2d.x - dot1.coor2d.x;
	dy = dot2.coor2d.y - dot1.coor2d.y;
	dot1.color = get_color(dot1.coor3d.z, dot2.coor3d.z);
	while (x < dot2.coor2d.x)
	{
		y = dot1.coor2d.y + dy * (x - dot1.coor2d.x) / dx;
		mlx_pixel_put(env->mlx, env->win, x, y, dot1.color);
		x += 0.3;
	}
}

static void		manage_drawing(t_env *env, t_lst *tmp, int i, int j)
{
	t_dot dot[2];

	dot[0] = create_dot(i, j, tmp->tab[i], env);
	if (i + 1 < tmp->len)
	{
		dot[1] = create_dot(i + 1, j, tmp->tab[i + 1], env);
		draw_segment(dot[0], dot[1], env);
	}
	if (tmp->next)
	{
		dot[1] = create_dot(i, j + 1, tmp->next->tab[i], env);
		draw_segment(dot[0], dot[1], env);
	}
}

int				draw_map(t_env *env)
{
	int		i;
	int		j;
	t_lst	*tmp;

	tmp = env->list;
	j = 0;
	while (tmp)
	{
		i = 0;
		while (i < tmp->len)
		{
			manage_drawing(env, tmp, i, j);
			i++;
		}
		j++;
		tmp = tmp->next;
	}
	return (0);
}
