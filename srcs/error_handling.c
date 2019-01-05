/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fviolin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/26 13:47:16 by fviolin           #+#    #+#             */
/*   Updated: 2016/04/01 14:50:22 by fviolin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int		check_line(char **str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(*str[i]) && *str[i] != '-')
		{
			ft_putendl_fd("error: unvalid map", 2);
			return (1);
		}
		i++;
	}
	return (0);
}

int		check_args(int ac, char **av)
{
	int		fd;

	if (ac > 2)
	{
		ft_putendl_fd("error: too many arguments", 2);
		exit(1);
	}
	else if (ac < 2)
	{
		ft_putendl_fd("error: wrong usage, specify a map", 2);
		exit(1);
	}
	if ((fd = open(av[1], O_RDONLY)) < 0)
	{
		ft_putendl_fd("error: opening error", 2);
		exit(1);
	}
	return (fd);
}
