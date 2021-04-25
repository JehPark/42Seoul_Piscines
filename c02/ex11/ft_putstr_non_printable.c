/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jehpark <jehpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 18:54:23 by jehpark           #+#    #+#             */
/*   Updated: 2021/04/01 09:36:07 by jehpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char ch)
{
	write(1, &ch, 1);
}

void	ft_print_non(char np)
{
	char			fhex;
	char			shex;
	unsigned char	cp;

	cp = (unsigned char)np;
	ft_putchar('\\');
	fhex = (cp / 16) >= 10 ? (cp / 16) - 10 + 'a' : (cp / 16) + '0';
	shex = (cp % 16) >= 10 ? (cp % 16) - 10 + 'a' : (cp % 16) + '0';
	ft_putchar(fhex);
	ft_putchar(shex);
}

void	ft_putstr_non_printable(char *str)
{
	int idx;

	idx = 0;
	while (str[idx] != '\0')
	{
		if (str[idx] >= 32 && str[idx] < 127)
			ft_putchar(str[idx]);
		else
			ft_print_non(str[idx]);
		idx++;
	}
}
