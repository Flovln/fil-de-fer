/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projections.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fviolin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/28 12:07:35 by fviolin           #+#    #+#             */
/*   Updated: 2016/03/29 21:06:13 by fviolin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int		x_project(int x, int y, int z)
{
	t_dot dot;

	z = 0;
	dot.coor2d.x = x + y;
	return (dot.coor2d.x);
}

int		y_project(int x, int y, int z, t_env *env)
{
	t_dot dot;

	dot.coor2d.y = (y * env->pers) - (env->pers * (x + z));
	return (dot.coor2d.y);
}
