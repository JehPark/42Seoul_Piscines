/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jehpark <jehpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 10:32:09 by jehpark           #+#    #+#             */
/*   Updated: 2021/03/31 16:08:30 by jehpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char *str)
{
	int		idx;
	char	ch;

	idx = 0;
	while (idx < 3)
	{
		ch = str[idx];
		write(1, &ch, 1);
		idx++;
	}
}

void	ft_print_comb(void)
{
	char str[3];

	str[0] = '0';
	while (str[0] <= '7')
	{
		str[1] = str[0] + 1;
		while (str[1] <= '8')
		{
			str[2] = str[1] + 1;
			while (str[2] <= '9')
			{
				ft_putchar(str);
				if (str[0] == '7' && str[1] == '8' && str[2] == '9')
					break ;
				write(1, &",", 1);
				write(1, &" ", 1);
				str[2]++;
			}
			str[1]++;
		}
		str[0]++;
	}
}
