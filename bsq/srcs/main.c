/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jehpark <jehpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 14:17:13 by jehpark           #+#    #+#             */
/*   Updated: 2021/04/14 21:50:48 by byunkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"
#include "func.h"

void	ft_std_input(int fd, t_map_info map_info, char **map)
{
	if (fd == -1)
		ft_error_msg();
	else
	{
		map = ft_mkmap(fd, &map_info);
		if (map)
		{
			ft_fillmap(map, &map_info);
			ft_freemap(map, &map_info);
		}
		else
			ft_error_msg();
	}
}

void	ft_other_input(char *argv, int fd, t_map_info map_info, char **map)
{
	fd = open(argv, O_RDONLY);
	if (fd == -1)
		ft_error_msg();
	else
	{
		map = ft_mkmap(fd, &map_info);
		if (map)
		{
			ft_fillmap(map, &map_info);
			ft_freemap(map, &map_info);
		}
		else
			ft_error_msg();
	}
}

void	ft_freemap(char **map, t_map_info *mapinfo)
{
	int i;

	i = 0;
	while (i < mapinfo->row)
		free(map[i++]);
	free(map);
}

int		main(int argc, char **argv)
{
	int				fd;
	int				idx;
	char			**map;
	t_map_info		map_info;

	idx = 1;
	fd = 0;
	map = 0;
	map_info.col = 0;
	if (argc > 0)
	{
		if (argc == 1)
			ft_std_input(fd, map_info, map);
		while (idx < argc)
		{
			ft_other_input(argv[idx], fd, map_info, map);
			idx++;
			close(fd);
			if (idx == argc)
				break ;
			write(1, "\n", 1);
		}
	}
	exit(0);
}
