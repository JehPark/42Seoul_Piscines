/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jehpark <jehpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 20:26:53 by jehpark           #+#    #+#             */
/*   Updated: 2021/04/14 10:59:07 by jehpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int	i;
	int c;

	if (length < 2)
		return (1);
	i = 0;
	while (i < length - 1)
	{
		c = (*f)(tab[i], tab[i + 1]);
		i++;
		if (c == 0)
			continue ;
		break ;
	}
	c = c < 0 ? 1 : -1;
	while (i < length - 1)
	{
		if (c == 1 ? !((*f)(tab[i], tab[i + 1]) <= 0) :
				!((*f)(tab[i], tab[i + 1]) >= 0))
			return (0);
		i++;
	}
	return (1);
}
