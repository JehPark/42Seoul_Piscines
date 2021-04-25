/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jehpark <jehpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 12:50:09 by jehpark           #+#    #+#             */
/*   Updated: 2021/04/12 15:44:33 by byunkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

typedef struct	s_map_info
{
	int		row;
	int		col;
	int		size;
	char	empty;
	char	obstacle;
	char	fill;
}				t_map_info;

typedef struct	s_point
{
	int		x;
	int		y;
	int		i;
	int		j;
	int		largest;
}				t_point;

#endif
