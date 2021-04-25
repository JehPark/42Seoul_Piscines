/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jehpark <jehpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 18:42:50 by jehpark           #+#    #+#             */
/*   Updated: 2021/04/12 10:01:55 by jehpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_isspace(char c);
int		ft_basechecker(char *base);
char	*ft_nbrchecker(char *nbr, char *base);
char	*ft_convert_base(char *nbr, char *base_from, char *base_to);

extern int	g_minus_count;

int		ft_atoi(char *nbr, char *base, int len)
{
	int	checker[256];
	int	idx;
	int	ans;

	idx = 0;
	while (idx < 256)
		checker[idx++] = -1;
	idx = 0;
	while (*base)
	{
		checker[(unsigned char)*base] = idx++;
		base++;
	}
	ans = 0;
	while (*nbr && checker[(unsigned char)*nbr] != -1)
	{
		ans *= len;
		ans += checker[(unsigned char)*nbr];
		nbr++;
	}
	return (ans);
}

int		ft_nbrlen(long long nbr, int len)
{
	int length;

	if (nbr < 0)
		nbr *= -1;
	length = 0;
	while (nbr)
	{
		length++;
		nbr /= len;
	}
	return (length);
}

int		ft_pow(int len, int pow)
{
	int ans;

	ans = 1;
	while (pow)
	{
		ans *= len;
		pow--;
	}
	return (ans);
}

char	*ft_itoa(long long nbr, char *base, int len)
{
	int		size;
	char	*ans;
	int		idx;
	int		div;

	size = ft_nbrlen(nbr, len);
	ans = (char *)malloc(size + 1 + (g_minus_count % 2 == 1 ? 1 : 0));
	idx = 0;
	div = ft_pow(len, size - 1);
	if (g_minus_count % 2 == 1)
	{
		ans[0] = '-';
		idx++;
		size++;
	}
	while (idx < size)
	{
		ans[idx++] = base[nbr / div];
		nbr = nbr % div;
		div /= len;
	}
	ans[idx] = 0;
	return (ans);
}
