/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jehpark <jehpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 17:43:37 by jehpark           #+#    #+#             */
/*   Updated: 2021/04/12 14:04:52 by jehpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_itoa(long long nbr, char *base, int len);
int		ft_atoi(char *nbr, char *base, int len);
int		ft_nbrlen(long long nbr, int len);
int		ft_pow(int len, int pow);

int		g_minus_count;

int		ft_isspace(char c)
{
	if (c == '\f' || c == '\v' || c == '\n')
		return (1);
	else if (c == '\r' || c == '\t' || c == ' ')
		return (1);
	return (0);
}

int		ft_basechecker(char *base)
{
	int	checker[256];
	int idx;
	int len;

	idx = 0;
	while (idx < 256)
		checker[idx++] = 0;
	len = 0;
	while (*base)
	{
		if (ft_isspace(*base) || *base == '+' || *base == '-')
			return (0);
		if (checker[(unsigned char)*base] == 1)
			return (0);
		checker[(unsigned char)*base] = 1;
		base++;
		len++;
	}
	return (len);
}

char	*ft_nbrchecker(char *nbr, char *base)
{
	int checker[256];
	int idx;

	while (ft_isspace(*nbr))
		nbr++;
	idx = 0;
	while (idx < 256)
		checker[idx++] = 0;
	while (*base)
		checker[(unsigned char)*base++] = 1;
	g_minus_count = 0;
	while (!checker[(unsigned char)*nbr])
	{
		if (*nbr == '+' || *nbr == '-')
		{
			if (*nbr == '-')
				g_minus_count++;
		}
		else
			return (char *)(0);
		nbr++;
	}
	return (nbr);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		bf_len;
	int		bt_len;
	char	*nr;
	int		ret;
	char	*ans;

	bf_len = ft_basechecker(base_from);
	bt_len = ft_basechecker(base_to);
	if (bf_len == 0 || bf_len == 1 || bt_len == 0 || bt_len == 1)
		return (char *)(0);
	nr = ft_nbrchecker(nbr, base_from);
	ans = (char *)malloc(2);
	ans[0] = base_to[0];
	ans[1] = '\0';
	if (nr == 0)
		return (ans);
	ret = ft_atoi(nr, base_from, bf_len);
	if (ret == 0)
		return (ans);
	ans = ft_itoa(ret, base_to, bt_len);
	return (ans);
}
