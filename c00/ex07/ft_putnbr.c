/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jehpark <jehpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 14:20:37 by jehpark           #+#    #+#             */
/*   Updated: 2021/03/29 12:01:56 by jehpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_pow(int nb)
{
	int ans;
	int idx;

	idx = nb;
	ans = 1;
	while (idx > 0)
	{
		ans *= 10;
		idx--;
	}
	return (ans);
}

int		ft_getlen(int nb)
{
	int idx;

	idx = 9;
	while (idx > 0)
	{
		if (nb >= ft_pow(idx))
		{
			return (idx + 1);
		}
		idx--;
	}
	return (1);
}

void	ft_putnbr(int nb)
{
	int		length;
	int		div;
	char	ch;

	if (nb == -2147483648)
	{
		write(1, "-2", 2);
		nb += 2000000000;
		nb *= -1;
	}
	if (nb < 0)
	{
		nb *= -1;
		write(1, &"-", 1);
	}
	length = ft_getlen(nb);
	div = ft_pow(length - 1);
	while (length > 0)
	{
		ch = (nb / div) + '0';
		nb = nb - (nb / div) * div;
		write(1, &ch, 1);
		div /= 10;
		length--;
	}
}
