/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jehpark <jehpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 20:11:22 by jehpark           #+#    #+#             */
/*   Updated: 2021/04/13 19:01:56 by jehpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		*ft_map(int *tab, int length, int (*f)(int))
{
	int idx;
	int *ans;

	idx = 0;
	ans = (int *)malloc(sizeof(int) * length);
	while (idx < length)
	{
		ans[idx] = (*f)(tab[idx]);
		idx++;
	}
	return (ans);
}
