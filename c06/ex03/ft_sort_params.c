/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jehpark <jehpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 15:23:45 by jehpark           #+#    #+#             */
/*   Updated: 2021/04/05 15:56:50 by jehpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_strcmp(char *s1, char *s2)
{
	while (*s1 && *s2)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

void	ft_sort(char **strs, int size)
{
	int		i;
	int		j;
	char	*temp;

	j = 0;
	while (j < size)
	{
		i = 0;
		while (i < size)
		{
			if (ft_strcmp(strs[i], strs[j]) > 0)
			{
				temp = strs[i];
				strs[i] = strs[j];
				strs[j] = temp;
			}
			i++;
		}
		j++;
	}
}

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
	argv++;
	argc--;
	ft_sort(argv, argc);
	while (*argv)
	{
		ft_putstr(*argv);
		write(1, "\n", 1);
		argv++;
	}
}
