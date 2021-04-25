/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jehpark <jehpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 13:11:51 by jehpark           #+#    #+#             */
/*   Updated: 2021/04/07 16:56:23 by jehpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	ft_intcpy(int *arr, int min, int max)
{
	int idx;

	idx = 0;
	while (min < max)
		arr[idx++] = min++;
}

int		ft_ultimate_range(int **range, int min, int max)
{
	long	size;

	if (min >= max)
	{
		*range = 0;
		return (0);
	}
	size = (long)(max - min);
	*range = (int *)malloc(sizeof(int) * size);
	if (!*range)
		return (-1);
	ft_intcpy(*range, min, max);
	return (size);
}
