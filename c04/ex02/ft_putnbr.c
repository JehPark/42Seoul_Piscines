/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jehpark <jehpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 22:23:50 by jehpark           #+#    #+#             */
/*   Updated: 2021/04/04 21:35:03 by jehpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		ft_pow(int pow)
{
	int ans;

	ans = 1;
	while (pow)
	{
		ans *= 10;
		pow--;
	}
	return (ans);
}

int		ft_len(int nbr)
{
	int len;

	if (nbr == 0)
		return (1);
	len = 0;
	while (nbr)
	{
		len++;
		nbr /= 10;
	}
	return (len);
}

void	ft_putnbr(int nb)
{
	int		len;
	int		div;
	char	temp;

	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	if (nb < 0)
	{
		nb *= -1;
		ft_putchar('-');
	}
	len = ft_len(nb);
	div = ft_pow(len - 1);
	while (div)
	{
		temp = nb / div + '0';
		ft_putchar(temp);
		nb -= (nb / div) * div;
		div /= 10;
	}
}
