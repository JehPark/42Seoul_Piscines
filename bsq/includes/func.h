/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jehpark <jehpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 12:04:43 by jehpark           #+#    #+#             */
/*   Updated: 2021/04/14 16:55:20 by byunkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNC_H
# define FUNC_H

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include "map.h"

void	ft_std_input(int fd, t_map_info map_info, char **map);
void	ft_other_input(char *argv, int fd, t_map_info map_info, char **map);
void	ft_freemap(char **map, t_map_info *mapinfo);
int		**ft_dp_alloc(t_map_info *mapinfo);
void	ft_core_logic(t_point *point, char **map,
		t_map_info *mapinfo, int **dp);
int		ft_maximalsquare(t_point *point, char **map, t_map_info *mapinfo);
void	ft_display(char **map, int row);
void	ft_fillmap(char **map, t_map_info *mapinfo);
char	*ft_readline(int fd, char c);
int		ft_mkinfo(int fd, t_map_info *mapinfo);
int		ft_check_error(int fd);
void	ft_errorfree(char **map, char *word, int idx);
char	**ft_mkmap(int fd, t_map_info *mi);
int		ft_mkmap2(int fd, char **map, t_map_info *mi);
int		ft_isprintable(char ch);
int		ft_chcheck(char *line, t_map_info *mapinfo);
int		ft_fcheck(char *line, int start);

void	ft_error_msg(void);
int		ft_m(int n1, int n2);
int		ft_natoi(char *nbr, int n);
void	ft_putstr(char *str);
char	*ft_strcat(char *dest, char *src);
char	*ft_strncat(char *dest, char *src, int n);
int		ft_strlen(char *str);

#endif
