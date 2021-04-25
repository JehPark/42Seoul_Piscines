/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jehpark <jehpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 16:34:41 by jehpark           #+#    #+#             */
/*   Updated: 2021/04/05 15:11:24 by jehpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_isprime(int n)
{
	int i;

	if (n <= 2 || n % 2 == 0)
		return (n == 2 ? 1 : 0);
	i = 3;
	while (i <= n / i)
	{
		if (n % i == 0)
			return (0);
		i += 2;
	}
	return (1);
}

int		ft_find_next_prime(int nb)
{
	int i;

	if (nb <= 2)
		return (2);
	i = 0;
	while ((nb + i) < 2147483647)
	{
		if (ft_isprime(nb + i))
			return (nb + i);
		i++;
	}
	return (2147483647);
}
