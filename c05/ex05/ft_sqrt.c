/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jehpark <jehpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 15:41:39 by jehpark           #+#    #+#             */
/*   Updated: 2021/04/05 15:17:36 by jehpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_sqrt(int nb)
{
	long long i;

	if (nb <= 0)
		return (0);
	i = 0;
	while (i * i < nb)
		i++;
	if (i * i == nb)
		return ((int)i);
	return (0);
}
