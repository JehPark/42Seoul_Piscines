/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jehpark <jehpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 12:38:11 by jehpark           #+#    #+#             */
/*   Updated: 2021/04/07 16:59:02 by jehpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		*ft_range(int min, int max)
{
	long	size;
	int		*arr;
	int		*temp;

	if (min >= max)
		return (int *)(0);
	size = (max - min) > 0 ? (long)(max - min) : 0;
	arr = (int *)malloc(sizeof(int) * size);
	if (!arr)
		return (arr);
	temp = arr;
	while (min < max)
		*temp++ = min++;
	return (arr);
}
