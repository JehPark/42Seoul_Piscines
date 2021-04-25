/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logic.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jehpark <jehpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 14:48:25 by jehpark           #+#    #+#             */
/*   Updated: 2021/04/12 23:06:27 by jehpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "func.h"
#include "map.h"

int		**ft_dp_alloc(t_map_info *mapinfo)
{
	int		**dp;
	int		i;

	dp = (int **)malloc(sizeof(int *) * (mapinfo->row + 1));
	i = 0;
	while (i < mapinfo->row + 1)
		dp[i++] = (int *)malloc(sizeof(int) * (mapinfo->col + 1));
	i = 0;
	while (i < mapinfo->row + 1)
		dp[i++][0] = 0;
	i = 0;
	while (i < mapinfo->col + 1)
		dp[0][i++] = 0;
	return (dp);
}

void	ft_core_logic(t_point *point, char **map, t_map_info *mapinfo, int **dp)
{
	int	i;
	int	j;

	i = point->i;
	j = point->j;
	if (map[i - 1][j - 1] == mapinfo->obstacle)
		dp[i][j] = 0;
	else if (map[i - 1][j - 1] == mapinfo->empty)
		dp[i][j] = 1 + ft_m(dp[i - 1][j], ft_m(dp[i][j - 1], dp[i - 1][j - 1]));
	if (point->largest < dp[i][j])
	{
		point->x = i - 1;
		point->y = j - 1;
		point->largest = dp[i][j];
	}
}

int		ft_maximalsquare(t_point *point, char **map, t_map_info *mapinfo)
{
	int		**dp;
	int		i;
	int		j;

	point->largest = 0;
	dp = ft_dp_alloc(mapinfo);
	i = 1;
	while (i <= mapinfo->row)
	{
		j = 1;
		while (j <= mapinfo->col)
		{
			point->i = i;
			point->j = j;
			ft_core_logic(point, map, mapinfo, dp);
			j++;
		}
		i++;
	}
	i = 0;
	while (i < mapinfo->row + 1)
		free(dp[i++]);
	free(dp);
	return (point->largest);
}

void	ft_display(char **map, int row)
{
	int i;

	i = 0;
	while (i < row)
	{
		ft_putstr(map[i++]);
		write(1, "\n", 1);
	}
}

void	ft_fillmap(char **map, t_map_info *mapinfo)
{
	t_point		end;
	int			largest;
	int			i;
	int			j;

	end.x = 0;
	end.y = 0;
	largest = ft_maximalsquare(&end, map, mapinfo);
	i = 0;
	while (i < largest)
	{
		j = 0;
		while (j < largest)
		{
			map[end.x - i][end.y - j] = mapinfo->fill;
			j++;
		}
		i++;
	}
	ft_display(map, mapinfo->row);
}
