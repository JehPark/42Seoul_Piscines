/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jehpark <jehpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 15:55:55 by jehpark           #+#    #+#             */
/*   Updated: 2021/04/05 15:01:19 by jehpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

long	ft_sqrt(int nb)
{
	long	i;

	if (nb <= 0)
		return (0);
	if (nb == 1)
		return (nb);
	i = 2;
	while (i * i <= nb)
		i++;
	return ((int)(i));
}

int		ft_is_prime(int nb)
{
	int	sqrt;
	int	i;

	if (nb <= 2 || nb % 2 == 0)
		return (nb == 2 ? 1 : 0);
	sqrt = ft_sqrt(nb);
	i = 3;
	while (i <= sqrt)
	{
		if (nb % i == 0)
			return (0);
		i += 2;
	}
	return (1);
}
