/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fviolin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/26 14:23:10 by fviolin           #+#    #+#             */
/*   Updated: 2016/03/30 13:50:37 by fviolin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void			free_list(t_lst *node)
{
	t_lst *next;

	while (node)
	{
		next = node->next;
		if (node->tab)
			free(node->tab);
		free(node);
		node = next;
	}
	node = NULL;
}

static int		*str_tab_to_int_tab(char **str, int len)
{
	int	*new_tab;
	int	i;

	i = 0;
	if (!(new_tab = malloc(sizeof(int) * len)))
		return (NULL);
	while (i < len)
	{
		new_tab[i] = ft_atoi(str[i]);
		i++;
	}
	return (new_tab);
}

static t_lst	*create_node(char **str)
{
	t_lst *new;

	if (!(new = malloc(sizeof(t_lst))))
		return (NULL);
	new->len = ft_tablen(str);
	new->tab = str_tab_to_int_tab(str, new->len);
	new->next = NULL;
	return (new);
}

static void		list_push_node(t_lst **head, t_lst *new_node)
{
	t_lst *cur;

	if (!*head)
	{
		*head = new_node;
		return ;
	}
	cur = *head;
	while (cur->next)
		cur = cur->next;
	cur->next = new_node;
}

t_lst			*save_map(int fd)
{
	char	*line;
	char	**str;
	t_lst	*list;

	line = NULL;
	str = NULL;
	list = NULL;
	while (get_next_line(fd, &line) > 0)
	{
		str = ft_strsplit(line, ' ');
		if (!*str)
		{
			ft_putendl_fd("error: unvalid map", 2);
			exit(1);
		}
		if (check_line(str) == 1)
			exit(1);
		list_push_node(&list, create_node(str));
		free(str);
	}
	return (list);
}
