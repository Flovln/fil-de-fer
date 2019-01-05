/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fviolin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/24 13:53:50 by fviolin           #+#    #+#             */
/*   Updated: 2016/04/01 14:10:10 by fviolin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int				get_color(int z1, int z2)
{
	if (z1 > 0 && z2 > 0)
		return (0xFF4B00);
	else if (z1 > 0 || z2 > 0)
		return (0xFF9500);
	else if (z1 < 0 && z2 < 0)
		return (0x080CFF);
	else if (z1 < 0 || z2 < 0)
		return (0x0875FF);
	return (WHITE);
}

static int		count_node_length(t_lst *head)
{
	while (head->next)
	{
		if (head->len != head->next->len)
			return (1);
		else
			head = head->next;
	}
	return (0);
}

static int		is_list_valid(t_lst *head)
{
	if (!head)
		return (1);
	if (count_node_length(head) == 1)
		return (1);
	return (0);
}

int				main(int ac, char **av)
{
	t_env	env;
	int		fd;

	fd = check_args(ac, av);
	ft_memset(&env, 0, sizeof(env));
	env.list = save_map(fd);
	if (is_list_valid(env.list) == 1)
	{
		ft_putendl("Invalid file");
		return (0);
	}
	close(fd);
	init_env_default(&env);
	env.mlx = mlx_init();
	env.win = mlx_new_window(env.mlx, WIN_WIDTH, WIN_HEIGHT, "my fdf");
	mlx_key_hook(env.win, key_hook_manager, &env);
	mlx_expose_hook(env.win, draw_map, &env);
	mlx_loop(env.mlx);
	return (0);
}
