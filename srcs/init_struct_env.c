/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct_env.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fviolin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/01 14:05:43 by fviolin           #+#    #+#             */
/*   Updated: 2016/04/01 14:08:57 by fviolin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

static int		count_max_height(t_lst *list)
{
	int i;
	int max;

	max = 0;
	while (list)
	{
		i = 0;
		while (i < list->len)
		{
			if (max < list->tab[i])
				max = list->tab[i];
			i++;
		}
		list = list->next;
	}
	return (max);
}

static int		count_list_length(t_lst *head)
{
	int i;

	i = 0;
	while (head)
	{
		i++;
		head = head->next;
	}
	return (i);
}

void			init_env_default(t_env *env)
{
	env->z_factor = 5;
	env->map.offsetx = 200;
	env->map.offsety = 500;
	env->map.max_height = count_max_height(env->list);
	env->map.max_len = env->list->len;
	env->map.max_width = count_list_length(env->list);
	env->map.padding = WIN_WIDTH /
		(((env->map.max_len + env->map.max_width) / 2) * 3);
	env->pers = 0.5;
}
