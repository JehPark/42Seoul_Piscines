/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jehpark <jehpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 18:34:28 by jehpark           #+#    #+#             */
/*   Updated: 2021/04/14 17:00:38 by byunkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"
#include "func.h"

int		ft_isprintable(char ch)
{
	if (32 <= ch && 126 >= ch)
		return (1);
	return (0);
}

int		ft_chcheck(char *line, t_map_info *mapinfo)
{
	char ety;
	char obs;

	ety = mapinfo->empty;
	obs = mapinfo->obstacle;
	while (*line)
	{
		if ((ety != *line && obs != *line) || !ft_isprintable(*line))
			return (1);
		line++;
	}
	return (0);
}

int		ft_fcheck(char *line, int start)
{
	int i;
	int j;

	i = start;
	while (i < 3 + start)
	{
		if (!ft_isprintable(line[i]))
			return (1);
		j = i + 1;
		while (j < 3 + start)
		{
			if (line[j] == line[i])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int		ft_mkmap2(int fd, char **map, t_map_info *mi)
{
	int		idx;
	char	*word;

	idx = 0;
	word = ft_readline(fd, '\n');
	if (ft_chcheck(word, mi))
	{
		ft_errorfree(map, word, idx);
		return (-1);
	}
	mi->col = ft_strlen(word);
	map[idx++] = word;
	while (idx < mi->row)
	{
		word = ft_readline(fd, '\n');
		if (mi->col != ft_strlen(word) || ft_chcheck(word, mi) || mi->col == 0)
		{
			ft_errorfree(map, word, idx);
			return (-1);
		}
		map[idx++] = word;
	}
	return (idx);
}
