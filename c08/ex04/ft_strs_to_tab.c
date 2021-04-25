/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jehpark <jehpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 16:47:35 by jehpark           #+#    #+#             */
/*   Updated: 2021/04/06 19:26:52 by jehpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_stock_str.h"

int					ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (*str)
	{
		len++;
		str++;
	}
	return (len);
}

char				*ft_strcpy(char *dest, char *src)
{
	char *tmp;

	tmp = dest;
	while (*src)
		*tmp++ = *src++;
	*tmp = '\0';
	return (dest);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	struct s_stock_str	*ans;
	int					idx;
	int					size;

	ans = (struct s_stock_str *)malloc(sizeof(struct s_stock_str) * (ac + 1));
	idx = 0;
	while (idx < ac)
	{
		size = ft_strlen(av[idx]);
		ans[idx].size = size;
		ans[idx].str = av[idx];
		ans[idx].copy = (char *)malloc(size * sizeof(char) + 1);
		ft_strcpy(ans[idx].copy, av[idx]);
		idx++;
	}
	ans[idx] = (struct s_stock_str){0, 0, 0};
	return (ans);
}
