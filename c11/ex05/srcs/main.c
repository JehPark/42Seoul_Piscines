/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jehpark <jehpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 11:44:00 by jehpark           #+#    #+#             */
/*   Updated: 2021/04/14 17:20:24 by jehpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int			ft_atoi(char *nbr)
{
	long	ans;
	long	flag;

	ans = 0;
	flag = 1;
	while (*nbr == '-' || *nbr == '+')
	{
		if (*nbr == '-')
			flag *= -1;
		nbr++;
	}
	while (*nbr && *nbr >= '0' && *nbr <= '9')
	{
		ans *= 10;
		ans += *nbr - '0';
		nbr++;
	}
	return (int)((ans) * (flag));
}

void		ft_putnbr(int nbr)
{
	char temp;

	if (nbr == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	else if (nbr < 0)
	{
		write(1, "-", 1);
		nbr *= -1;
		ft_putnbr(nbr);
	}
	else if (nbr > 9)
	{
		ft_putnbr(nbr / 10);
		ft_putnbr(nbr % 10);
	}
	else
	{
		temp = nbr + '0';
		write(1, &temp, 1);
	}
}

void		ft_do_op(int num1, char *op, int num2)
{
	int	(*fp[5])(int, int);

	fp[0] = add;
	fp[1] = mul;
	fp[2] = div;
	fp[3] = modular;
	fp[4] = minus;
	if (*op == '+')
		ft_putnbr(fp[0](num1, num2));
	else if (*op == '*')
		ft_putnbr(fp[1](num1, num2));
	else if (*op == '/')
		ft_putnbr((fp[2](num1, num2)));
	else if (*op == '%')
		ft_putnbr(fp[3](num1, num2));
	else if (*op == '-')
		ft_putnbr(fp[4](num1, num2));
	else
		write(1, "0", 1);
}

int			main(int argc, char **argv)
{
	int a;
	int b;

	if (argc == 4)
	{
		a = ft_atoi(argv[1]);
		b = ft_atoi(argv[3]);
		if (ft_strlen(argv[2]) != 1)
			write(1, "0", 1);
		else if (b == 0 && (argv[2][0] == '%' || argv[2][0] == '/'))
		{
			if (argv[2][0] == '%')
				write(1, "Stop : modulo by zero", 21);
			else if (argv[2][0] == '/')
				write(1, "Stop : division by zero", 23);
		}
		else
			ft_do_op(a, argv[2], b);
		write(1, "\n", 1);
	}
	return (0);
}
