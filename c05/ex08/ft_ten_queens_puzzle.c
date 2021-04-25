/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jehpark <jehpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 17:11:05 by jehpark           #+#    #+#             */
/*   Updated: 2021/04/01 18:47:15 by jehpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int g_count;

void	ft_print(int *postions)
{
	char	pos_char[11];
	int		i;

	i = 0;
	while (i < 10)
	{
		pos_char[i] = postions[i] + '0';
		i++;
	}
	pos_char[10] = '\0';
	write(1, pos_char, 10);
	write(1, "\n", 1);
}

int		ft_checkvalid(int *positions, int row, int col)
{
	int j;
	int cur_col;
	int	row_distance;
	int	col_distance;

	j = 0;
	while (j < row)
	{
		cur_col = positions[j];
		if (cur_col == col)
			return (0);
		col_distance = cur_col - col > 0 ? (cur_col - col) : (col - cur_col);
		row_distance = row - j;
		if (col_distance == row_distance)
			return (0);
		j++;
	}
	return (1);
}

void	ft_placequeens(int row, int *positions)
{
	int col;

	if (row == 10)
	{
		ft_print(positions);
		g_count++;
	}
	else
	{
		col = 0;
		while (col < 10)
		{
			if (ft_checkvalid(positions, row, col))
			{
				positions[row] = col;
				ft_placequeens(row + 1, positions);
			}
			col++;
		}
	}
}

int		ft_ten_queens_puzzle(void)
{
	int	position[10];
	int	i;

	i = 0;
	while (i < 10)
		position[i++] = 0;
	g_count = 0;
	ft_placequeens(0, position);
	return (g_count);
}
