/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jehpark <jehpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 19:58:56 by jehpark           #+#    #+#             */
/*   Updated: 2021/04/03 13:47:05 by jehpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(unsigned char ch)
{
	write(1, &ch, 1);
}

void	ft_put_addr(void *addr)
{
	long long		np;
	int				i;
	unsigned char	ch[16];

	np = (long long)addr;
	i = 0;
	while (np > 0)
	{
		ch[i] = (np % 16) >= 10 ? (np % 16) - 10 + 'a' : (np % 16) + '0';
		np /= 16;
		i++;
	}
	while (i < 16)
	{
		ch[i] = '0';
		i++;
	}
	while (i >= 0)
	{
		i--;
		ft_putchar(ch[i]);
	}
	write(1, &": ", 2);
}

void	ft_puthex(unsigned char *addr, int print_size)
{
	int				i;
	char			fhex;
	char			shex;
	unsigned char	*cp;
	char			temp;

	i = 0;
	cp = (unsigned char *)addr;
	while (i < print_size)
	{
		temp = cp[i] / 16;
		fhex = temp >= 10 ? temp - 10 + 'a' : temp + '0';
		temp = cp[i] % 16;
		shex = temp >= 10 ? temp - 10 + 'a' : temp + '0';
		ft_putchar(fhex);
		ft_putchar(shex);
		i++;
		if (i % 2 == 0)
			write(1, &" ", 1);
	}
}

void	ft_printstr(void *addr, int print_size)
{
	int				i;
	unsigned char	*char_a;

	if (print_size < 16)
	{
		if (print_size % 2 == 1)
			write(1, " ", 1);
		i = 0;
		while (i++ < 16 - print_size)
		{
			write(1, "  ", 2);
			if (i % 2 == 0)
				write(1, " ", 1);
		}
	}
	i = 0;
	char_a = (unsigned char *)addr;
	while (i < print_size)
	{
		if (char_a[i] < 32 || char_a[i] >= 127)
			ft_putchar('.');
		else
			ft_putchar(char_a[i]);
		i++;
	}
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	int				off;
	unsigned char	*ptr;

	off = 0;
	ptr = (unsigned char *)addr;
	while (size > 0)
	{
		ft_put_addr(ptr + off);
		if (size >= 16)
		{
			ft_puthex(ptr + off, 16);
			ft_printstr(ptr + off, 16);
			size -= 16;
		}
		else
		{
			ft_puthex(ptr + off, size);
			ft_printstr(ptr + off, size);
			size = 0;
		}
		write(1, &"\n", 1);
		off += 16;
	}
	return (addr);
}
