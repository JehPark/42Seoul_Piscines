/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jehpark <jehpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 14:33:33 by jehpark           #+#    #+#             */
/*   Updated: 2021/03/27 17:03:20 by jehpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		islastnumber(int *digits, int n)
{
	int	index;
	int	num;

	index = n - 1;
	num = 0;
	while (index > -1)
	{
		if (digits[index--] != 9 - num)
		{
			return (1);
		}
		num++;
	}
	return (0);
}

void	ft_putchar(int *ch, int n)
{
	int		idx;
	char	temp;

	idx = 0;
	while (idx < n)
	{
		temp = '0' + ch[idx];
		write(1, &temp, 1);
		idx++;
	}
}

void	ft_init(int *digits, int n)
{
	int idx;
	int num;

	idx = 0;
	num = 0;
	while (idx < n)
	{
		digits[idx] = num;
		idx++;
		num++;
	}
}

void	ft_checker(int *digits, int n)
{
	int num;
	int idx;

	num = 0;
	idx = n - 1;
	while (digits[idx] == 9 - num)
	{
		num++;
		idx--;
	}
	digits[idx]++;
	while (idx < n - 1)
	{
		digits[idx + 1] = digits[idx] + 1;
		idx++;
	}
}

void	ft_print_combn(int n)
{
	int digits[n];
	int index;
	int num;

	index = 0;
	num = 0;
	ft_init(digits, n);
	ft_putchar(digits, n);
	while (islastnumber(digits, n))
	{
		write(1, &",", 1);
		write(1, &" ", 1);
		if (digits[n - 1] == 9)
		{
			ft_checker(digits, n);
		}
		else
			digits[n - 1]++;
		ft_putchar(digits, n);
	}
}
