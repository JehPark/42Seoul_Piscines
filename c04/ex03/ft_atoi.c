/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jehpark <jehpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 09:58:53 by jehpark           #+#    #+#             */
/*   Updated: 2021/04/05 09:31:16 by jehpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int			ft_isspace(char ch)
{
	if (ch == '\f' || ch == '\v' || ch == '\n')
		return (1);
	else if (ch == '\r' || ch == '\t' || ch == ' ')
		return (1);
	return (0);
}

long long	ft_change(char *str)
{
	int			len;
	int			pow;
	long long	ans;

	ans = 0;
	len = 0;
	pow = 1;
	while (str[len] >= '0' && str[len] <= '9')
		len++;
	len--;
	while (len + 1)
	{
		ans += (str[len] - '0') * pow;
		pow *= 10;
		len--;
	}
	return (ans);
}

int			ft_atoi(char *str)
{
	int		minus_count;
	int		flag;

	minus_count = 0;
	while (ft_isspace(*str))
		str++;
	while (*str < '0' || *str > '9')
	{
		if (*str == '-')
		{
			minus_count++;
			str++;
		}
		else if (*str == '+')
			str++;
		else
			return (0);
	}
	flag = minus_count % 2 == 1 ? 1 : 0;
	return ((int)(flag == 1 ? ft_change(str) * -1 : ft_change(str)));
}
