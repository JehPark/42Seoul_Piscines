/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jehpark <jehpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 14:10:46 by jehpark           #+#    #+#             */
/*   Updated: 2021/04/03 14:24:56 by jehpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(char *str)
{
	char temp;

	while (*str)
	{
		temp = *str;
		write(1, &temp, 1);
		str++;
	}
}

int		main(int argc, char **argv)
{
	argc--;
	while (argc != 0)
	{
		ft_putstr(argv[argc]);
		write(1, "\n", 1);
		argc--;
	}
	return (0);
}
