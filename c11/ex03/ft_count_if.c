/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_if.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jehpark <jehpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 20:18:07 by jehpark           #+#    #+#             */
/*   Updated: 2021/04/13 19:02:24 by jehpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_count_if(char **tab, int length, int (*f)(char *))
{
	int ans;
	int idx;

	ans = 0;
	idx = 0;
	if (length == 0)
		return (0);
	while (idx < length)
	{
		if ((*f)(tab[idx]) != 0)
			ans++;
		idx++;
	}
	return (ans);
}
