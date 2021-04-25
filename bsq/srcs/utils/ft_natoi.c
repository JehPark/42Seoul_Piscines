/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_natoi.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jehpark <jehpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 13:27:17 by jehpark           #+#    #+#             */
/*   Updated: 2021/04/11 14:25:47 by jehpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "func.h"

int		ft_natoi(char *nbr, int n)
{
	int	ans;
	int	idx;

	ans = 0;
	idx = 0;
	while (*nbr && idx < n)
	{
		if (*nbr > '9' || *nbr < '0')
			return (0);
		ans *= 10;
		ans += *nbr - '0';
		idx++;
		nbr++;
	}
	return (ans);
}
