/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jehpark <jehpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 11:57:01 by jehpark           #+#    #+#             */
/*   Updated: 2021/03/28 09:45:07 by jehpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char *ch)
{
	int		idx;
	char	temp;

	idx = 0;
	while (idx < 2)
	{
		temp = ch[idx++];
		write(1, &temp, 1);
	}
}

void	ft_print_comb2(void)
{
	int		i;
	int		j;
	char	fnum[2];
	char	snum[2];

	i = 0;
	j = 0;
	while (i <= 99)
	{
		fnum[0] = (i / 10) + '0';
		j = i + 1;
		fnum[1] = (i++ % 10) + '0';
		while (j <= 99)
		{
			snum[0] = (j / 10) + '0';
			snum[1] = (j++ % 10) + '0';
			ft_putchar(fnum);
			write(1, &" ", 1);
			ft_putchar(snum);
			if (fnum[0] == '9' && fnum[1] == '8')
				break ;
			write(1, &",", 1);
			write(1, &" ", 1);
		}
	}
}
