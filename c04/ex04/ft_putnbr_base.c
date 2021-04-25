/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jehpark <jehpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 11:18:58 by jehpark           #+#    #+#             */
/*   Updated: 2021/04/05 12:33:08 by jehpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char ch)
{
	write(1, &ch, 1);
}

void	ft_printbase(char *base, long nbr, int len)
{
	if (nbr < len)
		ft_putchar(base[nbr]);
	else
	{
		ft_printbase(base, nbr / len, len);
		ft_putchar(base[nbr % len]);
	}
}

int		ft_baselen(char *base)
{
	int				ans;
	int				checker[256];
	unsigned char	i;
	int				idx;

	idx = 0;
	while (idx < 256)
		checker[idx++] = 0;
	ans = 0;
	while (*base)
	{
		i = (unsigned char)*base;
		if (checker[(int)i] == 1 || *base == '+' || *base == '-')
			return (0);
		checker[i]++;
		base++;
		ans++;
	}
	return (ans);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int		len;
	long	cnbr;

	cnbr = (long)nbr;
	len = ft_baselen(base);
	if (len == 0 || len == 1)
		return ;
	if (cnbr < 0)
	{
		write(1, "-", 1);
		cnbr *= -1;
	}
	ft_printbase(base, cnbr, len);
}
