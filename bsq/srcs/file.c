/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jehpark <jehpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 11:27:23 by jehpark           #+#    #+#             */
/*   Updated: 2021/04/14 17:00:50 by byunkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"
#include "func.h"

char		*ft_readline(int fd, char c)
{
	char	ch;
	char	*temp;
	char	*line;
	int		len;

	line = (char *)malloc(1);
	line[0] = '\0';
	len = 0;
	while (read(fd, &ch, 1) > 0 && ch != c)
	{
		len++;
		temp = line;
		line = (char *)malloc(sizeof(char) * (len + 1));
		line[0] = '\0';
		ft_strcat(line, temp);
		ft_strncat(line, &ch, 1);
		free(temp);
	}
	line[len] = '\0';
	return (line);
}

int			ft_mkinfo(int fd, t_map_info *mapinfo)
{
	char		*fline;
	int			len;

	fline = ft_readline(fd, '\n');
	len = ft_strlen(fline);
	if (len < 4)
	{
		free(fline);
		return (0);
	}
	mapinfo->row = ft_natoi(fline, len - 3);
	if (!(mapinfo->row) || ft_fcheck(fline, len - 3))
	{
		free(fline);
		return (0);
	}
	mapinfo->empty = fline[len - 3];
	mapinfo->obstacle = fline[len - 2];
	mapinfo->fill = fline[len - 1];
	free(fline);
	return (1);
}

int			ft_check_error(int fd)
{
	char	*temp;

	temp = (char *)malloc(sizeof(char));
	temp[0] = '\0';
	if (read(fd, temp, 1) > 0)
	{
		free(temp);
		return (1);
	}
	free(temp);
	return (0);
}

void		ft_errorfree(char **map, char *word, int idx)
{
	int i;

	i = 0;
	free(word);
	while (i < idx)
		free(map[i++]);
	free(map);
}

char		**ft_mkmap(int fd, t_map_info *mi)
{
	char	**map;
	int		idx;

	if (!ft_mkinfo(fd, mi))
		return (0);
	map = (char **)malloc(sizeof(char *) * (mi->row + 1));
	idx = ft_mkmap2(fd, map, mi);
	if (idx == -1)
		return (0);
	if (ft_check_error(fd))
		return (0);
	map[idx] = 0;
	return (map);
}
